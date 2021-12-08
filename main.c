#include "stdio.h"
#include "stdlib.h"
#include "arbre_binaire.c"

void main()
{
    Arbre a = NULL;
    a = inserer(a, 2, "0627394830", "dsqdfds", "ooyo");
    a = saisir(a);
    afficherParOrdreCroissant(a);
}