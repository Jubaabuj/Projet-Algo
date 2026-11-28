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
liste * supprimer_etudiant(liste *l, float val);
void trier_liste(liste *l);
void afficher_liste_trie(liste *l);
void trier_liste_decroissant(liste *l);
void afficher_k_meilleur_etudiant(liste *l, int k);
void detruire_liste(liste **l);


#endif