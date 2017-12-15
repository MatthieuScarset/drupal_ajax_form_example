#!/usr/bin/perl

# ************************************************************ #
#                                                              #
# Auteur : Christophe Madeja                                   #
# Date : 30/10/2013                                            #
# Description : Import d'un dump de BDD de PROD                #
# Arguments :                                                  #
#     1 - <--dl_bdd|--imp_bdd|--clean|--index|--all>           #
# ************************************************************ #

# connecter en ssh
# télécharger le fichier dans temp
# couper la connection ssh
# sauvegarde de l'ancienne BDD dans temp
# suppression de la BDD et recréation
# import de la BDD
# revert si ça ne marche pas

# scripts drush pour désactiver des modules
# scripts drush pour modifier des variables
# scripts d'update BDD
# flush des caches
# nettoyage des données personnelles
# désactivation des rules de notification
# indexation du contenu solr (très long, désactivé pour l'instant)
# génération du fichier sitemap (très long, désactivé pour l'instant)

# ---- PRAGMAS

use strict;
use warnings;
use diagnostics;
use Net::SSH2;

require "functions.pl";

# ---- VARIABLES GLOBALES

my $OPE;

my $cmd_date = "date +%Y%m%d-%H%M";
my $date = `$cmd_date`;
chomp($date);

my $USER_PROD = 'ruby';
my $IP_PROD = '94.124.134.12';
my $PWD_PROD = 'abDXYtCGv3';
my $R_PRIVATE = '/data2/sql-prod/backup/ruby-sql03-prod/daily/drupal';
my $SRC_date = `date --date='1 days ago' '+%Y-%m-%d_02h00m.%A'`;
chomp($SRC_date);
my $SRC = 'drupal_'.$SRC_date.'.sql.gz';

my $database = "drupal";
my $F_LOG;
my $R_ROOT = "/home/orangecom/ruby";
my $R_SITE = "/var/www";
my $R_BIN = $R_ROOT. "/bin";
my $R_LOG = $R_ROOT. "/log";
my $R_SAVE = $R_ROOT. "/backup";
my $R_SAVE_BDD = $R_SAVE . "/bdd";
my $F_DUMP;
my $A_DUMP;
my $apachesolr_environment = 'http://localhost:8983/solr/drupal';
my $xmlsitemap_base_url = 'http://orangepointcom.silicomp.fr';
my $comscore_url = '//tags.tiqcdn.com/utag/orange/obscare/qa/utag.js';

my $server_host_name = `hostname`;
chomp($server_host_name);


# ---- FONCTIONS

# ********************
# Nom : display_syntax
# Description : definition de la syntaxe
# Argument : -
# ********************

sub display_syntax() {
    print "ERREUR - Syntaxe : import-bdd-prod <--dl_bdd|--imp_bdd|--clean|--index|--all>\n";
    exit;
}

# ********************
# Nom : bdd_save
# Description : sauvegarde de la BDD de l'environnement
# Argument : -
# ********************
sub bdd_save(){
	$F_DUMP = "dump_ruby_$date.sql";
    $A_DUMP = "dump_ruby_$date.sql.gz";
    my $cmd_dump = "";
    
	print_log("INFO", "Dump de la BDD", "BOTH");
	if ($server_host_name eq 'recetteclient') {
		$cmd_dump = "mysqldump -uroot -pOrange000 -hruby-bdd --database $database > /home/orangecom/ruby/backup/ruby/$A_DUMP";
	}
	else{
		$cmd_dump = "mysqldump -uroot -pSilicomp69 --database $database > /home/orangecom/ruby/backup/ruby/$A_DUMP";
	}
    print_log("DEBUG", $cmd_dump, "BOTH");
    my $retour_dump = `$cmd_dump`;
}

# ********************
# Nom : bdd_import
# Description : import de la BDD de l'environnement
# Argument : chemin vers le fichier à importer
# ********************
sub bdd_import {
	my $FILE_TO_IMPORT = shift;
	if (-e $FILE_TO_IMPORT) {
	
		if ($FILE_TO_IMPORT =~ /\.sql.gz$/i) {
			print_log("INFO", "gunzip de l'archive $FILE_TO_IMPORT", "BOTH");
			my $cmd_gunzip = "gunzip -f $FILE_TO_IMPORT\r";
			print_log("DEBUG", $cmd_gunzip, "BOTH");
    		my $retour_gunzip = `$cmd_gunzip`;
		}
		else{
			print_log("ERROR", "no file $FILE_TO_IMPORT to import", "BOTH");
		}
	}
	else{
		print_log("ERROR", "no file $FILE_TO_IMPORT to import", "BOTH");
	}
	
	$FILE_TO_IMPORT =~ s/\.gz//;
	    
	if (-e $FILE_TO_IMPORT) {
		if ($FILE_TO_IMPORT =~ /\.sql$/i) {    		
			print_log("INFO", "Suppression de la BDD existante", "BOTH");
			my $cmd_rm = "";
			if ($server_host_name eq 'recetteclient') {
    			$cmd_rm = "mysql -uroot -pOrange000 -hruby-bdd --debug-info -D $database -e 'DROP DATABASE $database;CREATE DATABASE $database DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;'\r";
    		}
    		else{
    			$cmd_rm = "mysql -uroot -pSilicomp69 --debug-info -D $database -e 'DROP DATABASE $database;CREATE DATABASE $database DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;'\r";
    		}
   			print_log("DEBUG", $cmd_rm, "BOTH");
    		my $retour_rm = `$cmd_rm`;
    		
    		print_log("INFO", "Import du nouveau dump", "BOTH");
    		my $cmd_imp = "";
    		if ($server_host_name eq 'recetteclient') {
    			$cmd_imp = "mysql -uroot -pOrange000 -hruby-bdd --debug-info -D $database < $FILE_TO_IMPORT";
    		}
    		else{
    			$cmd_imp = "mysql -uroot -pSilicomp69 --debug-info -D $database < $FILE_TO_IMPORT";
    		}
   			print_log("DEBUG", $cmd_imp, "BOTH");
    		my $retour_imp = `$cmd_imp`;
		}
		else{
			print_log("ERROR", "no file $FILE_TO_IMPORT to import", "BOTH");
		}
	}
	else{
		print_log("ERROR", "no file $FILE_TO_IMPORT to import", "BOTH");
	}
}

# ********************
# Nom : drupal_clean_procedures
# Description : lance les procédures drupal pour affiner l'installation
# Argument : -
# ********************
sub drupal_clean_procedures() {
	my $database_instruction = "mysql -uroot -pSilicomp69 --debug-info -D $database -e";
	my $R_CONF = "/var/www/conf";
	my $F_CONF = $R_CONF . "/drush.conf";
	
	my $retour_cd = `cd $R_SITE;`;
	
	print_log("INFO", "server name : $server_host_name", "BOTH");
	
	if ($server_host_name eq 'orangepointcom') {
		$apachesolr_environment = 'http://localhost:8983/solr/drupal';
		$xmlsitemap_base_url = 'http://orangepointcom.silicomp.fr';
	}
	elsif ($server_host_name eq 'recetteruby') {
		$apachesolr_environment = 'http://localhost:8983/solr/drupal';
		$xmlsitemap_base_url = 'http://recetteruby.silicomp.fr';
	}
	elsif ($server_host_name eq 'recetteclient') {
		$apachesolr_environment = 'http://192.168.131.2:8080/solr/drupal';
		$xmlsitemap_base_url = 'http://recetteclient.silicomp.fr';
		
		$database_instruction = "mysql -uroot -pOrange000 -hruby-bdd --debug-info -D $database -e"
	}
	
	my $retour_solr = `$database_instruction 'UPDATE apachesolr_environment SET url = "$apachesolr_environment" WHERE url != "$apachesolr_environment"';\r`;
	print_log("INFO", "Module apachesolr paramétré", "BOTH");
	my $retour_xml = `drush --root=$R_SITE vset --yes xmlsitemap_base_url '$xmlsitemap_base_url'\n`;
	print_log("INFO", "Module xmlsitemap paramétré", "BOTH");
	
	my $retour_memcache = `drush --root=$R_SITE pm-disable -y memcache memcache_admin\n`;
	print_log("INFO", "Module memcache désactivé", "BOTH");
	
	# parcours du fichier de conf
	if ( -e $F_CONF ) {
        print_log("INFO", "Parcours du  fichier $F_CONF", "SCREEN");
        open(DRUSH, "<", $F_CONF) or die "ERREUR : impossible d'ouvrir $F_CONF : $!";
        while (my $line = <DRUSH>) {
            my $cmd_drush = "drush --root=/var/www/ -y  $line";
            print_log("DEBUG", "$cmd_drush", "SCREEN");
            my $retour_cmd_drush = `$cmd_drush`;
        }
        close(DRUSH);
	} else {
		print_log("ERREUR", "Le fichier $F_CONF n'existe pas", "SCREEN");
		exit
	}
	
	# nettoyage des données personnelles
	my $retour_comment1 = `$database_instruction 'UPDATE comment SET hostname = "127.0.0.1" WHERE hostname != "127.0.0.1"';\r`;
	my $retour_comment2 = `$database_instruction 'UPDATE comment SET mail = "ruby.equipe\@orange.com" WHERE mail != "ruby.equipe\@orange.com"';\r`;
	my $retour_comment3 = `$database_instruction 'UPDATE comment SET homepage = "http://www.orange-business.com" WHERE homepage != "http://www.orange-business.com"';\r`;
	print_log("INFO", "Table 'comment' nettoyée", "BOTH");
	
	my $retour_field_body1 = `$database_instruction 'UPDATE field_data_comment_body SET comment_body_value = "my comment" WHERE comment_body_value != "my comment"';\r`;
	my $retour_field_body2 = `$database_instruction 'UPDATE field_revision_comment_body SET comment_body_value = "my comment" WHERE comment_body_value != "my comment"';\r`;
	print_log("INFO", "Table 'field_data_comment_body' nettoyée", "BOTH");
	print_log("INFO", "Table 'field_revision_comment_body' nettoyée", "BOTH");
	
	my $retour_field_email1 = `$database_instruction 'UPDATE field_data_field_txt_email SET field_txt_email_email = NULL WHERE (field_txt_email_email != NULL OR field_txt_email_email != "") AND entity_type = "comment"';\r`;
	my $retour_field_email2 = `$database_instruction 'UPDATE field_revision_field_txt_email SET field_txt_email_email = NULL WHERE (field_txt_email_email != NULL OR field_txt_email_email != "") AND entity_type = "comment"';\r`;
	print_log("INFO", "Table 'field_data_field_txt_email' nettoyée", "BOTH");
	print_log("INFO", "Table 'field_revision_field_txt_email' nettoyée", "BOTH");
	
	my $retour_field_link1 = `$database_instruction 'UPDATE field_data_field_link SET field_link_url = "website-URL" WHERE field_link_url != "website-URL" AND entity_type = "comment"';\r`;
	my $retour_field_link2 = `$database_instruction 'UPDATE field_revision_field_link SET field_link_url = "website-URL" WHERE field_link_url != "website-URL" AND entity_type = "comment"';\r`;
	print_log("INFO", "Table 'field_data_field_link' nettoyée", "BOTH");
	print_log("INFO", "Table 'field_revision_field_link' nettoyée", "BOTH");
	
	my $retour_field_voting = `$database_instruction 'UPDATE votingapi_vote SET vote_source = "127.0.0.1" WHERE vote_source != "127.0.0.1"';\r`;
	print_log("INFO", "Table 'votingapi_vote' nettoyée", "BOTH");
	
	my $retour_field_webform1 = `$database_instruction 'UPDATE webform_submissions SET remote_addr = "127.0.0.1" WHERE remote_addr != "127.0.0.1"';\r`;
	my $retour_field_webform2 = `$database_instruction 'UPDATE webform_submitted_data SET data = "my data" WHERE data != "my data" AND (cid != 11 OR (nid != 193 AND nid != 5544)) AND (cid != 12 OR (nid != 193 AND nid != 5544))';\r`;
	print_log("INFO", "Table 'webform_submissions' nettoyée", "BOTH");
	print_log("INFO", "Table 'webform_submitted_data' nettoyée", "BOTH");
	
	# désactivation des rules de notification
	my $retour_rules1 = `$database_instruction 'UPDATE rules_config SET active = 0 WHERE name = "rules_send_email_to_manager_when_a_comment_is_posted"';\r`;
	my $retour_rules2 = `$database_instruction 'UPDATE rules_config SET active = 0 WHERE name = "rules_send_email_to_commentator_when_a_comment_is_approved"';\r`;
	my $retour_rules3 = `$database_instruction 'UPDATE rules_config SET active = 0 WHERE name = "rules_send_mail_when_post_is_published"';\r`;
	my $retour_rules4 = `$database_instruction 'UPDATE rules_config SET active = 0 WHERE name = "rules_send_mail_to_blog_manager_custom"';\r`;
	my $retour_rules5 = `$database_instruction 'UPDATE rules_config SET active = 0 WHERE name = "rules_send_mail_when_post_is_scheduled_to_publish"';\r`;
	print_log("INFO", "'rules' notifications désactivées", "BOTH");
	
	#changement url comscore
  	my $retour_comscore = `drush --root=$R_SITE vset --yes comscore_url '$comscore_url'\n`;
  	print_log("INFO", "URL Comscore changée", "BOTH");
  
  	#creation des utilisateurs selenium
  	my $retour_user1 = `drush --root=$R_SITE user-create SeleniumAdmin --password="nJ52\!zQ47" --mail="sqdrfvsdqgsd\@qsgsdqg.fr" \n`;
  	print_log("INFO", "user SeleniumAdmin created", "BOTH");
  	my $retour_user2 = `drush --root=$R_SITE user-create SeleniumBO --password="nJ52\!zQ47" --mail="qsfvqsfef\@qsgfsqdg.fr" \n`;
  	print_log("INFO", "user SeleniumBO created", "BOTH");
  	my $retour_user_role1 = `drush --root=$R_SITE user-add-role "functional admin" SeleniumAdmin \n`;
  	my $retour_user_role2 = `drush --root=$R_SITE user-add-role "functional head" SeleniumAdmin,SeleniumBO \n`;
  	print_log("INFO", "role assigned", "BOTH");
  	
  	my $retour_user_pwd_force_change1 = `$database_instruction 'UPDATE password_policy_force_change SET force_change= 0 WHERE uid = (SELECT u.uid FROM users u WHERE u.name = "SeleniumAdmin" LIMIT 0, 1)';\r`;
  	my $retour_user_pwd_force_change2 = `$database_instruction 'UPDATE password_policy_force_change SET force_change= 0 WHERE uid = (SELECT u.uid FROM users u WHERE u.name = "SeleniumBO" LIMIT 0, 1)';\r`;
	print_log("INFO", "password policy change", "BOTH");
	
	my $retour_cc = `drush --root=$R_SITE cc 'all'\n`;
}

# ********************
# Nom : drupal_index_procedures
# Description : lance les procédures d'indexation de contenu
# Argument : -
# ********************
sub drupal_index_procedures() {
	# indexation solr
	#my $retour_solr_delete_index = `drush --root=$R_SITE solr-delete-index\n`;
	#my $retour_solr_mark_all = `drush --root=$R_SITE solr-mark-all\n`;
	#my $retour_solr_index = `drush --root=$R_SITE solr-index\n`;
	#print_log("INFO", "indexation solr", "BOTH");
	
	# génération du sitemap
	#my $retour_sitemap_index = `drush --root=$R_SITE xmlsitemap-rebuild\n`;
	#print_log("INFO", "indexation xmlsitemap", "BOTH");
}

# ---- PROGRAMME PRINCIPAL

# Verifications des arguments
my $nb_arg = $#ARGV + 1;
if ($nb_arg < 1) {
    display_syntax();
} else {
    $OPE = $ARGV[0];
    if ($OPE ne "--dl_bdd"
    	&& $OPE ne "--imp_bdd"
        && $OPE ne "--clean"
        && $OPE ne "--index"
        && $OPE ne "--all") {
        display_syntax();
    }
    
	# Initialisation du LOG
	$F_LOG = $R_LOG."/".$date."_livraison.log";
	open(LOGFILE, ">", $F_LOG) or die "ERREUR : impossible d'ouvrir $F_LOG : $!";
	
	
	if ($OPE eq "--dl_bdd") {
		my $ssh2 = Net::SSH2->new(trace => -1);
		$ssh2->connect($IP_PROD) or die $!;
		
		if ($ssh2->auth(username => $USER_PROD, password => $PWD_PROD)) {
		    print_log("INFO", "Connexion SSH au serveur de PROD", "BOTH");
		    print_log("INFO", "Téléchargement du fichier $SRC", "BOTH");

            if ($ssh2->scp_get($R_PRIVATE."/".$SRC, '/tmp/'.$SRC)){
                print_log("INFO", "Fichier SQL téléchargé", "BOTH");
                print_log("INFO", "Connexion SSH fermée", "BOTH");
                $ssh2->disconnect();
            }
            else{
                die("Can't download the file $SRC");
            }
		}
		else{
		    die("Can't authenticate");
		}
	}
	elsif ($OPE eq "--imp_bdd") {
		bdd_save();
		bdd_import('/tmp/'.$SRC);
	}
	elsif ($OPE eq "--clean") {
		drupal_clean_procedures();
	}
	elsif ($OPE eq "--index") {
		drupal_index_procedures();
	}
	elsif ($OPE eq "--all") {
		my $ssh2 = Net::SSH2->new();
		$ssh2->connect($IP_PROD) or die $!;
		
		if ($ssh2->auth(username => $USER_PROD, password => $PWD_PROD)) {
		    print_log("INFO", "Connexion SSH au serveur de PROD", "BOTH");
		    print_log("INFO", "Téléchargement du fichier $SRC", "BOTH");

            if ($ssh2->scp_get($R_PRIVATE."/".$SRC, '/tmp/'.$SRC)){
                print_log("INFO", "Fichier SQL téléchargé", "BOTH");
                print_log("INFO", "Connexion SSH fermée", "BOTH");
                $ssh2->disconnect();

                bdd_save();
                bdd_import('/tmp/'.$SRC);
                drupal_clean_procedures();
                drupal_index_procedures();
            }
            else{
                die("Can't download the file $SRC");
            }
		}
		else{
		    die("Can't authenticate");
		}
	}
}
close(LOGFILE);
exit;
