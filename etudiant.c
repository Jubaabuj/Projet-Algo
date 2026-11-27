#include<stdio.h>
#include<etudiant.h>

void afficher_etudiant(etudiant e){
    printf("nom de l'etudiant : %s \n", e.nom);
    printf("prenom de l'etudiant : %s \n", e.prenom);
    printf("nom de l'etudiant : %d \n", e.age);
    if (e.sexe==H){
        printf("sexe de l'etudiant : Homme \n");
    }
    else {
        printf("sexe de l'etudiant : Femme \n");
    }
    for(int i=0;i<5; i++){
        printf("la note numero %d : %d",i+1,  e.notes[i]);
    }   
}