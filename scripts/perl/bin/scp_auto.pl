#!/usr/bin/perl

# ********************************************* #
#                                               #
# Auteur : CMZ									#
# Date : 30/10/2013                             #
# MAJ : 18/11/2014                             	#
# Description : Recopie automatique             #
# Arguments :                                   #
#     1 - <recetteruby|recetteclient|both>   	#
#     2 - <file|directory>                      #
# ********************************************* #

# ---- PRAGMAS

use strict;
use warnings;
use diagnostics;

require "functions.pl";

# ---- VARIABLES GLOBALES

my $ENV_original;
my $ENV;

my $R_CURRENT;
my $R_ROOT = "/home/orangecom/ruby";
my $R_BIN  = $R_ROOT . "/bin";
my $R_WWW  = "/var/www";

my $R_SRC = "";
my $SRC;

# ---- FONCTIONS

# ********************
# Nom : display_syntax
# Description : definition de la syntaxe
# Argument : -
# ********************

sub display_syntax() {
	print_log(
		"HELP",
"scp-auto <recetteruby|recetteclient|both> <file|repository> [<file|repository>]",
		"SCREEN"
	);
	exit;
}

# ********************
# Nom : scp
# Description : recopie d'un element avec la commande scp
# Argument : -
# ********************
sub scp() {
	my $cmd_rm = "ssh $ENV 'rm -rf $R_CURRENT/$SRC; echo \$?;'";
	print_log( "CMD", "$cmd_rm", "SCREEN" );
	my $rm = 0;
	$rm = `$cmd_rm`;
	chomp($rm);
	if ( $rm eq 0 ) {
		print_log( "OK", "Supppression effectuee avec succes", "SCREEN" );
	} else {
		print_log( "ERREUR", "Probleme lors de la supppression", "SCREEN" );
	}

	my $cmd_scp = "scp -rp $SRC $ENV\:$R_CURRENT/$R_SRC; echo \$?;";
	print_log( "CMD", "$cmd_scp", "SCREEN" );
	my $scp = 0;
	$scp = `$cmd_scp`;
	chomp($scp);
	if ( $scp eq 0 ) {
		print_log( "OK", "Recopie effectuee avec succes", "SCREEN" );
	} else {
		print_log( "ERREUR", "Probleme lors de la recopie", "SCREEN" );
	}
}

# ---- PROGRAMME PRINCIPAL

# Verifications des arguments
my $nb_arg = $#ARGV + 1;
if ( $nb_arg < 2 ) {
	display_syntax();
} else {
	$ENV_original = $ARGV[0];

	# Détermination de l'environnement
	if (   $ENV_original ne "recetteruby"
		&& $ENV_original ne "recetteclient"
		&& $ENV_original ne "both" )
	{
		display_syntax();
	}

	# Debut du script de revert
	print_log( "INFO", "Debut du script scp-auto sur $ENV_original", "SCREEN" );

	# Repertoire courant
	my $cmd_pwd = "pwd";
	print_log( "CMD", "$cmd_pwd", "SCREEN" );
	$R_CURRENT = `$cmd_pwd`;
	chomp($R_CURRENT);
	print_log( "INFO", "Chemin courant : $R_CURRENT", "SCREEN" );

	my $i = 1;
	print_log( "DEBUG", "Nombre d'arguments : $nb_arg", "SCREEN" );
	for ( $i = 1 ; $i < $nb_arg ; $i++ ) {
		$R_SRC = '';
		$SRC   = $ARGV[$i];

		print_log( "INFO", "Traitement : $SRC", "SCREEN" );
		my $cmd_dirname = "dirname $SRC";
		print_log( "CMD", "$cmd_dirname", "SCREEN" );
		my $dirname = `$cmd_dirname`;
		chomp($dirname);

		if ( $dirname ne "." ) {
			$R_SRC = $dirname;
			print_log( "INFO", "Répertoire source : $R_SRC", "SCREEN" );
		}

		if ( -e $R_CURRENT . "/" . $SRC ) {
			if ( $ENV_original eq "both" ) {
				print_log( "INFO", "Recopie sur recetteruby", "SCREEN" );
				$ENV = "recetteruby";
				scp();
				print_log( "INFO", "Recopie sur recetteclient", "SCREEN" );
				$ENV = "recetteclient";
				scp();
			} else {
				$ENV = $ENV_original;
				print_log( "INFO", "Recopie sur $ENV", "SCREEN" );
				scp();
			}
		} else {
			print_log( "ERREUR", "La source $SRC n'existe pas", "SCREEN" );
			exit;
		}
	}
	print_log( "INFO", "Fin du script", "SCREEN" );
}
exit;
