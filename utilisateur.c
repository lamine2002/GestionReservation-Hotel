//
// Created by hp on 15/07/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "utilisateur.h"

/////////// Ajout utilisateur////////////////
Utilisateur ajout_utilisateur(){
    Utilisateur utilisateur;
    int i,j=0;
    utilisateur.id=id_utilisateur();

    printf("Saisir le prenom de l'utilisateur : ");
    scanf("%s",&utilisateur.prenomUtilisateur);
    printf("\nSaisir le nom de l'utilisateur : ");
    scanf("%s",&utilisateur.nomUtilisateur);

    do {
        printf("\nSaisir le numero de telephone de l'utilisateur : ");
        scanf("%d",&utilisateur.telephoneUtilisateur);
    } while (utilisateur.telephoneUtilisateur<=0);

    for ( i = 0; i <3 ; i++) {
        utilisateur.loginUtilisateur[i]= toupper(utilisateur.prenomUtilisateur[i]);
    }
    for ( i = 3; i <5 ; i++) {
        utilisateur.loginUtilisateur[i]= toupper(utilisateur.nomUtilisateur[j]);
        j++;
    }
    fflush(stdin);
    sprintf(utilisateur.passwordUtilisateur,"passerbdd");
    sprintf(utilisateur.emailUtilisateur,"%c%c2022@boulakodaradiaral.sn", tolower(utilisateur.nomUtilisateur[0]),
            tolower(utilisateur.nomUtilisateur[strlen(utilisateur.nomUtilisateur)-1]));

    return utilisateur;
};


/////////// Ajout utilisateur dans fichier////////////////
void ajout_utilisateur_dans_file(const char* nomfichier){
    Utilisateur utilisateur1;

    FILE* fichierutilisateur=NULL;
    fichierutilisateur= fopen(nomfichier,"a");
    if(fichierutilisateur!=NULL){
        utilisateur1=ajout_utilisateur();
        fprintf(fichierutilisateur,"%d %s %s %d %s %s %s\n",utilisateur1.id,utilisateur1.prenomUtilisateur,utilisateur1.nomUtilisateur,utilisateur1.telephoneUtilisateur,utilisateur1.emailUtilisateur,utilisateur1.loginUtilisateur,utilisateur1.passwordUtilisateur);
        fclose(fichierutilisateur);
    } else{
        printf("\nErreur d'ouverture");
    }
};

/////////// Liste des utilisateurs dans fichier////////////////
void liste_des_utilisateurs_dans_file(const char* nomfichier){
    Utilisateur utilisateur0;

    FILE* fichierutilisateur;
    fichierutilisateur= fopen(nomfichier,"r");
    if(fichierutilisateur!=NULL){
        printf("Listes des utilisateur\n");
        printf("________________________________________________________________________________________________\n");
        printf("Id\tPrenom\tNom\tTelephone\tEmail\t\t\t\tLogin\tPassword\n");
        while (fscanf(fichierutilisateur,"%d %s %s %d %s %s %s",&utilisateur0.id,&utilisateur0.prenomUtilisateur,&utilisateur0.nomUtilisateur,&utilisateur0.telephoneUtilisateur,&utilisateur0.emailUtilisateur,&utilisateur0.loginUtilisateur,&utilisateur0.passwordUtilisateur)!= EOF){
            printf("%d\t%s\t%s\t%d\t%s\t%s\t%s\n",utilisateur0.id,utilisateur0.prenomUtilisateur,utilisateur0.nomUtilisateur,utilisateur0.telephoneUtilisateur,utilisateur0.emailUtilisateur,utilisateur0.loginUtilisateur,utilisateur0.passwordUtilisateur);
        }
        fclose(fichierutilisateur);
    } else{
        printf("\nErreur d'ouverture");
    }
};

//////////// id utilisateur ///////////////
int id_utilisateur(void){
  int id=1;
    Utilisateur utilisateur0;

    FILE* fichierutilisateur=NULL;
    fichierutilisateur= fopen("USERS.txt","r");
    if(fichierutilisateur!=NULL){

        while (fscanf(fichierutilisateur,"%d %s %s %d %s %s %s",&utilisateur0.id,&utilisateur0.prenomUtilisateur,&utilisateur0.nomUtilisateur,&utilisateur0.telephoneUtilisateur,&utilisateur0.emailUtilisateur,&utilisateur0.loginUtilisateur,&utilisateur0.passwordUtilisateur)!= EOF){
            id=utilisateur0.id+1;
        }
        fclose(fichierutilisateur);
    }
    return id;
};

////////////// Menu administrateur /////////////////
int menu_administrateur(void ){
    system("cls");
    int choix;
    printf("\t\tMenu Administrateur\n");
    printf("________________________________________________________\n");
    printf("\n1-Creer, Modifier, lister les Chambres et les Categories\n");
    printf("________________________________________________________\n");
    printf("\n2-Liste des chambres disponibles\n");
    printf("________________________________________________________\n");
    printf("\n3-Liste des reservations en cours \n");
    printf("________________________________________________________\n");
    printf("\n4-Liste des clients qui ont reserves  \n");
    printf("________________________________________________________\n");
    printf("\n5-Filtrer les reservations par etat \n");
    printf("________________________________________________________\n");
    printf("\n6-Faire une reservation pour un client \n");
    printf("________________________________________________________\n");
    printf("\n7-Ajouter utilisateur \n");
    printf("________________________________________________________\n");
    printf("\n8-Liste des utilisateurs \n");
    printf("________________________________________________________\n");
    printf("\n9-Se deconnecter \n");
    printf("________________________________________________________\n\n");
    do {
        printf("Entrer l'option : ");
        scanf("%d",&choix);

    } while (choix<=0 || choix>9);
    return choix;

};
/////////// sous_menu_administrateur_pour_chambre ///////////
int sous_menu_administrateur_pour_chambre(void ){
    system("cls");
    int choix;
    printf("\t\t\tCHAMBRES\n");
    printf("________________________________________________________\n");
    printf("\n1-Creer une Chambre\n");
    printf("________________________________________________________\n");
    printf("\n2-Modifier une Chambre\n");
    printf("________________________________________________________\n");
    printf("\n3-Liste des Chambres\n");
    printf("________________________________________________________\n");
    printf("\n4-Precedent\n");
    printf("________________________________________________________\n\n");
    do {
        printf("Entrer l'option : ");
        scanf("%d",&choix);

    } while (choix<1 || choix>4);
    return choix;

};

/////////// sous_menu_administrateur_pour_categorie ///////////
int sous_menu_administrateur_pour_categorie(void ){
    system("cls");
    int choix;
    printf("\t\t\tCATEGORIE\n");
    printf("________________________________________________________\n");
    printf("\n1-Creer une Categorie\n");
    printf("________________________________________________________\n");
    printf("\n2-Modifier une Categorie\n");
    printf("________________________________________________________\n");
    printf("\n3-Liste des Categories\n");
    printf("________________________________________________________\n");
    printf("\n4-Precedent\n");
    printf("________________________________________________________\n\n");
    do {
        printf("Entrer l'option : ");
        scanf("%d",&choix);

    } while (choix<1 || choix>4);
    return choix;

};

///////////// Menu Gestionnaire de reservation /////////////////
int menu_gestionnaire_de_reservation(void){
    system("cls");
    int choix;
    printf("\t\tMenu Gestionnaire de reservations\n");
    printf("____________________________________________________________________________\n");
    printf("\n1-Liste des chambres disponibles\n");
    printf("________________________________________________________\n");
    printf("\n2-Liste des reservations en cours \n");
    printf("________________________________________________________\n");
    printf("\n3-Liste des clients qui ont reserves  \n");
    printf("________________________________________________________\n");
    printf("\n4-Filtrer les reservations par etat \n");
    printf("________________________________________________________\n");
    printf("\n5-Faire une reservation pour un client \n");
    printf("________________________________________________________\n");
    printf("\n6-Rendre chambre disponible \n");
    printf("________________________________________________________\n");
    printf("\n7-Se deconnecter \n");
    printf("________________________________________________________\n\n");
    do {
        printf("Entrer l'option : ");
        scanf("%d",&choix);

    } while (choix<=0 || choix>7);
    return choix;

};

//////////////// Modifier le mot de passe de l'utilisateur //////////////
void modifier_utilisateur_password(int id){
    Utilisateur utilisateur0;
    FILE* fichierutilisateur;
    FILE* newfile;


  char newpassword[50];



    fichierutilisateur= fopen("USERS.txt","r");
    newfile=fopen("newfile.txt","a");

    if(fichierutilisateur!=NULL){
        while(fscanf(fichierutilisateur,"%d %s %s %d %s %s %s",&utilisateur0.id,&utilisateur0.prenomUtilisateur,&utilisateur0.nomUtilisateur,&utilisateur0.telephoneUtilisateur,&utilisateur0.emailUtilisateur,&utilisateur0.loginUtilisateur,&utilisateur0.passwordUtilisateur)!= EOF){

                if(id==utilisateur0.id){
                fflush(stdin);


                    printf("\nEntrer le nouveau mot de passe : ");
                    scanf("%s", &newpassword);


            fflush(stdin);

                fprintf(newfile,"%d %s %s %d %s %s %s\n",utilisateur0.id,utilisateur0.prenomUtilisateur,utilisateur0.nomUtilisateur,utilisateur0.telephoneUtilisateur,utilisateur0.emailUtilisateur,utilisateur0.loginUtilisateur,newpassword);
            }else{
                fprintf(newfile,"%d %s %s %d %s %s %s\n",utilisateur0.id,utilisateur0.prenomUtilisateur,utilisateur0.nomUtilisateur,utilisateur0.telephoneUtilisateur,utilisateur0.emailUtilisateur,utilisateur0.loginUtilisateur,utilisateur0.passwordUtilisateur);

            }
        }

    }
    fclose(newfile);
    fclose(fichierutilisateur);
    remove("USERS.txt");
    rename("newfile.txt","USERS.txt");
};
