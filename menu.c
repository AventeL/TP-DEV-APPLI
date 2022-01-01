#include "stdio.h"
#include "stdlib.h"
#include "arbre_binaire.h"


void menu(){
    int choix;
    char *nom;
    Arbre a = NULL;
    do{
            printf("\nMenu\n------- \n");
            printf("1.Ajouter\n2.Supprimer\n3.Afficher\n4.Rechercher\n5.Quitter\n");
            scanf("%d",&choix);
            switch(choix){
            case 1 :
                    system("cls");
                    printf("\nSous-menu\n-------- \n");
                    printf("1.Ajout par clavier\n2.Ajout par fichier\n3.Retour\n");
                    scanf("%d",&choix);
                    switch(choix){
                    case 1 : //inserer clavier
                        system("cls");
                        saisir(&a);
                        break;
                    case 2 : //inserer fichier
                        system("cls");
                        lire_fichier(&a);
                        break;
                    case 3 : //retour
                        system("cls");
                        break;
                        default : printf("Il faut saisir un choix entre 1 et 3");
                    }
                break;
            case 2 : //Supprimer
                printf("Saisir le nom de la personne que vous souhaitez supprimer : ");
                scanf("%s",&nom);
                supprimerParNom(&a,nom);
                break;
            case 3 : //Afficher
                    system("cls");
                    printf("\nSous-menu\n-------- \n");
                    printf("1.Afficher par Ordre croissant\n2.Afficher par ordre decroissant\n3.Retour\n");
                    scanf("%d",&choix);
                switch(choix){
                case 1 : //Afficher par Ordre croissant
                    system("cls");
                    afficherParOrdreCroissant(a);
                    break;
                case 2 : //Afficher par ordre decroissant
                    system("cls");
                    afficherParOrdreDecroissant(a);
                    break;
                case 3 : //Retour
                    break;
                    default : printf("Il faut saisir un choix entre 1 et 3");
                    }
                break;
            case 4 : //Rechercher
                system("cls");
                printf("Saisir le nom de la personne que vous souhaitez rechercher : ");
                scanf("%s",&nom);
                rechercherParNom(a, nom);
                break;
            case 5 : //Quitter
                break;
            default: printf("Il faut saisir un choix entre 1 et 5");
                break;
            }
        } while(choix != 5);
    }
