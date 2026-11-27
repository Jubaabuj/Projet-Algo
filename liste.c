#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include"etudiant.h"
#include"liste.h"



liste * creeNoeud(etudiant e){
    liste * l;
    l->suivant =NULL;
    l->e=e;
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

liste * supprimer_etudiant(liste *l, int val){
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

