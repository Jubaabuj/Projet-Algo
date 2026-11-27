#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"etudiant.h"


float moyenne_etudiant(etudiant e){
    float S=0;
    for(int i=0;i<5; i++){
        S=S+e.notes[i];
    } 
    return S/5.0;
}

void afficher_etudiant(etudiant e){
    printf("nom de l'etudiant : %s \n", e.nom);
    printf("prenom de l'etudiant : %s \n", e.prenom);
    printf("age de l'etudiant : %d \n", e.age);
    if (e.sexe==H){
        printf("sexe de l'etudiant : Homme \n");
    }
    else {
        printf("sexe de l'etudiant : Femme \n");
    }
    printf("moyenne de l'etudiant : %f \n", moyenne_etudiant(e));
}

Sexe saisir_sexe(){
    char c;
    printf("\n sexe de l'etudiant (H/F) :");
    scanf(" %c", &c);
    if(c=='H'){
        return H;
    }
    else if (c=='F'){
        return F;
    }
    return saisir_sexe();
}

void generernom(char mot[]) {
    int taille =rand()%40 + 10;
    for (int i=0; i<taille; i++) {
        mot[i] ='A'+ rand()%26;
    }  
    mot[taille] = '\0'; 
}



etudiant generer_etudiant(){
    etudiant e;
    Sexe sexe;
    generernom(e.nom);
    generernom(e.prenom);
    e.age =rand()%20 +18;
    sexe=saisir_sexe();
    e.sexe=sexe;
    for(int i=0; i<5; i++){
        e.notes[i]=rand()%21;
    }
    return e;
}  