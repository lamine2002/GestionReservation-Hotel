//
// Created by hp on 13/07/2022.
//

#ifndef PROJET_EXAM_LANG_C_CLIENT_H
#define PROJET_EXAM_LANG_C_CLIENT_H
typedef struct {
    char nomClient[30],prenomClient[30],adresseClient[30];
    int telephoneClient;
}Client;
#endif //PROJET_EXAM_LANG_C_CLIENT_H
///////////Les prototypes////////////
Client ajout_client(void );
void ajout_client_dans_file(const char *nomfichier);
void liste_des_clientsreserves(const char *nomfichier);