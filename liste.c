#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include"etudiant.h"
#include"liste.h"



liste * creeNoeud(etudiant e){
    liste * l= malloc(sizeof(liste));
    if(l==NULL){
        return NULL;
    }
    l->suivant =NULL;
    l->e=e;
    return l;
}

liste * ajouter_liste(liste * l, etudiant e){
    liste * new = creeNoeud(e);
    if(new==NULL){
        return l;
    }
    if (l==NULL){
        return new;
    }
    liste *tmp= l;
    while(tmp->suivant!=NULL){
          tmp=tmp->suivant;
    }
    tmp->suivant=new;
    return l;
}

bool etudiant_existe_l(liste * l, float val){
    if(l== NULL){
        return false;
    }
    while(l!=NULL){
        if(moyenne_etudiant(l->e)==val){
            return true;
        }
        l=l->suivant;
    }
    return false;
}

int nombre_moyenne(liste * l, float val){
    if(l== NULL){
        return 0;
    }
    int c=0;
    while(l!=NULL){
        if(moyenne_etudiant(l->e)==val){
            c++;
        }
        l=l->suivant;
    }
    return c;
}

liste * supprimer_etudiant(liste *l, float val){
    if(l==NULL){
        return NULL;
    }
    if(moyenne_etudiant(l->e)==val){
        liste * nv = l->suivant;
        free (l);
        return nv;
        
    }
    liste * tmp = l;
    while (tmp->suivant!=NULL && moyenne_etudiant(tmp->suivant->e)!=val){
         tmp=tmp->suivant;
   }
   if (tmp->suivant==NULL){
    return l;
   }
   liste * tmp2 = tmp->suivant;
   tmp->suivant=tmp2->suivant;
   free(tmp2);
   return l;
}

void trier_liste(liste *l){
    if(l==NULL || l->suivant==NULL){
        return;
    }
    liste * ltmp;
    etudiant tmp;
    int i=1;
    while(i!=0){
        ltmp=l;
        i=0;
        while(ltmp->suivant!=NULL){
            if(moyenne_etudiant(ltmp->e)>moyenne_etudiant(ltmp->suivant->e)){
                tmp = ltmp->e;
                ltmp->e=ltmp->suivant->e;
                ltmp->suivant->e=tmp;
                i++;
            }
        ltmp = ltmp->suivant;
        }
    }
} 

void afficher_liste_trie(liste *l){
    trier_liste(l);
    while (l!=NULL){
        printf("-----------------------\n");
        afficher_etudiant(l->e);
        l=l->suivant;
    }  
}

void detruire_liste(liste **l){
    liste * tmp;
    while(*l!=NULL){
        tmp =(*l) ->suivant;
        free(*l);
        *l=tmp;
    }
}


