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
// O(1)

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
/* meilleur cas : O(1) : la liste est vide
   moyens cas : O(n)
   pire cas : O(n)
*/

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
/*
meilleur cas : si l'etudiant est au debut de la liste O(1)
moyens cas : O(n)
pire cas : si il parcours toute la liste O(n)
*/

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
/*
meilleur cas : O(n)
moyens cas : O(n)
pire cas : O(n)
*/

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
/*
meilleur cas : si l'etudiant est au debut de la liste O(1)
moyens cas : O(n)
pire cas : O(n)
*/

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
/*
meilleur cas : liste deja trie O(n)
moyens cas : O(n²)
pire cas : liste trie a l'envers O(n²)
*/


void afficher_liste_trie(liste *l){
    trier_liste(l);
    while (l!=NULL){
        printf("-----------------------\n");
        afficher_etudiant(l->e);
        l=l->suivant;
    }  
}
/*
meilleur cas : liste deja trie O(n)
moyens cas : O(n²)
pire cas : liste trie a l'envers O(n²)
*/

void trier_liste_decroissant(liste *l){
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
            if(moyenne_etudiant(ltmp->e)<moyenne_etudiant(ltmp->suivant->e)){
                tmp = ltmp->e;
                ltmp->e=ltmp->suivant->e;
                ltmp->suivant->e=tmp;
                i++;
            }
        ltmp = ltmp->suivant;
        }
    }
}
/* 
meilleur cas : liste deja trie O(n)
moyens cas : O(n²)
pire cas : liste trie a l'envers O(n²)
*/

void afficher_k_meilleur_etudiant(liste *l, int k){
    if(l==NULL || k<=0){
        return;
    }
    trier_liste_decroissant(l);
    printf("classement des etudiant");
    for(int i=0; i<k && l!=NULL; i++){
       printf("%d : ", i+1);
       afficher_etudiant(l->e);
       l=l->suivant;
    }
}
/*
meilleur cas : liste deja trie O(n)
moyens cas : O(n²)
pire cas : liste trie a l'envers O(n²)
*/

void detruire_liste(liste **l){
    liste * tmp;
    while(*l!=NULL){
        tmp =(*l) ->suivant;
        free(*l);
        *l=tmp;
    }
}
/*
meilleur cas : O(n)
moyens cas : O(n)
pire cas : O(n)
*/

liste *generer_liste_etudiant(liste *l, int n){
    while(n>0){
        l=ajouter_liste(l ,generer_etudiant());
        n--;
    }     
    return l;
}
/*
meilleur cas : O(n)
moyens cas : O(n²)
pire cas : O(n²)
*/



