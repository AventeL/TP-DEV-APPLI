#include "stdio.h"
#include "stdlib.h"
#include "arbre_binaire.h"

int main()
{
    Arbre a;
    a = creerNoeud(0, "6523458965", "AZERT", "ERTYUI");
    inserer(a, 1, "63875332", "Lumbly", "Alric");
    inserer(a, 2, "65307376", "Buttler", "Joline");
    inserer(a, 3, "66014531", "Le Provest", "Selma");
    inserer(a, 4, "61213009", "Lockley", "Gerek");
    inserer(a, 5, "64858296", "Orange", "Jo ann");
    inserer(a, 6, "62940528", "Schuster", "Myriam");
    inserer(a, 7, "65247491", "Valenta", "Karon");
    inserer(a, 8, "60311765", "Lealle", "Marie-jeanne");
    inserer(a, 9, "61033543", "Eyre", "Livia");

    rechercherParNom(a, "AZERT");
    //afficherArbre(a, 3);
    //supprimerParNom(&a, "Valenta");

    //printf("\naffichage\n");

    /* lire_fichier(a);
    ecrire_fichier(a); */

    /*afficherParOrdreCroissant(a);
    supprimerParNom(&a, "Eyre");
    afficherParOrdreCroissant(a);
    afficherArbre(a, 3);*/

    return 0;
}

