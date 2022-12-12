/*!
    \file functions_algo_KNN.h
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fichier d'en tête des fonctions de fonctions_algo_KNN.c
*/
#ifndef FUNCTIONS_ALGO_KNN_H
#define FUNCTIONS_ALGO_KNN_H

void calculateDistance(Housing housingArray[], int housingArraylength, Housing housingX, char *characteristics[], int number_characteristics);
Housing housingXDataFilling();
void impementationKnnAlgorithm();
void evalPredictionModel();
int inputInt(int lowerLimit, int upperLimit);
int inputNumCharac();
int inputK(int housingArrayLength);

#endif