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
    if (e.sexe==M){
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
        return M;
    }
    else if (c=='F'){
        return F;
    }
    return saisir_sexe();
}

etudiant generer_etudiant(){
    etudiant e;
    char nom[50];
    char prenom[50];
    int age;
    Sexe sexe;
    printf("\n nom de l'utilisateur : ");
    scanf("%s", nom);
    strcpy(e.nom,nom);
    printf("\n prenom de l'utilisateur : ");
    scanf("%s", prenom);
    strcpy(e.prenom,prenom);
    printf("\n age de l'utilisateur : ");
    scanf("%d", &age);
    e.age=age;
    sexe=saisir_sexe();
    e.sexe=sexe;
    srand(time(NULL));
    for(int i=0; i<5; i++){
        e.notes[i]=rand()%21;
    }
    return e;
}  