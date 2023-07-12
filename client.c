//
// Created by hp on 21/07/2022.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"

////////////// Saisi donnees client ////////////
Client ajout_client(void ){
    Client client;
    printf("\nSaisi donnees client");
    printf("\n_______________________\n\n");
    printf("Saisir le prenom du client : ");
    scanf("%s",&client.prenomClient);
    printf("\nSaisir le nom du client : ");
    scanf("%s",&client.nomClient);
    printf("\nSaisir l'adresse du client : ");
    scanf("%s",&client.adresseClient);
    do {
        printf("\nSaisir le numero de telephone du client : ");
        scanf("%d",&client.telephoneClient);
    } while (client.telephoneClient<=0);
    return client;
};


//////////////liste des clients reserves dans file//////////////
void liste_des_clientsreserves(const char *nomfichier){
    FILE* fichierclient;
    Client client;
    fichierclient= fopen(nomfichier,"r");
    if(fichierclient!=NULL){
        printf("Liste des clients qui ont reserves : \n");
        printf("__________________________________________\n");
        printf("Prenom\tNom\tAdresse\t\tTelephone\n");
        while (fscanf(fichierclient,"%s %s %s %d",&client.prenomClient,&client.nomClient,&client.adresseClient,&client.telephoneClient)!=EOF){
            printf("%s\t%s\t%s\t%d\n",client.prenomClient,client.nomClient,client.adresseClient,client.telephoneClient);
        }


        fclose(fichierclient);
    } else{
        printf("\nErreur d'ouverture");
    }
};