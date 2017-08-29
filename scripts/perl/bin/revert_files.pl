#!/usr/bin/perl

# ********************************************* #
#                                               #
# Auteur : Thibaut Despoulain                   #
# Date : 30/10/2013                             #
# Description : Import d'une archive            #
# Arguments :                                   #
#     1 - <recetteruby|recetteclient>           #
#     2 - archive.tar.gz                        #
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
my $R_WWW = "/var/www";
my $R_BIN = $R_ROOT. "/bin";
my $R_LOG = $R_ROOT. "/log";
my $R_SAVE = $R_ROOT. "/backup/files";

my $F_LOG;
my $A_SAVE;

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
    print "ERREUR - Syntaxe : revert-files <recetteruby|recetteclient> <archive.tar.gz>\n";
    exit;
}

# ---- PROGRAMME PRINCIPAL

my $nb_arg = $#ARGV + 1;
if ($nb_arg ne 2) {
    display_syntax();
} else {
    # Parametres
    $ENV = $ARGV[0];
    $A_SAVE = $ARGV[1];
    
    # Verification ENV
    if ($ENV ne "recetteruby"
        && $ENV ne "recetteclient") {
        display_syntax();
    }
    
    if ($A_SAVE !~ /\.tar\.gz/) {
        display_syntax();
    }
    
    # Initialisation du LOG
    $F_LOG = $R_LOG."/".$date."_revert_files_".$ENV.".log";
    open(LOGFILE, ">", $F_LOG) or die "ERREUR : impossible d'ouvrir $F_LOG : $!";
    
    # Debut du script de revert
    print_log("INFO", "Debut du script de revert files sur $ENV", "BOTH");

    # Connexion SSH
    my $exp = new Expect;
    $exp->raw_pty(1);
    $exp->log_stdout(0);
    $exp->spawn("ssh orangecom\@".$ENV) or die "ERREUR : impossible d'etablir une connexion SSH : $!\n";
    $exp->expect(5, "orangecom\@");
    $exp->clear_accum();
    
    # Existence de l'archive
    $exp->send("if test -f $R_SAVE/$A_SAVE ; then echo 1 ; else echo 0 ; fi \r");
    $exp->expect(5, "orangecom\@");
    my $existence = $exp->before();
    chomp($existence);
    $exp->clear_accum();
    if ($existence =~ /1/) {
        print_log("INFO", "L'archive $R_SAVE/$A_SAVE existe", "BOTH");
        print_log("DEBUG", "cd $R_WWW", "BOTH");
        $exp->send("cd $R_WWW \r");
        $exp->expect(5, "orangecom\@");
        $exp->clear_accum();
        print_log("DEBUG", "rm -rf sites", "BOTH");
        $exp->send("rm -rf sites\r");
        $exp->expect(15, "orangecom\@");
        $exp->clear_accum();
        print_log("DEBUG", "tar xvfz $R_SAVE/$A_SAVE -C . ", "BOTH");
        $exp->send("tar xvfz $R_SAVE/$A_SAVE -C . \r");
        $exp->expect(undef, "orangecom\@");
        $exp->clear_accum();
        
        if ($ENV eq "recetteruby") {
            print_log("INFO", "Redemarrage de memcached", "BOTH");
            print_log("DEBUG", "sudo /usr/sbin/service memcached restart", "BOTH");
            $exp->send("sudo /usr/sbin/service memcached restart \r");
            $exp->expect(10, "orangecom\@");
            $exp->clear_accum();
        }
        print_log("INFO", "Revert files OK", "BOTH");
    } else {
        print_log("ERREUR", "L'archive $R_SAVE/$A_SAVE n'existe pas", "BOTH");
        exit;
    }
    print_log("INFO", "Fin du script", "BOTH");
    $exp->soft_close();
}
close(LOGFILE);
exit;
