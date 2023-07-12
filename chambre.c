//
// Created by hp on 14/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chambre.h"

Chambre ajoutchambre(void){
    int verif=0;
    char choix[30];
    Chambre chambre;
    Chambre chambre0;
    chambre.id=id_chambre();

        fflush(stdin);
        do {
            printf("\nEntrer le numero de telephone de la chambre : ");
            scanf("%d",&chambre.numTelephone);
        } while (chambre.numTelephone<=0);

        fflush(stdin);

        do {
            printf("\nEntrer l'etat de la chambre 1 (pour actif) et 0 (pour inactif): ");
            scanf("%d", &chambre.etatChambre);
        } while (chambre.etatChambre<0 || chambre.etatChambre>1);
        fflush(stdin);
        listeCategorieFile("CATEGORIES.txt");
        fflush(stdin);
    Categorie categorie;
    FILE* fichiercategorie=NULL;
    do {
        fflush(stdin);
        printf("\nEntrer le code de la categories choisies : ");
        scanf("%s",&choix);


        fichiercategorie= fopen("CATEGORIES.txt","r");
        if(fichiercategorie!=NULL){
            while(fscanf(fichiercategorie,"%d %s %s %s %f %d",&categorie.id,&categorie.codeCategorie,&categorie.libelleCategorie,&categorie.descriptionCategorie,&categorie.montant,&categorie.etatCategorie)!=EOF){
                if(strcmp(strupr(categorie.codeCategorie),strupr(choix))==0 && categorie.etatCategorie==0){
                    chambre.categorieChambre=categorie;
                    verif=1;
                }
            }
            if(verif==0){
                printf("\n! ! ! Cette categorie est indisponible");
            }

        } else{
            printf("\nErreur d'ouverture");
        }
    } while (verif!=1);
    fclose(fichiercategorie);
        sprintf(chambre.numChambre,"%s000%d",chambre.categorieChambre.libelleCategorie,chambre.id);

        return chambre;



};

//////////ajouter une chambre dans le fichiers CHAMBRES/////////////
void ajoutChambreFile(const char* nomfichier){
    Chambre chambre;
    FILE* fichierchambre;
    fichierchambre= fopen(nomfichier,"a");
    if(fichierchambre!=NULL){
        chambre=ajoutchambre();
        if(chambre.id>40){
            printf("\nLe nombre de chambre est atteint(soit 40 chambres)");
        } else{
            fprintf(fichierchambre,"%d %s %d %s %d %f\n",chambre.id,chambre.numChambre,chambre.numTelephone,chambre.categorieChambre.codeCategorie,chambre.etatChambre,chambre.categorieChambre.montant);
            fclose(fichierchambre);
        }
    }else{
        printf("\nErreur d'ouverture");
    }
};

////////// liste des chambres dans le fichiers CHAMBRES/////////////
void listeChambreFile(const char* nomfichier){
    Chambre chambre0;
    FILE* fichierchambre;
    fichierchambre= fopen(nomfichier,"r");
    if(fichierchambre!=NULL){
        printf("\nListes des chambres\n");
        printf("Id\tNumChambre\tNumTelephone\tCodeCategorieChambre\tEtatChambre\tmontant_chambre\n");
        while (fscanf(fichierchambre,"%d %s %d %s %d %f",&chambre0.id,&chambre0.numChambre,&chambre0.numTelephone,&chambre0.categorieChambre.codeCategorie,&chambre0.etatChambre,&chambre0.categorieChambre.montant)!=EOF){
            printf("%d\t%s\t%d\t%s\t\t\t%d\t\t%f\n",chambre0.id,chambre0.numChambre,chambre0.numTelephone,chambre0.categorieChambre.codeCategorie,chambre0.etatChambre,chambre0.categorieChambre.montant);
        }
        fclose(fichierchambre);
    } else{
        printf("\nErreur d'ouverture");
    }
};

////////// Modifications dans le fichier CHAMBRES/////////////
void modifierChambreFile(const char* nomfichier,char numeroChambre[]){
    Chambre chambre;
    FILE* fichierchambre;
    FILE* newfile;

    char mnumChambre[20];
    int metatChambre,mnumtelephone;
    char choix[30];


    fichierchambre= fopen(nomfichier,"r");
    newfile=fopen("newfile.txt","a");

    if(fichierchambre!=NULL){
        while(fscanf(fichierchambre,"%d %s %d %s %d %f",&chambre.id,&chambre.numChambre,&chambre.numTelephone,&chambre.categorieChambre.codeCategorie,&chambre.etatChambre,&chambre.categorieChambre.montant)!=EOF){

            if(strcmp(strupr(chambre.numChambre),strupr(numeroChambre))==0 ){
                printf("%d %s %d %s %d %f\n",chambre.id,chambre.numChambre,chambre.numTelephone,chambre.categorieChambre.codeCategorie,chambre.etatChambre,chambre.categorieChambre.montant);
                fflush(stdin);
                do {
                    printf("\nEntrer le numero de telephone de la chambre : ");
                    scanf("%d",&mnumtelephone);
                } while (mnumtelephone<=0);

                fflush(stdin);

                do {
                    printf("\nEntrer l'etat de la chambre 1 (pour actif) et 0 (pour inactif): ");
                    scanf("%d", &metatChambre);
                } while (metatChambre<0 || metatChambre>1);
                fflush(stdin);
                listeCategorieFile("CATEGORIES.txt");
                fflush(stdin);
                printf("\nEntrer le code de la categories choisies : ");
                scanf("%s",&choix);
                fflush(stdin);
                Categorie categorie,mcodeCategorie;
                FILE* fichiercategorie=NULL;
                fichiercategorie= fopen("CATEGORIES.txt","r");
                if(fichiercategorie!=NULL){
                    while(fscanf(fichiercategorie,"%d %s %s %s %f %d",&categorie.id,&categorie.codeCategorie,&categorie.libelleCategorie,&categorie.descriptionCategorie,&categorie.montant,&categorie.etatCategorie)!=EOF){
                        if(strcmp(strupr(categorie.codeCategorie),strupr(choix))==0){
                            mcodeCategorie=categorie;
                        }
                    }
                    fclose(fichiercategorie);
                } else{
                    printf("\nErreur d'ouverture");
                }
                sprintf(mnumChambre,"%s000%d",mcodeCategorie.libelleCategorie,chambre.id);

                fprintf(newfile,"%d %s %d %s %d\n",chambre.id,mnumChambre,mnumtelephone,mcodeCategorie.codeCategorie,metatChambre);
            }else{
                fprintf(newfile,"%d %s %d %s %d\n",chambre.id,chambre.numChambre,chambre.numTelephone,chambre.categorieChambre.codeCategorie,chambre.etatChambre);

            }
        }

    }
    fclose(newfile);
    fclose(fichierchambre);
    remove(nomfichier);
    rename("newfile.txt",nomfichier);
};

////////// Liste des chambres disponibe dans le fichier CHAMBRES/////////////
void listeChambreDisponibleFile(const char* nomfichier){
    Chambre chambre;
    int verif=0;
    FILE* fichierchambre;
    fichierchambre= fopen(nomfichier,"r");
    if(fichierchambre!=NULL){
        printf("\nListes des chambres Disponibles\n");
        printf("_______________________________________________________________________________________________________\n");
        printf("Id\tNumChambre\tNumTelephone\tCodeCategorieChambre\tEtatChambre\tMontantChambre\n");
        while (fscanf(fichierchambre,"%d %s %d %s %d %f",&chambre.id,&chambre.numChambre,&chambre.numTelephone,&chambre.categorieChambre.codeCategorie,&chambre.etatChambre,&chambre.categorieChambre.montant)!=EOF) {
            if (chambre.etatChambre == 0) {
                printf("%d\t%s\t%d\t%s\t\t\t%d\t\t%f\n", chambre.id, chambre.numChambre, chambre.numTelephone,
                       chambre.categorieChambre.codeCategorie, chambre.etatChambre,chambre.categorieChambre.montant);
                verif++;
            }
        }
        fclose(fichierchambre);
    } else{
        printf("\nErreur d'ouverture");
    }

};

////////// Rendre chambre disponible dans le fichier CHAMBRES/////////////
void rendreChambreDisponible(const char* nomfichier,char numeroChambre[]){
    Chambre chambre;
    FILE* fichierchambre;
    FILE* newfile;


    int metatChambre;



    fichierchambre= fopen(nomfichier,"r");
    newfile=fopen("newfile.txt","a");

    if(fichierchambre!=NULL){
        while(fscanf(fichierchambre,"%d %s %d %s %d %f",&chambre.id,&chambre.numChambre,&chambre.numTelephone,&chambre.categorieChambre.codeCategorie,&chambre.etatChambre,&chambre.categorieChambre.montant)!=EOF){

            if(strcmp(strupr(chambre.numChambre),strupr(numeroChambre))==0 ){
                printf("%d %s %d %s %d %f\n",chambre.id,chambre.numChambre,chambre.numTelephone,chambre.categorieChambre.codeCategorie,chambre.etatChambre,chambre.categorieChambre.montant);

                fflush(stdin);

                do {
                    printf("\nEntrer l'etat de la chambre 1 (pour Indisponible) et 0 (pour Disponible): ");
                    scanf("%d", &metatChambre);
                } while (metatChambre<0 || metatChambre>1);


                fprintf(newfile,"%d %s %d %s %d %f\n",chambre.id,chambre.numChambre,chambre.numTelephone,chambre.categorieChambre.codeCategorie,metatChambre,chambre.categorieChambre.montant);
            }else{
                fprintf(newfile,"%d %s %d %s %d %f\n",chambre.id,chambre.numChambre,chambre.numTelephone,chambre.categorieChambre.codeCategorie,chambre.etatChambre,chambre.categorieChambre.montant);

            }
        }

    }
    fclose(newfile);
    fclose(fichierchambre);
    remove(nomfichier);
    rename("newfile.txt",nomfichier);
};

////////// Etat chambre apres reservation/////////////
void etat_chambreapres_reservation(const char* nomfichier,char numeroChambre[]){
    Chambre chambre;
    FILE* fichierchambre;
    FILE* newfile;


    int metatChambre=1;



    fichierchambre= fopen(nomfichier,"r");
    newfile=fopen("newfile.txt","a");

    if(fichierchambre!=NULL){
        while(fscanf(fichierchambre,"%d %s %d %s %d %f",&chambre.id,&chambre.numChambre,&chambre.numTelephone,&chambre.categorieChambre.codeCategorie,&chambre.etatChambre,&chambre.categorieChambre.montant)!=EOF){

            if(strcmp(strupr(chambre.numChambre),strupr(numeroChambre))==0 ){
                printf("%d %s %d %s %d %f\n",chambre.id,chambre.numChambre,chambre.numTelephone,chambre.categorieChambre.codeCategorie,chambre.etatChambre,chambre.categorieChambre.montant);

                fflush(stdin);

                fprintf(newfile,"%d %s %d %s %d %f\n",chambre.id,chambre.numChambre,chambre.numTelephone,chambre.categorieChambre.codeCategorie,metatChambre,chambre.categorieChambre.montant);
            }else{
                fprintf(newfile,"%d %s %d %s %d %f\n",chambre.id,chambre.numChambre,chambre.numTelephone,chambre.categorieChambre.codeCategorie,chambre.etatChambre,chambre.categorieChambre.montant);

            }
        }

    }
    fclose(newfile);
    fclose(fichierchambre);
    remove(nomfichier);
    rename("newfile.txt",nomfichier);
};
////////////// id chambre //////////////////////
int id_chambre(void){
  int id=1;
  Chambre chambre0;
    FILE* fichierchambre=NULL;
    fichierchambre= fopen("CHAMBRES.txt","r");
    if(fichierchambre!=NULL){

        while (fscanf(fichierchambre,"%d %s %d %s %d %f",&chambre0.id,&chambre0.numChambre,&chambre0.numTelephone,&chambre0.categorieChambre.codeCategorie,&chambre0.etatChambre,&chambre0.categorieChambre.montant)!=EOF){
            id=chambre0.id+1;
        }
        fclose(fichierchambre);
    }
    return id;
};