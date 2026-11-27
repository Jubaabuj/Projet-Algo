
#ifndef ETUDIANT_H
#define ETUDIANT_H

typedef enum{
    H='H',
    F='F'    
}Sexe;

typedef struct etudiant{
    char nom[50];
    char prenom[50];
    int age;
    Sexe sexe;
    int notes[5];
} etudiant;

void afficher_etudiant(etudiant e);
 #endif