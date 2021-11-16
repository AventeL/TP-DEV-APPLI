#include "stdio.h"
#include "stdlib.h"
#include "arbre_binaire.c"

void main()
{
    Arbre a;
    a = creerNoeud(4, 23452, "Nom", "Prenom");
    a->left = creerNoeud(2, 2345632, "Fils", "GAUCHE");
    a->right = creerNoeud(5, 2345632, "Fils", "Droit");
    a->right->right = creerNoeud(8, 3453, "Fils droit", "droit");
    a->right->right->left = creerNoeud(7, 2345632, "Fils", "Droitgauche");
    a->right->right->right = creerNoeud(9, 2345632, "Fils", "Droitgauche");
    a->left->left = creerNoeud(1, 2345632, "Fils", "gauchegauche");
    a->left->right = creerNoeud(3, 2345632, "Fils", "gauchedroite");

    afficherArbre(a, 4);
}