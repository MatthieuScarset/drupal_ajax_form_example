#!/usr/bin/perl

# ********************************************* #
#                                               #
# Auteur : Camille MANIEZ                       #
# Date : 05/05/2014                             #
# Description : Livraison IPP en interne        #
# Arguments :                                   #
#     1 - <archive_version>                     #
#                                               #
# ********************************************* #

# ---- PRAGMAS

use strict;
use warnings;
use diagnostics;

require "functions.pl";

# VARIABLES GLOBALES
my $R_LIVRABLE          = "/var/livrable";
my $R_LIVRABLE_ARCHIVES = $R_LIVRABLE . "/archives";
my $F_LIVRABLE_PROD;
my $F_LIVRABLE;

my $R_BIN     		= "/home/orangecom/ruby/bin";
my $R_WWW     		= "/var/www";
my $R_WWW_LIVRABLE 	= $R_LIVRABLE . "/common";
		
my $R_CONF = "/var/www/conf";
my $R_CONF_LIVRABLE = $R_LIVRABLE . "/env/production/conf";
my $F_CONF = $R_CONF . "/drush.conf";
my $F_CONF_LIVRABLE = $R_CONF_LIVRABLE . "/drush.conf";

my $database = "drupal";
my $apachesolr_environment = 'http://localhost:8983/solr/drupal';
my $xmlsitemap_base_url = 'http://orangepointcom.silicomp.fr';

my $server_host_name = `hostname`;
chomp($server_host_name);


# ---- FONCTIONS

# ********************
# Nom : display_syntax
# Description : decrire la syntaxe attendue du script
# Argument : -
# ********************

sub display_syntax() {
	print_log( "HELP", "Syntaxe : livraison-ipp <archive_version>", "SCREEN" );
	exit;
}

# ---- PROGRAMME PRINCIPAL
print_log( "INFO", "Début du script", "SCREEN" );

# Verifications des arguments
my $nb_arg = $#ARGV + 1;
if ( $nb_arg < 1 ) {
	display_syntax();
} else {
	print_log( "INFO", "Téléchargement de la BDD de prod", "SCREEN" );
	my $cmd_dl_bdd = "$R_BIN/import_bdd.pl --dl_bdd";
	print_log( "CMD", "$cmd_dl_bdd", "SCREEN" );
	my $retour_dl_bdd = `$cmd_dl_bdd`;
	print_log( "DEBUG", "RETOUR : $retour_dl_bdd", "SCREEN" );

	print_log( "INFO", "Import de la BDD de prod", "SCREEN" );
	my $cmd_imp_bdd = "$R_BIN/import_bdd.pl --imp_bdd";
	print_log( "CMD", "$cmd_imp_bdd", "SCREEN" );
	my $retour_imp_bdd = `$cmd_imp_bdd`;
	print_log( "DEBUG", "RETOUR : $retour_imp_bdd", "SCREEN" );

	print_log( "INFO", "Recopie des fichiers de prod", "SCREEN" );
	my $version = $ARGV[0];
	my $old_version;

	my @matches = ( $version =~ m/([0-1]{1}\.[0-9]{1}\.)([0-9]{2})/ );
	if ( @matches)  {
		my $base = $matches[0];
		$old_version = $matches[1];
		$old_version = $old_version - 1;
		if ( $old_version =~ /^[0-9]{1}$/ ) { $old_version = '0' . $old_version; }
		$old_version = $base . $old_version;

		print_log( "DEBUG", "OLD VERSION : $old_version", "SCREEN" );
	}
	$F_LIVRABLE_PROD = "obs-ruby-webapp-V" . $old_version . ".tgz";

	if ( -e $R_LIVRABLE_ARCHIVES . "/" . $F_LIVRABLE_PROD ) {
		my $cmd_cp_archive =
		  "cp -p $R_LIVRABLE_ARCHIVES/$F_LIVRABLE_PROD $R_LIVRABLE";
		print_log( "CMD", "$cmd_cp_archive", "SCREEN" );
		my $retour_cp_archive = `$cmd_cp_archive`;
		print_log( "DEBUG", "RETOUR : $retour_cp_archive", "SCREEN" );

		my $cmd_untar_archive = "cd $R_WWW_LIVRABLE; rm -rf sites includes modules profiles scripts themes misc *.php *.txt web.config; cd $R_LIVRABLE; tar xvfz $F_LIVRABLE_PROD;";
		print_log( "CMD", "$cmd_untar_archive", "SCREEN" );
		my $retour_untar_archive = `$cmd_untar_archive `;
		print_log( "DEBUG", "RETOUR : $retour_untar_archive", "SCREEN" );

		print_log( "INFO", "Suppression anciens fichiers", "SCREEN" );
		my $cmd_rm_sites = "cd $R_WWW; rm -rf sites includes modules profiles scripts themes misc *.php *.txt web.config";
		print_log( "DEBUG", "$cmd_rm_sites", "SCREEN" );
		my $retour_rm_sites = `$cmd_rm_sites `;
		print_log( "DEBUG", "RETOUR : $retour_rm_sites", "SCREEN" );

		print_log( "INFO", "Recopie nouveaux fichiers", "SCREEN" );
		my $cmd_cp_files  = "cd $R_WWW_LIVRABLE; cp -rpf sites includes modules profiles scripts themes misc *.php *.txt web.config $R_WWW";
		print_log( "CMD", "$cmd_cp_files", "SCREEN" );
		my $retour_cp_files = `$cmd_cp_files `;
		print_log( "DEBUG", "RETOUR : $retour_cp_files", "SCREEN" );

		my $cmd_mv_archive = "cd $R_LIVRABLE; mv -f $F_LIVRABLE_PROD $R_LIVRABLE_ARCHIVES";
		print_log( "CMD", "$cmd_mv_archive", "SCREEN" );
		my $retour_mv_archive = `$cmd_mv_archive `;
		print_log( "DEBUG", "RETOUR : $retour_mv_archive", "SCREEN" );
	} else {
		print_log( "ERREUR", "Le fichier $F_LIVRABLE_PROD n'existe pas",
			"SCREEN" );
		exit;
	}

	print_log( "INFO", "Variables", "SCREEN" );
	my $cmd_drush =
	  "drush -y --root=/var/www vset --always-set maintenance_mode 1";
	print_log( "CMD", "$cmd_drush", "SCREEN" );
	my $retour_drush = `$cmd_drush `;
	print_log( "DEBUG", "RETOUR : $retour_drush", "SCREEN" );

	$cmd_drush =
"drush -y --root=/var/www vset --always-set obs_maintenance_block_users 1";
	print_log( "CMD", "$cmd_drush", "SCREEN" );
	$retour_drush = `$cmd_drush `;
	print_log( "DEBUG", "RETOUR : $retour_drush", "SCREEN" );
	
	my $database_instruction = "mysql -uroot -pSilicomp69 --debug-info -D $database -e";
	
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
	my $retour_xml = `drush --root=$R_WWW vset --yes xmlsitemap_base_url '$xmlsitemap_base_url'\n`;
	print_log("INFO", "Module xmlsitemap paramétré", "BOTH");

	print_log( "INFO", "Redémarrage Apache", "SCREEN" );
	my $cmd_apache = "echo Silicomp69 | sudo -S service apache2 restart";
	print_log( "CMD", "$cmd_apache", "SCREEN" );
	my $retour_apache = `$cmd_apache`;
	print_log( "DEBUG", "RETOUR : $retour_apache", "SCREEN" );

	print_log( "INFO", "Décompression archive", "SCREEN" );
	$F_LIVRABLE = "obs-ruby-webapp-V" . $ARGV[0] . ".tgz";
	if ( -e $R_LIVRABLE . "/" . $F_LIVRABLE ) {
		my $cmd_untar_archive = "cd $R_WWW_LIVRABLE; rm -rf sites includes modules profiles scripts themes misc *.php *.txt web.config; cd $R_LIVRABLE;tar xvfz $F_LIVRABLE;";
		print_log( "CMD", "$cmd_untar_archive", "SCREEN" );
		my $retour_untar_archive = `$cmd_untar_archive `;
		print_log( "DEBUG", "RETOUR : $retour_untar_archive", "SCREEN" );
	} else {
		print_log( "ERREUR", "Le fichier $F_LIVRABLE n'existe pas", "SCREEN" );
		exit;
	}

	print_log( "INFO", "Suppression anciens fichiers", "SCREEN" );
	my $cmd_rm_sites = "cd $R_WWW; rm -rf sites includes modules profiles scripts themes misc *.php *.txt web.config";
	print_log( "DEBUG", "$cmd_rm_sites", "SCREEN" );
	my $retour_rm_sites = `$cmd_rm_sites `;
	print_log( "DEBUG", "RETOUR : $retour_rm_sites", "SCREEN" );

	print_log( "INFO", "Recopie nouveaux fichiers", "SCREEN" );
	my $cmd_cp_files  = "cd $R_WWW_LIVRABLE; cp -rpf sites includes modules profiles scripts themes misc *.php *.txt web.config $R_WWW";
	print_log( "CMD", "$cmd_cp_files", "SCREEN" );
	my $retour_cp_files = `$cmd_cp_files `;
	print_log( "DEBUG", "RETOUR : $retour_cp_files", "SCREEN" );
	
	print_log( "INFO", "Recopie du fichier drush.conf", "SCREEN" );
	my $cmd_cp_drush  = "cp -f $F_CONF_LIVRABLE $R_CONF";
	print_log( "CMD", "$cmd_cp_drush", "SCREEN" );
	my $retour_cp_drush = `$cmd_cp_drush `;
	print_log( "DEBUG", "RETOUR : $retour_cp_drush", "SCREEN" );

	if ( -e $F_CONF ) {
		print_log( "INFO", "Parcours du  fichier $F_CONF", "SCREEN" );
		open( DRUSH, "<", $F_CONF )
		  or die "ERREUR : impossible d'ouvrir $F_CONF : $!";
		while ( my $line = <DRUSH> ) {
			$cmd_drush = "drush --root=/var/www/ -y  $line";
			print_log( "CMD", "$cmd_drush", "SCREEN" );
			$retour_drush = `$cmd_drush`;
			print_log( "DEBUG", "RETOUR : $retour_drush", "SCREEN" );

		}
		close(DRUSH);
	} else {
		print_log( "ERREUR", "Le fichier $F_CONF n'existe pas", "SCREEN" );
		exit;
	}

	print_log( "INFO", "Désactivation de modules", "SCREEN" );
	my $cmd_memcache =
	  "drush -y --root=/var/www pm-disable memcache memcache_admin";
	print_log( "CMD", "$cmd_memcache", "SCREEN" );
	my $retour_memcache = `$cmd_memcache`;
	print_log( "DEBUG", "RETOUR : $retour_memcache", "SCREEN" );
	
	#creation des utilisateurs selenium
  	my $retour_user1 = `drush --root=/var/www user-create SeleniumAdmin --password="nJ52\!zQ47" --mail="sqdrfvsdqgsd\@qsgsdqg.fr" \n`;
  	print_log("INFO", "user SeleniumAdmin created", "BOTH");
  	my $retour_user2 = `drush --root=/var/www user-create SeleniumBO --password="nJ52\!zQ47" --mail="qsfvqsfef\@qsgfsqdg.fr" \n`;
  	print_log("INFO", "user SeleniumBO created", "BOTH");
  	my $retour_user_role1 = `drush --root=/var/www user-add-role "functional admin" SeleniumAdmin \n`;
  	my $retour_user_role2 = `drush --root=/var/www user-add-role "functional head" SeleniumAdmin,SeleniumBO \n`;
  	print_log("INFO", "role assigned", "BOTH");
  	
  	my $retour_user_pwd_force_change1 = `$database_instruction 'UPDATE password_policy_force_change SET force_change= 0 WHERE uid = (SELECT u.uid FROM users u WHERE u.name = "SeleniumAdmin" LIMIT 0, 1)';\r`;
  	my $retour_user_pwd_force_change2 = `$database_instruction 'UPDATE password_policy_force_change SET force_change= 0 WHERE uid = (SELECT u.uid FROM users u WHERE u.name = "SeleniumBO" LIMIT 0, 1)';\r`;
	print_log("INFO", "password policy change", "BOTH");

	print_log( "INFO", "Variables", "SCREEN" );
	$cmd_drush =
	  "drush -y --root=/var/www vset --always-set maintenance_mode 0";
	print_log( "CMD", "$cmd_drush", "SCREEN" );
	$retour_drush = `$cmd_drush `;
	print_log( "DEBUG", "RETOUR : $retour_drush", "SCREEN" );

	$cmd_drush =
"drush -y --root=/var/www vset --always-set obs_maintenance_block_users 0";
	print_log( "CMD", "$cmd_drush", "SCREEN" );
	$retour_drush = `$cmd_drush `;
	print_log( "DEBUG", "RETOUR : $retour_drush", "SCREEN" );

	print_log( "INFO", "Redémarrage Apache", "SCREEN" );
	$cmd_apache = "echo Silicomp69 | sudo -S service apache2 restart";
	print_log( "CMD", "$cmd_apache", "SCREEN" );
	$retour_apache = `$cmd_apache`;
	print_log( "DEBUG", "RETOUR : $retour_apache", "SCREEN" );

	print_log( "INFO", "Fin du script", "SCREEN" );
}
exit;
