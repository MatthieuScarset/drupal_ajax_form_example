#!/usr/bin/perl

# ********************************************* #
#                                                #
# Auteur : Thibaut Despoulain                    #
# Date : 30/10/2013                                #
# Description : Creation de l'archive IPP        #
# Arguments :                                    #
#     1 - <version>                                #
#                                                #
# ********************************************* #

# ---- PRAGMAS

use strict;
use warnings;
use diagnostics;
use LWP::UserAgent;
use HTTP::Request;

require "functions.pl";

# ---- VARIABLES GLOBALES

my $VERSION;

my $R_CURRENT;
my $R_ROOT = "/home/orangecom/ruby";
my $R_BIN = $R_ROOT. "/bin";
my $R_LOG = $R_ROOT. "/log";
my $R_SAVE = $R_ROOT. "/backup/files";
my $R_WWW = "/var/www";
my $R_LIV = "/var/livrable";
my $A_LIV;
# version = 1.0.92
my $R_SITES = "sites/all";
my $R_CONF = "conf";
my $F_LOG;
my $A_FILES;

my $R_SRC = "";
my $SRC;

my $cmd_date = "date +%Y%m%d_%H%M%S";
my $date = `$cmd_date`;
chomp($date);

my $user = 'ruby';
my $pass = 'ZQpXXfaGgDYV';
my $url;
my $contents;
my $F_ROBOTS_PRP = "/var/livrable/env/preproduction/robots.txt";
my $F_ROBOTS_PROD = "/var/livrable/env/production/robots.txt";
my $F_SITEMAP_PRP = "/var/livrable/env/preproduction/sitemap.xml";
my $F_SITEMAP_PROD = "/var/livrable/env/production/sitemap.xml";
my $F_CONF = "/var/livrable/package.properties";

# ---- FONCTIONS

# ********************
# Nom : display_syntax
# Description : définition de la syntaxe
# Argument : -
# ********************

sub display_syntax() {
    print "ERREUR - Syntaxe : archive-ipp <version>\n";
    exit;
}

sub get_robots {
        my $url = shift;
        my $protected = shift;
        my $timeout = 10;
        my $max_redirects = 10;
        my ($request, $response, $status, $link, $contents, $page_parser, $cachefile);

        my $browser = LWP::UserAgent->new(agent => "OBS-auto",
            timeout => $timeout,
            max_redirect => $max_redirects,
            env_proxy => 1,
            parse_head => 0);

        $request = new HTTP::Request 'GET' => "$url";
        if ($protected) {
            $request->authorization_basic($user, $pass);
        }
        $response = $browser->request($request);

        if ($response->is_success()) {
            $contents = $response->content();
            return $contents;
        } else {
            die $response->status_line;
        }
}

sub write_robots {
	my $robots_file_path = shift;
	
	chdir $R_WWW;
	
	my $node_private_folders_drush_command = "drush vget -y 'node_private_folders'  | grep -o '\".*\"' | tr -d '\"'";
	my $node_private_folders;
	if ($node_private_folders = `$node_private_folders_drush_command`){
	}
	else{
		$node_private_folders = 'pages/';
	}
	my @private_folders = split(',', $node_private_folders);

	foreach my $private_folder (@private_folders) {
		chomp($private_folder);
		print_log("INFO", $private_folder, "BOTH");
		
		my $grep_robot_command = "grep '$private_folder' $robots_file_path";
		my $grep_robot = `$grep_robot_command`;
		if ($grep_robot eq ""){
			my $write_robot_command_und = "echo 'Disallow: /$private_folder' >> $robots_file_path";
			my $write_robot_und = `$write_robot_command_und`;
			print_log("INFO", $write_robot_command_und, "BOTH");
			
			my $write_robot_command_en = "echo 'Disallow: /en/$private_folder' >> $robots_file_path";
			my $write_robot_en = `$write_robot_command_en`;
			print_log("INFO", $write_robot_command_en, "BOTH");
			
			my $write_robot_command_fr = "echo 'Disallow: /fr/$private_folder' >> $robots_file_path";
			my $write_robot_fr = `$write_robot_command_fr`;
			print_log("INFO", $write_robot_command_fr, "BOTH");
			
			my $write_robot_command_ru = "echo 'Disallow: /ru/$private_folder' >> $robots_file_path";
			my $write_robot_ru = `$write_robot_command_ru`;
			print_log("INFO", $write_robot_command_ru, "BOTH");
			
			my $write_robot_command_ru_en = "echo 'Disallow: /ru-en/$private_folder' >> $robots_file_path";
			my $write_robot_ru_en = `$write_robot_command_ru_en`;
			print_log("INFO", $write_robot_command_ru_en, "BOTH");
		}  		
	}
	
	chdir $R_LIV;
}

# ---- PROGRAMME PRINCIPAL

# Verifications des arguments
my $nb_arg = $#ARGV + 1;
if ($nb_arg ne 1) {
    display_syntax();
} else {
    $VERSION = $ARGV[0];
    if ($VERSION !~ /[0-9]+\.[0-9]+\.[0-9]+/) {
        print "ERREUR : la version n'est pas standard\n";
        exit();
    }
    $A_LIV = "obs-ruby-webapp-V".$VERSION.".tgz";


    # Debut du script de revert
    print_log("INFO", "Debut du script d'archive IPP", "SCREEN");

    print_log("INFO", "Etape 1 : Mise a jour de la version $VERSION", "SCREEN");

    open (CONF, ">", $F_CONF) or die "ERREUR : impossible d'ouvrir $F_CONF : $!";
    print CONF "version = " . $VERSION;
    close(CONF);

    print_log("INFO", "Etape 2 : Recopie du dossier sites/all", "SCREEN");
    my $cmd_rm = "cd /var/livrable/common; rm -rf sites includes modules profiles scripts themes misc *.php *.txt web.config ";
    print_log("DEBUG", $cmd_rm, "SCREEN");
    my $retour_rm = `$cmd_rm`;

    my $cmd_cp = "cd /var/www; cp -rpf sites includes modules profiles scripts themes misc *.php *.txt web.config /var/livrable/common";
    print_log("DEBUG", $cmd_cp, "SCREEN");
    my $retour_cp = `$cmd_cp`;

    print_log("INFO", "Etape 3 : Recopie du dossier conf", "SCREEN");
    $cmd_cp = "dos2unix /var/www/conf/drush.conf";
    print_log("DEBUG", $cmd_cp, "SCREEN");
    $retour_cp = `$cmd_cp`;

    $cmd_cp = "cp -f /var/www/conf/drush.conf /var/livrable/env/preproduction/conf/";
    print_log("DEBUG", $cmd_cp, "SCREEN");
    $retour_cp = `$cmd_cp`;

    $cmd_cp = "cp -f /var/www/conf/drush.conf /var/livrable/env/production/conf/";
    print_log("DEBUG", $cmd_cp, "SCREEN");
    $retour_cp = `$cmd_cp`;

    print_log("INFO", "Etape 4 : robots.txt sur PRP", "SCREEN");
    $url = "http://ruby-prp.multimediabs.com/robots.txt";
    $contents = get_robots($url, 1);

    open (ROBOTS, ">", $F_ROBOTS_PRP) or die "ERREUR : impossible d'ouvrir $F_ROBOTS_PRP : $!";
    print ROBOTS $contents;
    close(ROBOTS);
    
    write_robots($F_ROBOTS_PRP);

    print_log("INFO", "Etape 5 : robots.txt sur PROD", "SCREEN");
    $url = "http://orange-business.com/robots.txt";
    $contents = get_robots($url, 0);

    open (ROBOTS, ">", $F_ROBOTS_PROD) or die "ERREUR : impossible d'ouvrir $F_ROBOTS_PROD : $!";
    print ROBOTS $contents;
    close(ROBOTS);
    
    write_robots($F_ROBOTS_PROD);
    
    print_log("INFO", "Etape 6 : sitemap.xml sur PRP", "SCREEN");
    $url = "http://ruby-prp.multimediabs.com/sitemap.xml";
    $contents = get_robots($url, 1);

    open (SITEMAP, ">", $F_SITEMAP_PRP) or die "ERREUR : impossible d'ouvrir $F_SITEMAP_PRP : $!";
    print SITEMAP $contents;
    close(SITEMAP);

    print_log("INFO", "Etape 7 : sitemap.xml sur PROD", "SCREEN");
    $url = "http://orange-business.com/sitemap.xml";
    $contents = get_robots($url, 0);

    open (SITEMAP, ">", $F_SITEMAP_PROD) or die "ERREUR : impossible d'ouvrir $F_SITEMAP_PROD : $!";
    print SITEMAP $contents;
    close(SITEMAP);

    print_log("INFO", "Etape 6 : Creation de l'archive", "SCREEN");
    my $cmd_tar = "cd /var/livrable; tar cvfzp $A_LIV common/ env/ package.properties";
    print_log("DEBUG", $cmd_tar, "SCREEN");
    my $retour_tar = `$cmd_tar`;

    print_log("INFO", "Fin du script", "SCREEN");
}
exit;