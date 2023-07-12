//
// Created by hp on 13/07/2022.
//

#ifndef PROJET_EXAM_LANG_C_CATEGORIE_H
#define PROJET_EXAM_LANG_C_CATEGORIE_H
typedef struct {
    int id;
    char libelleCategorie[30],descriptionCategorie[30],codeCategorie[30];
    int etatCategorie;
    float montant;
}Categorie;

Categorie ajoutcategorie(void);
void ajoutCategorieFile(const char* nomfichier);
void listeCategorieFile(const char* nomfichier);
void modifierCategorieFile(const char* nomfichier,char codecategorie[],char libelleCategorie[]);
#endif //PROJET_EXAM_LANG_C_CATEGORIE_H
