#!/usr/bin/perl

# ********************************************* #
#                                               #
# Auteur : Thibaut Despoulain                   #
# Date : 30/10/2013                             #
# Description : Import d'une sauvegarde BDD     #
# Arguments :                                   #
#     1 - <recetteruby|recetteclient>           #
#     2 - [file.sql.gz]                         #
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
my $MODE;

my $R_ROOT = "/home/orangecom/ruby";
my $R_BIN = $R_ROOT. "/bin";
my $R_LOG = $R_ROOT. "/log";
my $R_SAVE = $R_ROOT. "/backup";
my $R_SAVE_LAST = $R_SAVE . "/daily/drupal";
my $R_SAVE_FILE; 
my $F_LOG;
my $A_SQL;
my $F_SQL;

my $database = "drupal";
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
    print "ERREUR - Syntaxe : revert-bdd <recetteruby|recetteclient> [file.sql.gz]\n";
    exit;
}

# ---- PROGRAMME PRINCIPAL

my $nb_arg = $#ARGV + 1;
if ($nb_arg < 1) {
    display_syntax();
} else {
    # Parametres
    $ENV = $ARGV[0];
    
    # Verification ENV
    if ($ENV ne "recetteruby"
        && $ENV ne "recetteclient") {
        display_syntax();
    }
    
    # Gestion du mode
    if ($nb_arg == 1) {
        $MODE = "last";
        
        
    } elsif ($nb_arg == 2) {
        $MODE = "file";
        $A_SQL = $ARGV[1];
        
        
    } else {
        display_syntax();
    }
    
    # Initialisation du LOG
    $F_LOG = $R_LOG."/".$date."_revert_".$ENV.".log";
    open(LOGFILE, ">", $F_LOG) or die "ERREUR : impossible d'ouvrir $F_LOG : $!";

    print_log("INFO", "Debut du script de revert sur $ENV en mode $MODE", "BOTH");
    
    # Connexion SSH
    my $exp = new Expect;
    $exp->raw_pty(1);
    $exp->log_stdout(0);
    $exp->spawn("ssh orangecom\@".$ENV) or die "ERREUR : impossible d'etablir une connexion SSH : $!\n";
    $exp->expect(5, "orangecom\@");
    $exp->clear_accum();
    if ($MODE eq "last") {
        print_log("DEBUG", "cd $R_SAVE_LAST", "BOTH");
        $exp->send("cd $R_SAVE_LAST\r");
        $exp->expect(5, "orangecom\@");
        $exp->clear_accum();
        print_log("DEBUG", "ls -ctm --color=no", "BOTH");
        $exp->send("ls -ctm --color=no\r");
        $exp->expect(5, ",");
        $A_SQL = $exp->before();
        $exp->clear_accum();
        if ($A_SQL !~ /\.sql\.gz/) {
            print_log("ERREUR", "Ce n'est pas une archive", "BOTH");
            exit;
        }
    } elsif ($MODE eq "file") {
        print_log("DEBUG", "cd $R_SAVE", "BOTH");
        $exp->send("cd $R_SAVE\r");
        $exp->expect(5, "orangecom\@");
        $exp->clear_accum();
        print_log("DEBUG", "find . -name '$A_SQL'", "BOTH");
        $exp->send("find . -name '" . $A_SQL . "'\r");
        $exp->expect(5, "orangecom\@");
        my $R_TMP = $exp->before();
        chomp($R_TMP);
        if ($R_TMP =~ /\.\/(.*\/)+(.*\.sql\.gz)/) {
            $R_SAVE_FILE = $1;
            $A_SQL = $2;
        } else {
            print_log("ERREUR", "Le fichier $A_SQL n'existe pas", "BOTH");
            exit;
        }
        $exp->clear_accum();
        print_log("DEBUG", "cd $R_SAVE_FILE", "BOTH");
        $exp->send("cd $R_SAVE_FILE\r");
        $exp->expect(5, "orangecom\@");
        $exp->clear_accum();
    } else {
        display_syntax();
    }
    print_log("INFO", "Archive SQL a importer : $A_SQL", "BOTH");
    print_log("INFO", "Decompression de l'archive", "BOTH");
    print_log("DEBUG", "gunzip $A_SQL", "BOTH");
    $exp->send("gunzip $A_SQL\r");
    $exp->expect(15, "orangecom\@");
    $exp->clear_accum();
    $F_SQL = $A_SQL;
    $F_SQL =~ s/\.gz//;
    print_log("INFO", "Fichier SQL: $F_SQL", "BOTH");
    print_log("INFO", "Test d'existence du fichier", "BOTH");
    $exp->send("if test -f $F_SQL ; then echo 1 ; else echo 0 ; fi \r");
    $exp->expect(5, "orangecom\@");
    my $existence = $exp->before();
    chomp($existence);
    $exp->clear_accum();
    if ($existence =~ /1/) {
        print_log("DEBUG", "Existe : OK", "BOTH");
        print_log("INFO", "On supprime et recree la base de donnees $database", "BOTH");
        print_log("DEBUG", "mysql -uroot -pSilicomp69 --debug-info -e 'DROP DATABASE $database;CREATE DATABASE $database DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;'", "BOTH");
        $exp->send("mysql -uroot -pSilicomp69 --debug-info -e 'DROP DATABASE $database;CREATE DATABASE $database DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;'\r");
        $exp->expect(15, "orangecom\@");
        print_log("DEBUG",  $exp->before(), "BOTH");
        $exp->clear_accum();
        print_log("INFO", "Suppression et recretion OK", "BOTH");
        print_log("INFO", "Import des donnees", "BOTH");
        print_log("DEBUG", "mysql -uroot -pSilicomp69 --debug-info -D $database < $F_SQL", "BOTH");
        $exp->send("mysql -uroot -pSilicomp69 --debug-info -D $database < $F_SQL \r");
        $exp->expect(undef, "orangecom\@");
        print_log("DEBUG",  $exp->before(), "BOTH");
        $exp->clear_accum();
        print_log("INFO", "Archivage du fichier SQL", "BOTH");
        print_log("DEBUG", "gzip $F_SQL", "BOTH");
        $exp->send("gzip $F_SQL\r");
        $exp->expect(5, "orangecom\@");
        $exp->clear_accum();
    } else {
        print_log("ERREUR", "Le fichier $F_SQL n'existe pas", "BOTH");
    }
    $exp->soft_close();
    print_log("INFO", "Fin du script", "BOTH");
}
close(LOGFILE);
exit;
