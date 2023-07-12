//
// Created by hp on 13/07/2022.
//

#ifndef PROJET_EXAM_LANG_C_UTILISATEUR_H
#define PROJET_EXAM_LANG_C_UTILISATEUR_H
typedef struct {
    char nomUtilisateur[30],prenomUtilisateur[30],emailUtilisateur[30],loginUtilisateur[30],passwordUtilisateur[30];
    int id,telephoneUtilisateur;
}Utilisateur;

////////// Prototypes /////////////////////
void ajout_utilisateur_dans_file(const char* nomfichier);
Utilisateur ajout_utilisateur();
void liste_des_utilisateurs_dans_file(const char* nomfichier);
int id_utilisateur(void);
int menu_administrateur(void );
int sous_menu_administrateur_pour_chambre(void );
int sous_menu_administrateur_pour_categorie(void );
int menu_gestionnaire_de_reservation(void);
void modifier_utilisateur_password(int id);
#endif //PROJET_EXAM_LANG_C_UTILISATEUR_H
