#ifndef LISTE_H
#define LISTE_H

typedef struct liste{
    etudiant e;
    struct liste * suivant;
} liste;

liste * creeNoeud(etudiant e);
liste * ajouter_liste(liste * l, etudiant e);
bool etudiant_existe_l(liste * l, float val);
int nombre_moyenne(liste * l, float val);
liste * supprimer_etudiant(liste *l, int val);


#endif