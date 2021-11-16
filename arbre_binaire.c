#include "stdio.h"
#include "stdlib.h"

typedef struct noeud{
    int id;
    int numero;
    char *nom;
    char *prenom;
    struct noeud *right;
    struct noeud *left;
}Noeud;

typedef Noeud * Arbre;
