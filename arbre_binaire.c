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

Arbre creerNoeud(int id, int numero, char *nom, char *prenom) {
    Arbre nouveau = (Arbre) malloc(sizeof(Noeud));
    if (nouveau) {
        nouveau->id = id;
        nouveau->numero = numero;
        nouveau->nom = nom;
        nouveau->prenom = prenom;
        nouveau->right = nouveau->left = NULL;
    }
    return nouveau;
}

Arbre inserer(int id, int numero, char *nom, char *prenom, Arbre a){

}
