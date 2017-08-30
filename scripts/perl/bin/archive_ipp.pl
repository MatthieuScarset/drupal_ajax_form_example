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
my $R_ROOT = "/home/oab_web/ruby";
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
my $F_ENV_PRP = "/var/livrable/env/preproduction";
my $F_ENV_PROD = "/var/livrable/env/production";
my $F_CONF = "/var/livrable/package.properties";
my $A_DUMP = "dump_ruby_$date.sql.gz";

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

    print_log("INFO", "Etape 2 : Recopie des dossiers", "SCREEN");
    my $cmd_rm = "cd /var/livrable/common; rm -rf core libraries modules profiles sites themes vendor *.php *.txt web.config";
    print_log("DEBUG", $cmd_rm, "SCREEN");
    my $retour_rm = `$cmd_rm`;

    my $cmd_cp = "cd /var/www/current/portail; cp -rpf core libraries modules profiles sites themes vendor *.php web.config /var/livrable/common";
    print_log("DEBUG", $cmd_cp, "SCREEN");
    my $retour_cp = `$cmd_cp`;

    print_log("INFO", "Etape 3 : Creation des repertoires environnement", "SCREEN");
    my $cmd_env = "cd /var/livrable; mkdir -p $F_ENV_PRP; mkdir -p $F_ENV_PROD";
    print_log("DEBUG", $cmd_env, "SCREEN");
    my $retour_env = `$cmd_env`;

    print_log("INFO", "Etape 4 : Creation de l'archive", "SCREEN");
    my $cmd_tar = "cd /var/livrable; tar cvfzp $A_LIV common/ env/ package.properties";
    print_log("DEBUG", $cmd_tar, "SCREEN");
    my $retour_tar = `$cmd_tar`;

    print_log("INFO", "Etape 5 : Export base de données", "SCREEN");
    my $cmd_bdd = "mysqldump -uroot -pOrange000 ruby2 > /var/livrable/$A_DUMP";
    print_log("DEBUG", $cmd_bdd, "SCREEN");
    my $retour_bdd= `$cmd_bdd`;

    print_log("INFO", "Fin du script", "SCREEN");
}
exit;