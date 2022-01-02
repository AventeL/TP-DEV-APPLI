#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

#define TAILLE_MAX 80 //Taille max d'un nom dans la lecture depuis fichier
int IDcounter = 0;

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

Arbre creerNoeud(char *numero, char *nom, char *prenom)
{
    Arbre nouveau = (Arbre)malloc(sizeof(Noeud));
    if (nouveau)
    {
        nouveau->nom = malloc(sizeof(char) * 50);
        nouveau->prenom = malloc(sizeof(char) * 50);
        nouveau->numero = malloc(sizeof(char) * 50);

        nouveau->id = IDcounter;
        nouveau->numero = numero;
        nouveau->nom = nom;
        nouveau->prenom = prenom;
        nouveau->right = nouveau->left = NULL;
        IDcounter++;
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

Arbre inserer(Arbre * a, char *numero, char *nom, char *prenom)
{
    if ((*a) == NULL)
    {
        (*a) = creerNoeud(numero, nom, prenom);
    }
    else if (position(nom, (*a)->nom) == 0)
    {
        if ((*a)->left != NULL)
        {
            inserer(&(*a)->left, numero, nom, prenom);
        }
        else
        {
            (*a)->left = creerNoeud(numero, nom, prenom);
        }
    }
    else if (position(nom, (*a)->nom) == 1)
    {
        if ((*a)->right != NULL)
        {
            inserer(&(*a)->right, numero, nom, prenom);
        }
        else
        {
            (*a)->right = creerNoeud(numero, nom, prenom);
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
    else if (strcmp(a->nom, nom) == 0)
    {
        printf("\nResultat de la recherche:\n");
        afficherNoeud(a);
        printf("\n");
    }
    else if (position(nom, a->nom) == 0 && a->left != NULL)
    {
        return rechercherParNom(a->left, nom);
    }
    else if (position(nom, a->nom) == 1 && a->right != NULL)
    {
        return rechercherParNom(a->right, nom);
    }
    else
    {
        printf("\nResultat de la recherche:\n");
        printf("\nImpossible de trouver la donnee cherchee\n");
    }
}

void saisir(Arbre * a)
{
    char *nom = malloc(sizeof(char) * 50);
    char *prenom = malloc(sizeof(char) * 50);
    char *num = malloc(sizeof(char) * 10);

    printf("\nNom : ");
    scanf("%s", nom);
    printf("\nPrenom : ");
    scanf("%s", prenom);
    printf("\nNum telephone : ");
    scanf("%s", num);
    while (strlen(num) != 10)
    {
        printf("Numero Invalide");
        printf("\nNum telephone : ");
        scanf("%s", num);
    }
    inserer(a, num, nom, prenom);
}

void supprimerParNom(Arbre * a, char *nom)
{
    if (*a != NULL)
    {
        if(strcmp((*a)->nom, nom) == 0)
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
        }else{
            supprimerParNom(&(*a)->left, nom);
        }
    }
}

void ParseMaLigne(char * ligne, char ** array, int nbLignes){
    sscanf(ligne, "%49s %49s %49s[^\n]", array[0], array[1], array[2]);
}

void lire_fichier(Arbre * a){
    /*
        Order: Nom Prenom Numero
    */
    char * nomDuFichier = (char *) malloc (500 * sizeof(char));
    char * CheminFinal;
    size_t TailleCheminFinal;

    char * ligne = (char *) malloc (500 * sizeof(char));
    int nbLignes = 0, count = 0;


    printf("Saisir le nom du fichier (SANS L'EXTENSION) dans le repertoire data: ");
    scanf("%s", nomDuFichier);

    TailleCheminFinal = strlen("./data/") + strlen(nomDuFichier) + strlen(".txt") + 1;
    CheminFinal = (char *) malloc (TailleCheminFinal * sizeof(char));
    strcpy(CheminFinal, "./data/");
    strcat(CheminFinal, nomDuFichier);
    strcat(CheminFinal, ".txt");

    printf("\nSaisir le nombre de lignes du fichier: ");
    scanf("%d", &nbLignes);
    FILE *fichier = fopen (CheminFinal, "r");

    char ** array =(char **)malloc(nbLignes*sizeof(char *));
    for (int i=0;i<nbLignes;i++)
    {
        array[i]=(char*)malloc(3*sizeof(char));
    }

    while(fgets(ligne, TAILLE_MAX, fichier) != NULL && count < nbLignes){

        char ** array =(char **)malloc(nbLignes*sizeof(char *));
        for (int i=0;i<nbLignes;i++)
        {
            array[i]=(char*)malloc(3*sizeof(char));
        }

        ParseMaLigne(ligne, array, nbLignes);

        inserer(a, array[2], array[0], array[1]);

        count++;
    }
    fclose(fichier);
}

void ecrire_dans_fichier(Arbre a, char * Chemin)
{
    FILE *fichier = fopen (Chemin, "a+");

    if (a != NULL)
    {
        if (a->left != NULL)
        {
            fprintf(fichier,"%s %s %s\n",a->nom, a->prenom, a->numero);
            fclose(fichier);
            ecrire_dans_fichier(a->left, Chemin);
        }
        if (a->right != NULL)
        {
            fprintf(fichier,"%s %s %s\n",a->nom, a->prenom, a->numero);
            fclose(fichier);
            ecrire_dans_fichier(a->right, Chemin);
        }
        fprintf(fichier,"%s %s %s\n",a->nom, a->prenom, a->numero);
    }

    fclose(fichier);
}

void ecrire_fichier(Arbre a){
    char * nomDuFichier = (char *) malloc (500 * sizeof(char));
    char * CheminFinal = (char *) malloc (550 * sizeof(char));
    strcpy(CheminFinal, "./data/");

    printf("Saisir le nom du fichier de sortie (SANS L'EXTENSION): ");
    scanf("%s", nomDuFichier);
    strcat(nomDuFichier, ".txt");
    strcat(CheminFinal, nomDuFichier);
    free(nomDuFichier);

    ecrire_dans_fichier(a, CheminFinal);
    free(CheminFinal);
}
