#!/usr/bin/perl

# ********************************************* #
#                                               #
# Auteur : Thibaut Despoulain                   #
# Date : 30/10/2013                             #
# Description : Export/Import de la BDD         #
# Arguments :                                   #
#     1 - <recetteruby|recetteclient>           #
#                                               #
# ********************************************* #

# ---- PRAGMAS

use strict;
use warnings;
use diagnostics;
use Expect;

require "functions.pl";

# ---- VARIABLES GLOBALES

my $ENV;

my $R_ROOT = "/home/orangecom/ruby";
my $R_BIN = $R_ROOT. "/bin";
my $R_LOG = $R_ROOT. "/log";
my $F_LOG;
my $F_CONF = "/var/www/conf/drush.conf";

my $database = "testrevert";
my $cmd_date = "date +%Y%m%d_%H%M%S";
my $date = `$cmd_date`;
chomp($date);

# ---- FONCTIONS

# ********************
# Nom : display_syntax
# Description : definition de la syntaxe
# Argument : -
# ********************
sub display_syntax() {
    print "ERREUR - Syntaxe : update-bdd <recetteruby|recetteclient>\n";
    exit;
}

# ---- PROGRAMME PRINCIPAL

my $nb_arg = $#ARGV + 1;
if ($nb_arg ne 1) {
    display_syntax();
} else {
    # Paramètres
    $ENV = $ARGV[0];
    
    # Vérification ENV
    if ($ENV ne "recetteruby"
        && $ENV ne "recetteclient") {
        display_syntax();
    }
    
    # Initialisation du LOG
    $F_LOG = $R_LOG."/".$date."_update_bdd_".$ENV.".log";
    open(LOGFILE, ">", $F_LOG) or die "ERREUR : impossible d'ouvrir $F_LOG : $!";
    
    # Debut du script de revert
    print_log("INFO", "Debut du script d'update BDD sur $ENV", "BOTH");

    # Connexion SSH
    my $exp = new Expect;
    $exp->raw_pty(1);
    $exp->log_stdout(0);
    $exp->spawn("ssh orangecom\@".$ENV) or die "ERREUR : impossible d'etablir une connexion SSH : $!\n";
    $exp->expect(5, "orangecom\@");
    $exp->clear_accum();
    
    # Existence de drush.conf
    if ( -e $F_CONF ) {
        print_log("INFO", "Parcours du  fichier $F_CONF", "BOTH");
        open(DRUSH, "<", $F_CONF) or die "ERREUR : impossible d'ouvrir $F_CONF : $!";
        while (my $line = <DRUSH>) {
            print_log("DEBUG", "drush --root=/var/www/ -y -d $line", "BOTH");
            $exp->send("drush --root=/var/www/ -y -d $line \r");
            $exp->expect(undef, "orangecom\@$ENV");
            print_log("DEBUG", $exp->before(), "BOTH");
            $exp->clear_accum();
        }
        close(DRUSH);
    } else {
        print_log("ERREUR", "Le fichier $F_CONF n'existe pas", "BOTH");
        exit;
    }
    print_log("INFO", "Fin du script", "BOTH");
    $exp->soft_close();
}
close(LOGFILE);
exit;
