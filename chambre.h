//
// Created by hp on 11/07/2022.
//

#ifndef PROJET_EXAM_LANG_C_CHAMBRE_H
#define PROJET_EXAM_LANG_C_CHAMBRE_H
#include "categorie.h"
typedef struct {
    int id,numTelephone;
    char numChambre[30];
    int etatChambre;
    Categorie categorieChambre;
}Chambre;

typedef struct {
    Chambre tableauChambre[10];
}hotel;

///////LES PROTOTYPES//////////////
int id_chambre(void);
Chambre ajoutchambre(void);
void ajoutChambreFile(const char* nomfichier);
void listeChambreFile(const char* nomfichier);
void listeChambreDisponibleFile(const char* nomfichier);
void modifierChambreFile(const char* nomfichier,char numeroChambre[]);
void rendreChambreDisponible(const char* nomfichier,char numeroChambre[]);
#endif //PROJET_EXAM_LANG_C_CHAMBRE_H
