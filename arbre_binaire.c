#include "stdio.h"
#include "stdlib.h"

typedef struct noeud{
    int id;
    int numero;
    struct noeud *right;
    struct noeud *left;
}Noeud;

typedef Noeud * Arbre


//test