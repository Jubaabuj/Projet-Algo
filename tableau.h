#ifndef TABLEAU_H
#define TABLEAU_H

#include "etudiant.h"

typedef struct TabEtu {
    etudiant *E;
    int taille;
    int capacite;

}TabEtu;

#endif