//
// Created by hp on 14/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categorie.h"

Categorie ajoutcategorie(void){

    Categorie categorie;
    categorie.id=1;
    Categorie categorie0;
    FILE* fichierCategorie=NULL;
    fichierCategorie= fopen("CATEGORIES.txt","r");
    if (fichierCategorie!=NULL){

        while ( fscanf(fichierCategorie,"%d %s %s %s %f %d",&categorie0.id,&categorie0.codeCategorie,&categorie0.libelleCategorie,&categorie0.descriptionCategorie,&categorie0.montant,&categorie0.etatCategorie)!= EOF ){

            categorie.id=categorie0.id+1;
        }
        fclose(fichierCategorie);
    }




    fflush(stdin);
    printf("Entrer le libelle de la categorie : ");
    scanf("%s",&categorie.libelleCategorie);

    printf("\nEntrer la description de la categorie : ");
    scanf("%s",&categorie.descriptionCategorie);
    fflush(stdin);
    printf("\nEntrer le code de la categorie : ");
    scanf("%s",&categorie.codeCategorie);
    fflush(stdin);
    do {
        printf("\nEntrer l'etat de la categorie 1 (pour actif) et 0 (pour inactif): ");
        scanf("%d", &categorie.etatCategorie);
    } while (categorie.etatCategorie<0 || categorie.etatCategorie>1);
    do {
        printf("\nEntrer le montant de la categorie : ");
        scanf("%f",&categorie.montant);
    } while (categorie.montant<=0);
    return  categorie;
};

void ajoutCategorieFile(const char* nomfichier){
  Categorie categorie;
  FILE* fichierCategorie;

  fichierCategorie= fopen(nomfichier,"a");
    if (fichierCategorie!=NULL){
        categorie=ajoutcategorie();
        if(categorie.id<3){
            fprintf(fichierCategorie,"%d %s %s %s %f %d\n",categorie.id,categorie.codeCategorie,categorie.libelleCategorie,categorie.descriptionCategorie,categorie.montant,categorie.etatCategorie);
            fclose(fichierCategorie);
        } else{
            printf("\n ! ! ! Le nombre de categorie dans le fichier 'CATEGORIES.txt' est atteint\n");
        }

    } else{
        printf("Erreur d'ouverture");
    }

};

void listeCategorieFile(const char* nomfichier){

    Categorie categorie0;
    FILE* fichierCategorie;
    fichierCategorie= fopen(nomfichier,"r");
    if (fichierCategorie!=NULL){
        printf("\nListes des categories\n");
        printf("_____________________________________________________________________\n");
        printf("Id\tCode\tLibelle\tDescription\t\tMontant\t\tEtat\n");
        while ( fscanf(fichierCategorie,"%d %s %s %s %f %d",&categorie0.id,&categorie0.codeCategorie,&categorie0.libelleCategorie,&categorie0.descriptionCategorie,&categorie0.montant,&categorie0.etatCategorie)!= EOF ){
            printf("%d\t%s\t%s\t%s\t\t%f\t%d\n",categorie0.id,categorie0.codeCategorie,categorie0.libelleCategorie,categorie0.descriptionCategorie,categorie0.montant,categorie0.etatCategorie);

        }
        fclose(fichierCategorie);
    } else{
        printf("Erreur d'ouverture");
    }

};
void modifierCategorieFile(const char* nomfichier,char codecategorie[],char libelleCategorie[]){

    Categorie categorie;
    FILE* fichiercategorie;
    FILE* newfile;

    char mcode[20],mlibelle[20],mdescripion[30];
    int metat;
    float mmontant;

    fichiercategorie= fopen(nomfichier,"r");
    newfile=fopen("newfile.txt","a");

    if(fichiercategorie!=NULL){
        while(fscanf(fichiercategorie,"%d %s %s %s %f %d",&categorie.id,&categorie.codeCategorie,&categorie.libelleCategorie,&categorie.descriptionCategorie,&categorie.montant,&categorie.etatCategorie)!=EOF){

            if(strcmp(strupr(categorie.libelleCategorie),strupr(libelleCategorie))==0 && strcmp(strupr(categorie.codeCategorie),strupr(codecategorie))==0){
                printf("%d %s %s %s %f %d\n",categorie.id,categorie.codeCategorie,categorie.libelleCategorie,categorie.descriptionCategorie,categorie.montant,categorie.etatCategorie);
                printf("\nEntrer le libelle de la categorie : ");
                scanf("%s",&mlibelle);

                printf("\nEntrer la description de la categorie : ");
                scanf("%s",&mdescripion);
                fflush(stdin);
                printf("\nEntrer le code de la categorie : ");
                scanf("%s",&mcode);
                fflush(stdin);
                do {
                    printf("\nEntrer l'etat de la categorie 1 (pour actif) et 0 (pour inactif): ");
                    scanf("%d", &metat);
                } while (metat<0 || metat>1);
                do {
                    printf("\nEntrer le montant de la categorie : ");
                    scanf("%f",&mmontant);
                } while (mmontant<=0);

                fprintf(newfile,"%d %s %s %s %f %d\n",categorie.id,mcode,mlibelle,mdescripion,mmontant,metat);
            }else{
                fprintf(newfile,"%d %s %s %s %f %d\n",categorie.id,categorie.codeCategorie,categorie.libelleCategorie,categorie.descriptionCategorie,categorie.montant,categorie.etatCategorie);

            }
        }

    }
    fclose(newfile);
    fclose(fichiercategorie);
    remove(nomfichier);
    rename("newfile.txt",nomfichier);

};