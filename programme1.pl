#!/usr/bin/perl
use strict;
use warnings;

our $x = 10;

sub lexical_scope {
    # la variable locale masque la globale mais ne se propage pas aux appels imbriqués.
    print "\nPortée lexicale (my)\n";
    print "Avant lexical_scope : x = $x\n";

    my $x = 20;    # Nouvelle variable $x limitée à cette sous-routine.
    print "Pendant lexical_scope : x = $x\n";

    inner();
    print "Après appel interne dans lexical_scope : x = $x\n";
}

sub dynamic_scope {
    # on remplace temporairement la variable globale et elle est visible pour les sous-appels.
    print "\nPortée dynamique (local)\n";
    print "Avant dynamic_scope : x = $x\n";

    local $x = 30; # Remplacement temporaire de la variable globale pour ce bloc et ses appels internes.
    print "Pendant dynamic_scope : x = $x\n";

    inner();
    print "Après appel interne dans dynamic_scope : x = $x\n";
}

sub inner {
    # Affiche la valeur de $x telle qu'elle est visible depuis ce contexte d'appel.
    print "  [inner] x = $x\n";
}

# Trace la valeur globale avant et après chaque démonstration de portée.
print "Valeur globale initiale : x = $x\n";

lexical_scope();
print "Après lexical_scope : x = $x\n";

dynamic_scope();
print "Après dynamic_scope : x = $x\n";
