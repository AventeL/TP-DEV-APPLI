#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

typedef struct noeud
{
    int id;
    char *numero;
    char *nom;
    char *prenom;
    struct noeud *right;
    struct noeud *left;
} Noeud;

typedef Noeud *Arbre;

Arbre creerNoeud(int id, char *numero, char *nom, char *prenom)
{
    Arbre nouveau = (Arbre)malloc(sizeof(Noeud));
    if (nouveau)
    {
        nouveau->id = id;
        nouveau->numero = numero;
        nouveau->nom = nom;
        nouveau->prenom = prenom;
        nouveau->right = nouveau->left = NULL;
    }
    return nouveau;
}

void afficherParOrdreCroissant(Arbre a)
{
    if (a != NULL)
    {
        if (a->left != NULL)
        {
            afficherParOrdreCroissant(a->left);
        }
        printf("Id: %d\nNom: %s\nPrenom: %s\nnumero de telephone: %d\n\n", a->id, a->nom, a->prenom, a->numero);
        if (a->right != NULL)
        {
            afficherParOrdreCroissant(a->right);
        }
    }
}

void afficherParOrdreDecroissant(Arbre a)
{
    if (a != NULL)
    {
        if (a->right != NULL)
        {
            afficherParOrdreDecroissant(a->right);
        }
        printf("Id: %d\nNom: %s\nPrenom: %s\nnumero de telephone: %d\n\n", a->id, a->nom, a->prenom, a->numero);
        if (a->left != NULL)
        {
            afficherParOrdreDecroissant(a->left);
        }
    }
}

void afficherArbre(Arbre a, int nv)
{
    int i;
    if (a != NULL)
    {
        afficherArbre(a->right, nv + 1);

        for (i = 1; i <= nv; i++)
        {
            printf("  ");
        }
        printf("%d\n", a->id);
        afficherArbre(a->left, nv + 1);
    }
}

void afficherNoeud(Noeud *a)
{
    printf("\n Id : %d\nNom : %s\nPrenom : %s\nTelephone : %s", a->id, a->nom, a->prenom, a->numero);
}

int position(char *stringOne, char *stringTwo)
{
    int i = 0;
    //Renvoi 0 pour la gauche et 1 pour la droite
    if (strlen(stringOne) == strlen(stringTwo))
    {
        return -1;
    }
    while (toupper(stringOne[i]) == toupper(stringTwo[i]))
    {
        i = i + 1;
    }
    if (toupper(stringOne[i]) < toupper(stringTwo[i]))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

Arbre inserer(Arbre a, int id, char *numero, char *nom, char *prenom)
{
    if (a == NULL)
    {
        return creerNoeud(id, numero, nom, prenom);
    }
    else if (id < a->id)
    {
        if (a->left != NULL)
        {
            inserer(a->left, id, numero, nom, prenom);
        }
        else
        {
            a->left = creerNoeud(id, numero, nom, prenom);
        }
    }
    else if (id > a->id)
    {
        if (a->right != NULL)
        {
            inserer(a->right, id, numero, nom, prenom);
        }
        else
        {
            a->right = creerNoeud(id, numero, nom, prenom);
        }
    }
}

Arbre rechercherParId(Arbre a, int id)
{
    if (a == NULL)
    {
        return NULL;
    }
    else if (id < a->id)
    {
        return rechercherParId(a->left, id);
    }
    else if (id > a->id)
    {
        return rechercherParId(a->right, id);
    }
    else
        return a;
}

Arbre rechercherParNom(Arbre a, char *nom)
{
    if (a == NULL)
    {
        return NULL;
    }
    else if (nom < a->nom)
    {
        return rechercherParNom(a->left, nom);
    }
    else if (nom > a->nom)
    {

        return rechercherParNom(a->right, nom);
    }
    else
        return a;
}