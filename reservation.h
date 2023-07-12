//
// Created by hp on 13/07/2022.
//

#ifndef PROJET_EXAM_LANG_C_RESERVATION_H
#define PROJET_EXAM_LANG_C_RESERVATION_H
#include "prestation.h"
#include "utilisateur.h"
#include "chambre.h"
#include "client.h"

typedef struct {
    char numeroReservation[30];
    float montantreservation;
    Utilisateur loginUtilisateurReserve;
    Prestation prestationReserve[3];
    Chambre chambreReserve;
    Client clientReserve;
    int idreservation;
}Reservation;

///////// Les prototypes/////////////
void ajout_reservation_dans_file(Utilisateur utilisateur,int jj,int mm,int aaaa,int hh,int mn,int ss);
int id_reservations(void);
void liste_des_reservations_en_cours(void );
void etat_chambreapres_reservation(const char* nomfichier,char numeroChambre[]);
void etat_date(void);
#endif //PROJET_EXAM_LANG_C_RESERVATION_H
