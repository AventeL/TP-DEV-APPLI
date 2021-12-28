#include "arbre_binaire.c"

void afficherParOrdreCroissant(Arbre a);

void afficherParOrdreDecroissant(Arbre a);

void afficherArbre(Arbre a, int nv);

void afficherNoeud(Noeud *a);

int position(char *stringOne, char *stringTwo);

Arbre inserer(Arbre a, char *numero, char *nom, char *prenom);

Arbre insererNoeud(Arbre a, Arbre n);

void rechercherParNom(Arbre a, char *nom);

void saisir(Arbre a);

void supprimerParNom(Noeud **a, char *nom);

void ParseMaLigne(char * ligne, char ** array, int nbLignes);

void lire_fichier(Arbre a);

void ecrire_dans_fichier(Arbre a, char * Chemin);

void ecrire_fichier(Arbre a);
