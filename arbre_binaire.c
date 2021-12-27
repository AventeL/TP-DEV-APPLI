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
        nouveau->nom = malloc(sizeof(char) * 50);
        nouveau->prenom = malloc(sizeof(char) * 50);
        nouveau->numero = malloc(sizeof(char) * 50);

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
        printf("Id: %d\nNom: %s\nPrenom: %s\nnumero de telephone: %s\n\n", a->id, a->nom, a->prenom, a->numero);
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
        printf("Id: %d\nNom: %s\nPrenom: %s\nnumero de telephone: %s\n\n", a->id, a->nom, a->prenom, a->numero);
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
    printf("\nId : %d\nNom : %s\nPrenom : %s\nTelephone : %s", a->id, a->nom, a->prenom, a->numero);
}

int position(char *stringOne, char *stringTwo)
{
    int i = 0;
    //Renvoi 0 pour la gauche et 1 pour la droite
    while (toupper(stringOne[i]) == toupper(stringTwo[i]) && (toupper(stringOne[i + 1]) != '\0') && (toupper(stringTwo[i + 1]) != '\0'))
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
    else if (position(nom, a->nom) == 0)
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
    else if (position(nom, a->nom) == 1)
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

Arbre insererNoeud(Arbre a, Arbre n)
{
    if (a == NULL)
    {

    }
    else if (position(n->nom, a->nom) == 0)
    {
        if (a->left != NULL)
        {
            insererNoeud(a->left, n);
        }
        else
        {
            a->left = n;
        }
    }
    else if (position(n->nom, a->nom) == 1)
    {
        if (a->right != NULL)
        {
            insererNoeud(a->right, n);
        }
        else
        {
            a->right = n;
        }
    }
}

void rechercherParNom(Arbre a, char *nom)
{
    if (a == NULL)
    {
        printf("\nPas de donnees dans l'arbre.\n");
    }
    else if (a->nom == nom)
    {
        printf("\nResultat de la recherche:\n");
        afficherNoeud(a);
        printf("\n");
    }
    else if (nom < a->nom && a->left != NULL)
    {
        return rechercherParNom(a->left, nom);
    }
    else if (nom > a->nom && a->right != NULL)
    {
        return rechercherParNom(a->right, nom);
    }
    else
    {
        printf("\nResultat de la recherche:\n");
        printf("\nImpossible de trouver la donnee cherchee\n");
    }
}

void saisir(Arbre a)
{
    int id;
    char *nom = malloc(sizeof(char) * 50);
    char *prenom = malloc(sizeof(char) * 50);
    char *num = malloc(sizeof(char) * 10);

    printf("\nId : ");
    scanf("%d", &id);
    printf("\nNom : ");
    scanf("%s", nom);
    printf("\nPrenom : ");
    scanf("%s", prenom);
    printf("\nNum telephone : ");
    scanf("%s", num);
    while (strlen(num) != 10)
    {
        printf("Numéro Invalide");
        printf("\nNum téléphone : ");
        scanf("%s", num);
    }
    inserer(a, id, num, nom, prenom);
}

void supprimerParNom(Noeud **a, char *nom)
{
    if (*a != NULL)
    {
        if ((*a)->nom == nom)
        {
            if((*a)->left == NULL && (*a)->right == NULL){
                free(*a);
                (*a) = NULL;
            }
            else if((*a)->left == NULL){
                Noeud *temp = (*a)->right;
                free(*a);
                (*a) = temp;
            }
            else if((*a)->right == NULL){
                Noeud *temp = (*a)->left;
                free(*a);
                (*a) = temp;
            }
            else{
                Arbre gauche = (*a)->left;
                Arbre droite = (*a)->right;
                (*a) = droite;
                insererNoeud((*a), gauche);
            }
        }else if(position((*a)->nom, nom) == 0){
            supprimerParNom(&(*a)->right, nom);
        }else supprimerParNom(&(*a)->left, nom);
    }
}
