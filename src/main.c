/*!
    \file main.c
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Main program
*/

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "defines.h"
#include "functions_algo_KNN.h"
#include "functions_sort.h"


int main(int argc, char const *argv[])
{
    int wrong_input_value = 1;
    int main_menu_choice;
    printf("Logiciel de prédiction de prix d'un logement Airbnb\n\n");
    printf("Choisissez :\n");
    printf("1. Déterminer un prix approprié pour un logement\n");
    printf("2. Déterminer la caractéristique et la valeur de k permettant le plus de précision lors de la prédiction\n");
    while(wrong_input_value){
        scanf("%d", &main_menu_choice);
        if(main_menu_choice == 1 || main_menu_choice == 2){
            wrong_input_value = 0;
        }
        else{
            printf("Vous devez entrer une valeur entre 1 et 2. Réessayez.\n");
        }
    }
    if(main_menu_choice == 1){
        impementationKnnAlgorithm();
    }
    else if(main_menu_choice == 2){
        evalPredictionModel(); 
    }
    return 0;
}
