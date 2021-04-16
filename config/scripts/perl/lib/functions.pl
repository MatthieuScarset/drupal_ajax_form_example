# ********************************************* #
#                                               #
# Auteur : CMZ		                			#
# Date : 30/10/2013                             #
# Description : Fonctions génériques            #
#                                               #
# ********************************************* #

use Term::ANSIColor;

# ********************
# Nom : print_log
# Description : remplissage du log
# Arguments :
#        1 - INFO|ERREUR|DEBUG
#       1 - message
#       2 - LOG|SCREEN|BOTH
# ********************

sub print_log {
	my $type    = shift;
	my $string  = shift;
	my $display = shift;

	my $time = `date '+%d/%m/%Y %H:%M:%S'`;
	chomp($time);

	if ( $type eq "ERREUR" ) {
		print color 'red';
	}
	elsif ( $type eq "CMD" ) {
		print color 'yellow';
	}
	elsif ( $type eq "OK" ) {
		print color 'green';
	}
	elsif ( $type eq "DEBUG" ) {
		print color 'cyan';
	}
	elsif ( $type eq "HELP" ) {
		print color 'magenta';
	}

	if ( $display eq "SCREEN" ) {
		print "$time - $type - $string\n";
	}
	elsif ( $display eq "LOG" ) {
		print LOGFILE "$time - $type - $string\n";
	}
	elsif ( $display eq "BOTH" ) {
		print "$time -  $type - $string\n";
		print LOGFILE "$time - $type - $string\n";
	}
	else {
		print "ERREUR : Le type d'affichage demande est inconnu.\n";
	}

	print color 'reset';
}

1;