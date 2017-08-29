#!/usr/bin/perl

# ********************************************* #
#                                                #
# Auteur : Christophe Madeja                    #
# Date : 09/03/2015                                #
# Description : Parse des fichiers d'accès pour trouver les urls accédés pendant la MEP        #
# Arguments :                                    #
#     1 - <debut_log>                                #
#                                                #
# ********************************************* #


# ---- PRAGMAS

use strict;
use warnings;
use diagnostics;
use Net::SSH2;
use Date::Language;
use Date::Format;

require "functions.pl";


# ---- VARIABLES GLOBALES
my $OPE;

my $USER_PROD = 'ruby';
my $IP_PROD = '94.124.134.12';
my $PWD_PROD = 'abDXYtCGv3';
my $R_LOGS = '/logs/ruby-was01-prod/apache';
my $SRC = 'access.log';
my $tmp_log;


# ---- FONCTIONS

sub display_syntax() {
	print_log( "HELP", "ERREUR - Syntaxe : parse_access_logs <debut_log (09/Mar/2015:15:02:11)>", "SCREEN" );
    exit;
}

# ********************
# Nom : drupal_index_procedures
# Description : lance les procédures d'indexation de contenu
# Argument : -
# ********************
sub drupal_parse_logs {
	my $debut_log = shift;
	my $debut_log_cmd = "echo ".$debut_log." | sed -e 's:/:\\\\/:g' | tr -d '\n'";
	$debut_log = `$debut_log_cmd`;
	my $fin_log;
	my $lang = Date::Language->new('English');
	$fin_log = $lang->time2str("%d\\/%b\\/%Y:%H:%M:%S", time);
	print_log("INFO", "debut log : ".$debut_log, "BOTH");
	print_log("INFO", "fin log : ".$fin_log, "BOTH");
	if (-e '/tmp/'.$SRC) {
		my $tmp_rm_log;
		my $tmp_rm_log_cmd = "rm -f /tmp/tmp_access.log";
		print_log("INFO", $tmp_rm_log_cmd, "BOTH");
		$tmp_rm_log = `$tmp_rm_log_cmd`;
		
		my $tmp_log_cmd = "sed -n '/".$debut_log."/ , /".$fin_log."/p' /tmp/access.log > /tmp/tmp_access.log";
		print_log("INFO", $tmp_log_cmd, "BOTH");
		$tmp_log = `$tmp_log_cmd`;
		
		my $tmp_log_grep_cmd = "grep -Po '(?<=GET ).*(?=HTTP)' tmp_access.log > url_access.log";
		print_log("INFO", $tmp_log_grep_cmd, "BOTH");
		my $tmp_log_grep = `$tmp_log_grep_cmd`;
		
		#my $tmp_log_clean_cmd1 = "grep -Ev 'files' url_access.log > url_access_tmp.log";
		#my $tmp_log_clean_cmd1 = "grep -Ev 'files|theme_events' url_access.log > url_access_tmp.log";
		#my $tmp_log_clean_cmd3 = "grep -Ev 'theme_france' url_access_tmp.log > url_access_tmp1.log";
		#my $tmp_log_clean_cmd4 = "grep -Ev 'theme_events' url_access_tmp1.log > url_access_tmp2.log";
		#my $tmp_log_clean_cmd5 = "grep -Ev 'theme_obs' url_access_tmp2.log > url_access_tmp3.log";
		#my $tmp_log_clean_cmd6 = "grep -Ev 'theme_russe' url_access_tmp3.log > url_access_tmp4.log";
		#my $tmp_log_clean_cmd7 = "grep -Ev 'theme_magazine' url_access_tmp4.log > url_access_tmp5.log";
		#my $tmp_log_clean_cmd8 = "grep -Ev 'theme_webtv' url_access_tmp5.log > url_access_tmp6.log";
		#my $tmp_log_clean_cmd9 = "grep -Ev 'modules' url_access_tmp6.log > url_access_tmp7.log";
		#my $tmp_log_clean_cmd10 = "grep -Ev 'sites/all/' url_access_tmp7.log > url_access_tmp8.log";
		my $tmp_log_clean_cmd = "grep -Ev 'files|sites/all/|sites/common_resources/' url_access.log > url_access_tmp.log";
		
		my $tmp_log_clean = `$tmp_log_clean_cmd`;
		#my $tmp_log_clean1 = `$tmp_log_clean_cmd1`;
		#my $tmp_log_clean3 = `$tmp_log_clean_cmd3`;
		#my $tmp_log_clean4 = `$tmp_log_clean_cmd4`;
		#my $tmp_log_clean5 = `$tmp_log_clean_cmd5`;
		#my $tmp_log_clean6 = `$tmp_log_clean_cmd6`;
		#my $tmp_log_clean7 = `$tmp_log_clean_cmd7`;
		#my $tmp_log_clean8 = `$tmp_log_clean_cmd8`;
		#my $tmp_log_clean9 = `$tmp_log_clean_cmd9`;
		#my $tmp_log_clean10 = `$tmp_log_clean_cmd10`;
	}
}


# ---- PROGRAMME PRINCIPAL

# Verifications des arguments
my $nb_arg = $#ARGV + 1;
if ($nb_arg < 1) {
    display_syntax();
} else {
	my $debut_log = $ARGV[0];
	my $ssh2 = Net::SSH2->new();
	$ssh2->connect($IP_PROD) or die $!;
	
	if ($ssh2->auth(username => $USER_PROD, password => $PWD_PROD)) {
	    print_log("INFO", "Connexion SSH au serveur de PROD", "BOTH");
	    print_log("INFO", "Téléchargement du fichier $SRC", "BOTH");
		if ($ssh2->scp_get($R_LOGS."/".$SRC, '/tmp/'.$SRC)){
			print_log("INFO", "Fichier téléchargé", "BOTH");
		    $ssh2->disconnect();
			print_log("INFO", "Connexion SSH fermée", "BOTH");
			
			drupal_parse_logs($debut_log);
		}
	}
}
	