/*!
    \file functions_sort.c
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonctions traitant des fichiers et des tableaux
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "defines.h"
#include "functions_fileToArray.h"


/*!
    \fn int numberLineFile(char* fileName){
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction comptant le nombre de lignes d'un fichier
    \param fileName Nom du fichier
    \return Le nombre de lignes comptés
*/
int numberLineFile(char* fileName){
    FILE* file = NULL;
    char character = 0;
    int number_lines = 0;

    file = fopen(fileName, "r");
    if(file == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while((character = fgetc(file)) != EOF){
        if(character == '\n'){
            number_lines++;
        }
    }
    fclose(file);
    return number_lines;
}


/*!
    \fn headingHousingsFile(char* headingData, int* characteristicsIndex){
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction déterminant l'ordre de l'en-tête d'un fichier de données pour pouvoir bien récupérer les données en question
    \param headingData Chaîne de caractères contenant l'en-tête du fichier
    \param characteristicsIndex Tableau contenant l'ordre des caractéristiques
*/
void headingHousingsFile(char* headingData, int* characteristicsIndex){
    char* headingChar = "";
    int indexChar = 0;
    headingChar = strtok(headingData, ",");
    
    while(headingChar != NULL){
        if(strcmp(headingChar, "accommodates") == 0){
            characteristicsIndex[0] = indexChar;
        }
        else if(strcmp(headingChar, "bedrooms") == 0){
            characteristicsIndex[1] = indexChar;
        }
        else if(strcmp(headingChar, "bathrooms") == 0){
            characteristicsIndex[2] = indexChar;
        }
        else if(strcmp(headingChar, "beds") == 0){
            characteristicsIndex[3] = indexChar;
        }
        else if(strcmp(headingChar, "price") == 0){
            characteristicsIndex[4] = indexChar;
        }
        else if(strcmp(headingChar, "minimum_nights") == 0){
            characteristicsIndex[5] = indexChar;
        }
        else if(strcmp(headingChar, "maximum_nights") == 0){
            characteristicsIndex[6] = indexChar;
        }
        else if(strcmp(headingChar, "number_of_reviews") == 0){
            characteristicsIndex[7] = indexChar;
        }
        headingChar = strtok(NULL, ",");
        indexChar++;
    }

}


/*!
    \fn Housing housingDataFilling(char* housingData, int* characteristicsIndex)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction récupérant les valeurs d'un logement pour les convertir en un type Housing
    \param housingData Chaîne de caractères contenant les valeurs du logement
    \param characteristicsIndex Tableau contenant l'ordre des caractéristiques
    \return Le logement
*/
Housing housingDataFilling(char* housingData, int* characteristicsIndex){
    Housing housing;
    char * data = "";
    int indexChar = 0;

    data = strtok(housingData, ",");
    data = strtok(NULL, ",");
    while(data != NULL){
        if(indexChar > 7){
            fprintf(stderr, "Error strtok csv housing");
            exit(1);
        }
        else if(characteristicsIndex[0] == indexChar){
            housing.accommodates = strtof(data, NULL);
        }
        else if(characteristicsIndex[1] == indexChar){
            housing.bedrooms = strtof(data, NULL);
        }
        else if(characteristicsIndex[2] == indexChar){
            housing.bathrooms = strtof(data, NULL);
        }
        else if(characteristicsIndex[3] == indexChar){
            housing.beds = strtof(data, NULL);
        }
        else if(characteristicsIndex[4] == indexChar){
            housing.price = strtof(data, NULL);
        }
        else if(characteristicsIndex[5] == indexChar){
            housing.min_nights = strtof(data, NULL);
        }
        else if(characteristicsIndex[6] == indexChar){
            housing.max_nights = strtof(data, NULL);
        }
        else if(characteristicsIndex[7] == indexChar){
            housing.number_of_reviews = strtof(data, NULL);
        }
        data = strtok(NULL, ",");
        indexChar++;
    }

    housing.distance = NULL;

    return housing;
}


/*!
    \fn void housingArrayFilling(char* fileName, Housing* housingArray, int* characteristicsIndex)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction remplissant un tableau de logement avec le fichier contanant les données de ces logements
    \param fileName Nom du fichier de données
    \param housingArray Tableau de logements
    \param characteristicsIndex Tableau contenant l'ordre des caractéristiques
*/
void housingArrayFilling(char* fileName, Housing* housingArray, int* characteristicsIndex){
    FILE* file = NULL;
    //char character = 0;
    char line[256];
    int index = -1;

    file = fopen(fileName, "r");
    if(file == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    while(fgets(line, 256, file) != NULL){
        line[strlen(line)-2] = 0;
        if(index == -1){
            headingHousingsFile(line, characteristicsIndex);
        }
        else{
            housingArray[index] = housingDataFilling(line, characteristicsIndex);
        }
        index++;
    }
    fclose(file);
}


/*!
    \fn void maeFile(RegisterMae* maeArray, int maeArrayLenght, char* characteristics[])
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction inscrivant le tableau de MAE dans un fichier
    \param maeArray Tableau de MAE
    \param maeArrayLenght Taille du tableau de MAE
    \param characteristics Tableau contenant le nom des caractéristiques d'un logement
*/
void maeFile(RegisterMae* maeArray, int maeArrayLenght, char* characteristics[]){
    FILE * file = fopen("maeData.txt", "w");
    fprintf(file, "MAE\t\tCharacteristic\t\tk\n");
    for(int i = 0; i < maeArrayLenght; i++){
        fprintf(file, "%f\t%-18s\t%d\n", maeArray[i].mae, characteristics[maeArray[i].characteristic_num - 1], maeArray[i].k);
    }
    fclose(file);
}


/*!
    \fn void pricePredictedFile(float* pricePredictions, Housing* housingArray, int priceArrayLenght)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction inscrivant les prix prédit avec les prix connu pour toutes les logement du fichier test dans un autre fichier
    \param pricePredictions Tableau de prédictions de prix
    \param housingArray Tableau de logements
    \param priceArrayLenght Taille des tableaux entrés en paramètre
*/
void pricePredictedFile(float* pricePredictions, Housing* housingArray, int priceArrayLenght){
    FILE * file = fopen("pricePredictions.txt", "w");
    fprintf(file, "Predictions\t\tPrice\n");
    for(int i = 0; i < priceArrayLenght; i++){
        fprintf(file, "%f\t\t%f\n", pricePredictions[i], housingArray[i].price);
    }
    fclose(file);
}