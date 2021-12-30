#include "stdio.h"
#include "stdlib.h"
#include "arbre_binaire.h"

int main()
{
    Arbre a = NULL;

    //saisir(&a);
    inserer(&a, "0654235986", "Testeur2", "Testeur2");
    //rechercherParNom(a, "Testeur");
    lire_fichier(&a);
    //inserer(&a, "0654235988", "Testeur", "Testeur");
    supprimerParNom(&a, "test5");

    //afficherParOrdreCroissant(a);
    //afficherArbre(a, 3);
    //afficherParOrdreDecroissant(a);
    //ecrire_fichier(a);

    return 0;
}

