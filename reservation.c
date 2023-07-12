//
// Created by hp on 22/07/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "reservation.h"

///////////// Ajout reservation ///////////////
void ajout_reservation_dans_file(Utilisateur utilisateur,int jj,int mm,int aaaa,int hh,int mn,int ss){
    Reservation reservation;
    reservation.idreservation = id_reservations();
    reservation.loginUtilisateurReserve = utilisateur;
    int choix,choix2,cptchoix2=0,cptsortie=0;
    float montantprestation=0;
    char choixprestation[30];
    //////////// Choix de la chambre ///////////////////
    listeChambreDisponibleFile("CHAMBRES.txt");
    printf("\n");
    do {
        printf("Saisir l'ID de la chambre choisie : ");
        scanf("%d",&choix);
    } while (choix<=0 || choix>5);
    Chambre chambre;
    FILE* fichierchambre;
    fichierchambre= fopen("CHAMBRES.txt","r");
    if(fichierchambre!=NULL){

        while (fscanf(fichierchambre,"%d %s %d %s %d %f",&chambre.id,&chambre.numChambre,&chambre.numTelephone,&chambre.categorieChambre.codeCategorie,&chambre.etatChambre,&chambre.categorieChambre.montant)!=EOF) {
            if (chambre.etatChambre == 0 && chambre.id==choix) {
               reservation.chambreReserve=chambre;
               reservation.chambreReserve.categorieChambre.montant=chambre.categorieChambre.montant;
            }
        }
        fclose(fichierchambre);
        etat_chambreapres_reservation("CHAMBRES.txt",reservation.chambreReserve.numChambre);
    }
    //////////// Prestations ///////////////

    do {
        do {
            printf("\nVoulez-vous faire une prestation(ou en ajouter) : ");
            printf("\n1-OUI");
            printf("\n2-NON");
            printf("\nSaisir le choix : ");
            scanf("%d",&choix2);
        } while (choix2<1 || choix2>2);
        if(choix2==1){
            liste_des_prestation_dans_file("PRESTATIONS.txt");
            printf("\nEntrer le code de la prestation choisie : ");
            scanf("%s",&choixprestation);

            FILE* fichierprestation;
            Prestation prestation;
            fichierprestation= fopen("PRESTATIONS.txt","r");
            if(fichierprestation!=NULL){

                while (fscanf(fichierprestation,"%s %s %f",&prestation.codePrestation,&prestation.designationPrestation,&prestation.montant)!=EOF){
                   if(strcmp(strupr(prestation.codePrestation), strupr(choixprestation))==0){
                       reservation.prestationReserve[cptchoix2]=prestation;
                       montantprestation=montantprestation+reservation.prestationReserve[cptchoix2].montant;
                       cptchoix2++;
                   }
                }
                fclose(fichierprestation);
            }
        }
        if(choix2==2 || cptchoix2==3){
            cptsortie=1;
        }

    } while (cptsortie!=1);
//    printf("\nmontant prestation = %f",montantprestation);
//    printf("\nnumero chambre : %s",reservation.chambreReserve.numChambre);

   ///// Montant reservation /////////////////
    fflush(stdin);
   reservation.montantreservation = montantprestation+reservation.chambreReserve.categorieChambre.montant;
    fflush(stdin);
   ////////////// donnees du client qui a reserve ////////////
   reservation.clientReserve = ajout_client();
    FILE* fichierclient;
    fichierclient= fopen("CUSTOMERS.txt","a");
    if(fichierclient!=NULL){

        fprintf(fichierclient,"%s %s %s %d\n",reservation.clientReserve.prenomClient,reservation.clientReserve.nomClient,reservation.clientReserve.adresseClient,reservation.clientReserve.telephoneClient);
        fclose(fichierclient);
    } else{
        printf("\nErreur d'ouverture");
    }

    /////////////// Date system(numero reservation) ///////////////

    sprintf(reservation.numeroReservation,"%d_%d_%d_%d_%d_%d",aaaa,mm,jj,hh,mn,ss);
    fflush(stdin);
    printf("\nnumero reservation : %s",reservation.numeroReservation);
    printf("\n%f + %f = %f",montantprestation,reservation.chambreReserve.categorieChambre.montant,reservation.montantreservation);

    //////////// Ajout reservation dans fichiers RESERVATIONS ////////////
    FILE *fichierreservation=NULL;
    fichierreservation= fopen("RESERVATIONS.txt","a");
    if(fichierreservation!=NULL){
        fprintf(fichierreservation,"%d %s %s %f %d %s %s %s\n",reservation.idreservation,reservation.numeroReservation,reservation.chambreReserve.numChambre,reservation.montantreservation,cptchoix2,reservation.loginUtilisateurReserve.loginUtilisateur,reservation.clientReserve.prenomClient,reservation.clientReserve.nomClient);
        fclose(fichierreservation);
    }

    ////////////// Ajout recu dans dossiers RESERVATIONS ////////////////
    char nomrecu[50];
    sprintf(nomrecu,"RESERVATIONS/RECU_%d%d%d%d%d%d_%d_%s.txt",aaaa,mm,jj,hh,mn,ss,reservation.idreservation,reservation.loginUtilisateurReserve.loginUtilisateur);
    FILE *fichierreservation2=NULL;
    fichierreservation2= fopen(nomrecu,"a");
    if(fichierreservation2!=NULL){
        fprintf(fichierreservation2,"ID recu : %d\nNumero reservation : %s\n\nCode chambre reservee : %s\nMontant total de la reservation : %f\nNombre de prestation : %d\nLogin utilisateur : %s\nPrenom client : %s\nNom client : %s",reservation.idreservation,reservation.numeroReservation,reservation.chambreReserve.numChambre,reservation.montantreservation,cptchoix2,reservation.loginUtilisateurReserve.loginUtilisateur,reservation.clientReserve.prenomClient,reservation.clientReserve.nomClient);
        fclose(fichierreservation2);
    }

};

////////// ID RESERVATION///////////////
int id_reservations(void){
    int id=1,cptchoix2;
    Reservation reservation;
    FILE *fichierreservation=NULL;
    fichierreservation= fopen("RESERVATIONS.txt","r");
    if(fichierreservation!=NULL){
        while (fscanf(fichierreservation,"%d %s %s %f %d %s %s %s",&reservation.idreservation,&reservation.numeroReservation,&reservation.chambreReserve.numChambre,&reservation.montantreservation,&cptchoix2,&reservation.loginUtilisateurReserve.loginUtilisateur,&reservation.clientReserve.prenomClient,&reservation.clientReserve.nomClient)!=EOF){
            id=reservation.idreservation+1;
        }
        fclose(fichierreservation);
    }
    return id;
};

////////////// Liste des reservations en cours //////////////////////
void liste_des_reservations_en_cours(void ){
  FILE* fichierreservation=NULL;
  Reservation reservation;
  int cptchoix2;
  fichierreservation= fopen("RESERVATIONS.txt","r");
  if(fichierreservation!=NULL){
      printf("Liste des reservation en cours\n");

      while (fscanf(fichierreservation,"%d %s %s %f %d %s %s %s",&reservation.idreservation,&reservation.numeroReservation,&reservation.chambreReserve.numChambre,&reservation.montantreservation,&cptchoix2,&reservation.loginUtilisateurReserve.loginUtilisateur,&reservation.clientReserve.prenomClient,&reservation.clientReserve.nomClient)!=EOF){
          printf("%d %s %s %f %d %s %s %s\n",reservation.idreservation,reservation.numeroReservation,reservation.chambreReserve.numChambre,reservation.montantreservation,cptchoix2,reservation.loginUtilisateurReserve.loginUtilisateur,reservation.clientReserve.prenomClient,reservation.clientReserve.nomClient);
      }
      fclose(fichierreservation);
  }
};

////////////// filtrage par date /////////////
void etat_date(void){
    FILE* fichierreservation=NULL;
    Reservation reservation;
    int cptchoix2;
    fichierreservation= fopen("RESERVATIONS.txt","r");
    if(fichierreservation!=NULL){
        printf("Filtrage par Date\n");

        while (fscanf(fichierreservation,"%d %s %s %f %d %s %s %s",&reservation.idreservation,&reservation.numeroReservation,&reservation.chambreReserve.numChambre,&reservation.montantreservation,&cptchoix2,&reservation.loginUtilisateurReserve.loginUtilisateur,&reservation.clientReserve.prenomClient,&reservation.clientReserve.nomClient)!=EOF){
            printf("%s %d %s %f %d %s %s %s\n",reservation.numeroReservation,reservation.idreservation,reservation.chambreReserve.numChambre,reservation.montantreservation,cptchoix2,reservation.loginUtilisateurReserve.loginUtilisateur,reservation.clientReserve.prenomClient,reservation.clientReserve.nomClient);
        }
        fclose(fichierreservation);
    }
};