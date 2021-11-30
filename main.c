#include "stdio.h"
#include "stdlib.h"
#include "arbre_binaire.c"

void main()
{
    int i;
    Arbre a;
    Arbre b;
    a = creerNoeud(1, "33787237887", "Jean", "Paul");
    inserer(a, 2, "33673846736", "Alexis", "BCD");
    inserer(a, 4, "33673946736", "Loic", "Bernier");
    inserer(a, 3, "33653546536", "Mathis", "Blr");
    inserer(a, 5, "33653906536", "Al", "ale");
    afficherNoeud(rechercherParNom(a, "Alexis"));
}