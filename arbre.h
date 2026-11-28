#ifndef ARBRE_H
#define ARBRE_H

#include "etudiant.h"

 //Arbre binaire de recherche (ABR) indexé sur la moyenne générale.
// Clé = somme des 5 notes (entier) = 5 x moyenne. Comparaison exacte,
 //Moyennes identiques : les doublons vont dans le sous-arbre DROIT.
    //Invariant : gauche < cle <= droit.
 
 
 
   
     
 

typedef struct NoeudABR {
    etudiant e;
    int cle;                    //sommes des notes 
    struct NoeudABR *gauche;
    struct NoeudABR *droit;
} NoeudABR;

// Insère un étudiant. 
NoeudABR *inserer_abr(NoeudABR *a, etudiant e);


int  rechercher_abr(NoeudABR *a, float moyenne);//izmer at3elegh booleen 1,0

// Nombre d'étudiants ayant exactement cette moyenne.
int  compter_abr(NoeudABR *a, float moyenne);

//Supprime UN étudiant ayant cette moyenne (feuille, un fils, deux fils).
 //supprime vaut 1 si un étudiant a ete  supprime, 0 sinon (peut être NULL).

NoeudABR *supprimer_abr(NoeudABR *a, float moyenne, int *supprime);

// moyenne croissante (parcours infixe)
void afficher_croissant_abr(NoeudABR *a);

// Copie tous les étudiants par moyenne croissante dans tab (taille >= taille_abr(a)).
 // Retourne le nombre copie. Utile pour les mesures (pas pour afiicher ).
int  parcours_croissant_abr(NoeudABR *a, etudiant *tab);


// Hauteur (nombre de niveaux) et nombre  d etudiants .
int  hauteur_abr(NoeudABR *a);
int  taille_abr(NoeudABR *a);

//liberer arbre 
void detruit_arbre(NoeudABR *a);

NoeudABR *construire_abr_equilibre(etudiant *tab, int n);

#endif