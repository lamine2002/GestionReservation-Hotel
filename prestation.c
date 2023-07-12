//
// Created by hp on 21/07/2022.
//
#include "prestation.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//////////////////Ajout prestation dans file//////////////////////
void ajout_prestation_dans_file(const char* nomfichier){
    Prestation prestation;
    printf("Saisi donnees prestation : \n");
    printf("______________________________________________\n");
    printf("Saisir le code de la prestation : ");
    scanf("%s",&prestation.codePrestation);
    printf("\nSaisir la designation de la prestation : ");
    scanf("%s",&prestation.designationPrestation);
    fflush(stdin);
    do {
        printf("\nSaisir le montant de la prestation : ");
        scanf("%f",&prestation.montant);
    } while (prestation.montant<=0);
    FILE* fichierprestation;
    fichierprestation= fopen(nomfichier,"a");
    if(fichierprestation!=NULL){
        fprintf(fichierprestation,"%s %s %f\n",prestation.codePrestation,prestation.designationPrestation,prestation.montant);
        fclose(fichierprestation);
    } else{
        printf("\nErreur d'ouverture du fichier prestation");
    }
};

///////////////Liste des prestations dans file///////////////
void liste_des_prestation_dans_file(const char *nomfichier){
    FILE* fichierprestation;
    Prestation prestation;
    fichierprestation= fopen(nomfichier,"r");
    if(fichierprestation!=NULL){
        printf("Affichage donnees prestation : \n");
        printf("________________________________________________________\n");
        printf("Code\t\tDesignation\tMontant\n");
        while (fscanf(fichierprestation,"%s %s %f",&prestation.codePrestation,&prestation.designationPrestation,&prestation.montant)!=EOF){
            printf("%s\t%s\t\t%f\n",prestation.codePrestation,prestation.designationPrestation,prestation.montant);
        }
        fclose(fichierprestation);
    } else{
        printf("\nErreur d'ouverture du fichier prestation");
    }
};