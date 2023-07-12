//
// Created by hp on 13/07/2022.
//

#ifndef PROJET_EXAM_LANG_C_PRESTATION_H
#define PROJET_EXAM_LANG_C_PRESTATION_H
typedef struct {
    char designationPrestation[50],codePrestation[30];
    float montant;
}Prestation;
#endif //PROJET_EXAM_LANG_C_PRESTATION_H
//////////Les protypes///////////////////
void ajout_prestation_dans_file(const char *nomfichier);
void liste_des_prestation_dans_file(const char *nomfichier);