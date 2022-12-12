/*!
    \file functions_file_array.h
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fichier d'en tête des fonctions de fonctions_file_array.c
*/

#ifndef FUNCTIONS_FILETOARRAY_H
#define FUNCTIONS_FILETOARRAY_H

int numberLineFile(char* fileName);
void headingHousingsFile(char* headingData, int characteristicsIndex[]);
Housing housingDataFilling(char* housingData, int characteristicsIndex[]);
void housingArrayFilling(char* fileName, Housing housingArray[], int characteristicsIndex[]);
void maeFile(RegisterMae* maeArray, int maeArrayLenght, char* characteristics[]);
void pricePredictedFile(float* pricePredictions, Housing* housingArray, int priceArrayLenght);

#endif