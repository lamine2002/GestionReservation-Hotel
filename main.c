#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prestation.h"
#include "prestation.c"
#include "utilisateur.h"
#include "utilisateur.c"
#include "chambre.h"
#include "client.h"
#include "client.c"
#include "categorie.h"
#include "categorie.c"
#include "chambre.c"
#include "reservation.h"
#include "reservation.c"


int main() {
    system("color 0b");
    char chambre[]="CAT10001";

    int h, min, s, day, mois, an,jj,mm,aaaa,hh,mn,ss;
    time_t now;

    // Renvoie l'heure actuelle
    time(&now);
    // Convertir au format heure locale
    struct tm *local = localtime(&now);
    h = local->tm_hour;
    min = local->tm_min;
    s = local->tm_sec;
    day = local->tm_mday;
    mois = local->tm_mon + 1;
    an = local->tm_year + 1900;
    jj=day;
    mm=mois;
    aaaa=an;
    hh=h;
    mn=min;
    ss=s;
    int choix,choix_1,choix_chambre,choix_categorie,choix_etat;
    char numerochambre[30],codecategorie[30],libellecategorie[30];

int connexion,admin=0,gest=0,verification=0;
char login[30],password[30],administrateur[]="LAMNI",pass[]="passerbdd";
    Utilisateur utilisateur0,user;
    do {
        system("cls");
        printf("\tBienvenu dans L'hotel Boulako Dara Diaral");
        printf("\n___________________________________________________________\n");
        printf("\n Login : ");
        scanf("%s",&login);
        printf("\n Mot de passe : ");
        scanf("%s",&password);

        ////////////// Verification donnees utilisateur


        FILE* fichierutilisateur;
        fichierutilisateur= fopen("USERS.txt","r");
        if(fichierutilisateur!=NULL){

            while (fscanf(fichierutilisateur,"%d %s %s %d %s %s %s",&utilisateur0.id,&utilisateur0.prenomUtilisateur,&utilisateur0.nomUtilisateur,&utilisateur0.telephoneUtilisateur,&utilisateur0.emailUtilisateur,&utilisateur0.loginUtilisateur,&utilisateur0.passwordUtilisateur)!= EOF){
                if(strcmp(utilisateur0.loginUtilisateur,login)==0 && strcmp(utilisateur0.passwordUtilisateur,password)==0 &&
                        strcmp(utilisateur0.loginUtilisateur,administrateur)==0){
                    user=utilisateur0;
                    admin=1;
                }
                if(strcmp(utilisateur0.loginUtilisateur,login)==0 && strcmp(utilisateur0.passwordUtilisateur,password)==0 &&
                   strcmp(utilisateur0.loginUtilisateur,administrateur)!=0){
                    user=utilisateur0;
                    gest=1;
                }
            }
            fclose(fichierutilisateur);
        }
        if(gest==1 || admin==1){
            verification=1;
        }
    } while (verification!=1);


    if(admin==1){
        if(strcmp(user.passwordUtilisateur,pass)==0){
            modifier_utilisateur_password(user.id);
        }
        ////////////////// Menu Administrateur //////////////////////
    do {
        choix=menu_administrateur();
        switch (choix) {
            case 1:
                do {
                    system("cls");
                    printf("\tCreer, Modifier, lister les Chambres et les Categories\n");
                    printf("_________________________________________________________________\n");
                    printf("\n1-CHAMBRES\n");
                    printf("_________________________________________________________________\n");
                    printf("\n2-CATEGORIES\n");
                    printf("_________________________________________________________________\n");
                    printf("\n3-Menu Administrateur\n");
                    printf("_________________________________________________________________\n\n");
                    do {
                        printf("Entrer l'option : ");
                        scanf("%d",&choix_1);
                    } while (choix_1<1 || choix_1>3);
                    if(choix_1==1){
                        do {
                            choix_chambre=sous_menu_administrateur_pour_chambre();
                            switch (choix_chambre) {
                                case 1:
                                    system("cls");
                                    ajoutChambreFile("CHAMBRES.txt");
                                    system("pause");
                                    break;
                                case 2:
                                    system("cls");
                                    listeChambreFile("CHAMBRES.txt");
                                    printf("\nSaisir le numero de la chambre : ");
                                    scanf("%s",&numerochambre);
                                    modifierChambreFile("CHAMBRES.txt",numerochambre);
                                    system("pause");
                                    break;
                                case 3:
                                    system("cls");
                                    listeChambreFile("CHAMBRES.txt");
                                    system("pause");
                                    break;
                            }
                        } while (choix_chambre!=4);
                    }
                    if(choix_1==2){
                        do {
                            choix_categorie=sous_menu_administrateur_pour_categorie();
                            switch (choix_categorie) {
                                case 1:
                                    system("cls");
                                    ajoutCategorieFile("CATEGORIES.txt");
                                    system("pause");
                                    break;
                                case 2:
                                    system("cls");
                                    listeCategorieFile("CATEGORIES.txt");
                                    printf("\nSaisir le code de la categorie : ");
                                    scanf("%s",&codecategorie);
                                    printf("\nSaisir le libelle de la categorie : ");
                                    scanf("%s",&libellecategorie);
                                    modifierCategorieFile("CATEGORIES.txt",codecategorie,libellecategorie);
                                    system("pause");
                                    break;
                                case 3:
                                    system("cls");
                                    listeCategorieFile("CATEGORIES.txt");
                                    system("pause");
                                    break;
                            }
                        } while (choix_categorie!=4);
                    }
                } while (choix_1!=3);
                break;
            case 2:
                system("cls");
                listeChambreDisponibleFile("CHAMBRES.txt");
                system("pause");
                break;
            case 3:
                system("cls");
                liste_des_reservations_en_cours();
                system("pause");
                break;
            case 4:
                system("cls");
                liste_des_clientsreserves("CUSTOMERS.txt");
                system("pause");
                break;
            case 5:
                do {
                    system("cls");
                    printf("\tFiltrage des reservation par etat\n");
                    printf("_________________________________________________________________\n");
                    printf("\n1-Par Date\n");
                    printf("_________________________________________________________________\n");
                    printf("\n2-Par Montant\n");
                    printf("_________________________________________________________________\n");
                    printf("\n3-Menu Administrateur\n");
                    printf("_________________________________________________________________\n\n");
                    do {
                        printf("Entrer l'option : ");
                        scanf("%d", &choix_etat);
                    } while (choix_etat < 1 || choix_etat > 3);
                    if(choix_etat==1){
                        system("cls");
                        etat_date();
                        printf("\n");
                        system("pause");
                    }
                } while (choix_etat!=3);
                break;
            case 6:
                system("cls");
                ajout_reservation_dans_file(user,jj,mm,aaaa,hh,mn,ss);
                printf("\n");
                system("pause");
                break;
            case 7:
                system("cls");
                ajout_utilisateur_dans_file("USERS.txt");
                system("pause");
                break;
            case 8:
                system("cls");
                liste_des_utilisateurs_dans_file("USERS.txt");
                system("pause");
                break;
        }
    } while (choix!=9);
    }

    ////////////// Gestionnaire de reservation ////////////////
    char numchambre[40];
    if(gest==1){
        if(strcmp(user.passwordUtilisateur,pass)==0){
            modifier_utilisateur_password(user.id);
        }
        do {
            choix=menu_gestionnaire_de_reservation();
            switch (choix) {

                case 1:
                    system("cls");
                    listeChambreDisponibleFile("CHAMBRES.txt");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    liste_des_reservations_en_cours();
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    liste_des_clientsreserves("CUSTOMERS.txt");
                    system("pause");
                    break;
                case 4:
                    break;
                case 5:
                    system("cls");
                    ajout_reservation_dans_file(user,jj,mm,aaaa,hh,mn,ss);
                    printf("\n");
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    listeChambreFile("CHAMBRES.txt");
                    printf("\nSaisir le Numero de chambre : ");
                    scanf("%s",&numchambre);
                    rendreChambreDisponible("CHAMBRES.txt",numchambre);
                    system("pause");
                    break;

            }
        } while (choix!=7);
    }

    return 0;
}
