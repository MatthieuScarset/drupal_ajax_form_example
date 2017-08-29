#!/usr/bin/perl

# ********************************************* #
#                                               #
# Auteur : Thibaut Despoulain                   #
# Date : 30/10/2013                             #
# Description : Livraison sur env interne       #
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
my $R_SAVE = $R_ROOT. "/backup";
my $R_SAVE_BDD = $R_SAVE . "/bdd";
my $R_SAVE_FILE = $R_SAVE . "/files"; 
my $F_LOG;
my $A_SQL;
my $F_DUMP;
my $A_DUMP;
my $A_FILES;

my $database = "drupal";
my $cmd_date = "date +%Y%m%d_%H%M%S";
my $date = `$cmd_date`;
chomp($date);

# ---- FONCTIONS

# ********************
# Nom : display_syntax
# Description : decrire la syntaxe attendue du script
# Argument : -
# ********************

sub display_syntax() {
	print "ERREUR - Syntaxe : livraison <recetteruby|recetteclient>\n";
	exit;
}

# ---- PROGRAMME PRINCIPAL

# Verification des parametres passes au script
my $nb_arg = $#ARGV + 1;
if ($nb_arg ne 1) {
	display_syntax();
} else {
	# Recuperation des parametres
	$ENV = $ARGV[0];
	if ($ENV ne "recetteruby"
		&& $ENV ne "recetteclient") {
			display_syntax();
	}
	
	# Initialisation du LOG
    $F_LOG = $R_LOG."/".$date."_livraison_".$ENV.".log";
    open(LOGFILE, ">", $F_LOG) or die "ERREUR : impossible d'ouvrir $F_LOG : $!";

    print_log("INFO", "Debut du script de livraison sur $ENV", "BOTH");
    
    print_log("INFO", "Etape 1 : dump de la base de donnees", "BOTH");
    $F_DUMP = "dump_ruby_$date.sql";
    $A_DUMP = "dump_ruby_$date.sql.gz";
    my $exp = new Expect;
    $exp->raw_pty(1);
    $exp->log_stdout(0);
    $exp->spawn("ssh orangecom\@".$ENV) or die "ERREUR : impossible d'etablir une connexion SSH : $!\n";
    $exp->expect(5, "orangecom\@");
    $exp->clear_accum();
    my $cmd_dump = "mysqldump -uroot -pSilicomp69 --database $database > $R_SAVE_BDD/$F_DUMP";
    print_log("DEBUG", $cmd_dump, "BOTH");
    $exp->send("$cmd_dump\r");
    $exp->expect(undef, "orangecom\@");
    $exp->clear_accum();
    
    my $cmd_gzip = "gzip $R_SAVE_BDD/$F_DUMP";
    print_log("DEBUG", $cmd_gzip, "BOTH");
    $exp->send("$cmd_gzip\r");
    $exp->expect(5, "orangecom\@");
    $exp->clear_accum();
    $exp->close();
	
	print_log("INFO", "Etape 2 : update de la base de donnees", "BOTH");
	my $scan_update = "";
	while ($scan_update ne "O" 
		&& $scan_update ne "n") {
		print "Voulez-vous mettre a jour la base de donnes (O/n) ? ";
		chomp(my $input = <STDIN>);
		$scan_update = $input; 	
	}
	
	print_log("DEBUG", "Reponse : $scan_update", "BOTH");
	
	my $A_SQL;
	if ($scan_update eq "0") {
		print "Archive ? ";
		chomp(my $input = <STDIN>);
		$A_SQL = $input; 
		
		my $cmd_revert = "$R_BIN/revert_bdd.pl $ENV $A_SQL";
		print_log("DEBUG", $cmd_revert, "BOTH");
		my $retour_revert = `$cmd_revert`;
	}

	print_log("INFO", "Etape 3 : recopie des fichiers", "BOTH");
	my $cmd_scp = "$R_BIN/scp_auto.pl $ENV -all";
	print_log("DEBUG", $cmd_scp, "BOTH");
	my $retour_scp = `$cmd_scp`;
	if ($retour_scp =~ /ARCHIVE : (.*\.tar\.gz)/) {
		$A_FILES = $1;
	}
	
	print_log("DEBUG", "Sauvegarde des fichiers : $A_FILES", "BOTH");
 	
 	print_log("INFO", "Etape 4 : update Drupal", "BOTH");
 	my $cmd_update = "$R_BIN/update_bdd.pl $ENV";
 	my $retour_update = `$cmd_update`;
 	
 	print_log("INFO", "Etape 5 : verification", "BOTH");
 	my $scan_verif = "";
 	while ($scan_verif ne "O" && $scan_verif ne "n") {
 		print "Voulez-vous proceder a un retour arriere (O/n) ? ";
 		chomp(my $input = <STDIN>);
 		$scan_verif = $input; 
 	}
 	
 	print_log("DEBUG", "Reponse : $scan_verif", "BOTH");
 	if ($scan_verif eq "0") {
 		print_log("INFO", "Etape 6 : revert de la base de donnees", "BOTH");
 		my $cmd_revert_bdd = "$R_BIN/revert_bdd.pl $ENV $A_DUMP";
 		my $retour_bdd = `$cmd_revert_bdd`;
 		
 		print_log("INFO", "Etape 7 : revert des fichiers", "BOTH");
 		my $cmd_revert_files = "$R_BIN/revert_files.pl $ENV $A_FILES";
 		my $retour_revert_files =`$cmd_revert_files`;	
 	}
	
	print_log("INFO", "Fin du script", "BOTH");
}
close(LOGFILE);
exit;