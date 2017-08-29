#!/usr/bin/perl

# ---- PRAGMAS

use strict;
use warnings;

require "functions.pl";

my $R_SITES = '/var/www/sites/all';
my $R_THEMES = $R_SITES. '/themes';
my $F_LOG = 'liste_image_to_delete.txt';

open (FIC,  ">>$F_LOG" );
if ( -e $R_THEMES ) {
   print_log("INFO", "Le répertoire $R_THEMES existe.", "SCREEN");


	my @l = glob("$R_THEMES/*");
	my $nb_to_delete = 0;
	foreach my $rep (@l) {
		if( -d $rep ) {
			print_log("INFO", "Répertoire : $rep", "SCREEN");
			
			my @dossiers = ( "$rep/images",  "$rep/images/static", "$rep/images/icon-social");
			
			foreach my $R_IMAGES (@dossiers) {
				if ( -e $R_IMAGES ) {
					 print_log("INFO", "Le répertoire image existe.", "SCREEN");
	
					opendir REP, $R_IMAGES or die "impossible d'ouvrir le repertoire";
					my @fichiers = readdir REP;
					closedir REP;
					foreach my $entree (@fichiers) {
						print "$entree\n"; 
						if ($entree =~ /\.(png|jpg|jpeg|gif)/) {
							my $retour = `grep -R $entree $rep`;
							
							if (!defined $retour || $retour eq '') {
								$retour = `grep -R $entree $R_SITES/modules/obs_*`;
								
								if (!defined $retour || $retour eq '') {
									print_log("DEBUG", "Suppression du fichier : $R_IMAGES/$entree", "SCREEN");
									print FIC "$R_IMAGES/$entree\n";
									`rm -f $R_IMAGES/$entree`; 
									$nb_to_delete++;
									
								}
							}
						} else {
							print_log("DEBUG", "Fichier non image : $R_IMAGES/$entree", "SCREEN");
						}	
					}
				}
			}
			
		}
		
	} 
	print_log("DEBUG", "Nb à supprimer : $nb_to_delete", "SCREEN");

} else {
    print_log("ERREUR", "Le répertoire $R_THEMES n'existe pas.", "SCREEN");
}
close(FIC);
exit;
		