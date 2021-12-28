#include "stdio.h"
#include "stdlib.h"
#include "arbre_binaire.h"

int main()
{
    Arbre a;
    a = creerNoeud("6523458965", "AZERT", "ERTYUI");
    /*inserer(a, "63875332", "Lumbly", "Alric");
    inserer(a, "65307376", "Buttler", "Joline");
    inserer(a, "66014531", "Le Provest", "Selma");
    inserer(a, "61213009", "Lockley", "Gerek");
    inserer(a, "64858296", "Orange", "Jo ann");
    inserer(a, "62940528", "Schuster", "Myriam");
    inserer(a, "65247491", "Valenta", "Karon");
    inserer(a, "60311765", "Lealle", "Marie-jeanne");
    inserer(a, "61033543", "Eyre", "Livia");*/
    lire_fichier(a);
    afficherArbre(a, 3);

    /*rechercherParNom(a, "AZERT");
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

