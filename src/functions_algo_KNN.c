/*!
    \file functions_algo_KNN.c
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonctions principales de l'algorithme KNN
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>   

#include "structures.h"
#include "defines.h"
#include "functions_algo_KNN.h"
#include "functions_fileToArray.h"
#include "functions_sort.h"


/*!
    \fn void calculateDistance(Housing* housingArray, int housingArraylength, Housing housingX, char* characteristics[], int number_characteristics)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction calculant les distances entre tous les logements dont le prix est connu avec un logement dont on cherche à prédir le prix
    \param housingArray Tableau de logements d'on le prix est connu
    \param housingArraylength Taille du tableau de logements
    \param housingX Logement dont on cherche à déterminé le prix
    \param characteristics Tableau contenant le nom des caractéristiques d'un logement
    \param number_characteristics Nombre de caractéristiques
*/
void calculateDistance(Housing* housingArray, int housingArraylength, Housing housingX, char* characteristics[], int number_characteristics){
    float sommeDistance = 0;
    for(int i = 0; i < housingArraylength; i++){
        float* distance = (float *) malloc(number_characteristics * sizeof(float));
        sommeDistance = 0;
        for(int j = 0; j < number_characteristics; j++){
            if(strcmp(characteristics[j], "accommodates") == 0){
                sommeDistance = housingArray[i].accommodates - housingX.accommodates;
            }
            else if(strcmp(characteristics[j], "bedrooms") == 0){
                sommeDistance = housingArray[i].bedrooms - housingX.bedrooms;
            }
            else if(strcmp(characteristics[j], "bathrooms") == 0){
                sommeDistance = housingArray[i].bathrooms - housingX.bathrooms;
            }
            else if(strcmp(characteristics[j], "beds") == 0){
                sommeDistance = housingArray[i].beds - housingX.beds;
            }
            else if(strcmp(characteristics[j], "price") == 0){
                sommeDistance = housingArray[i].price - housingX.price;
            }
            else if(strcmp(characteristics[j], "min_nights") == 0){
                sommeDistance = housingArray[i].min_nights - housingX.min_nights;
            }
            else if(strcmp(characteristics[j], "max_nights") == 0){
                sommeDistance = housingArray[i].max_nights - housingX.max_nights;
            }
            else if(strcmp(characteristics[j], "number_of_reviews") == 0){
                sommeDistance = housingArray[i].number_of_reviews - housingX.number_of_reviews;
            }
            distance[j] = fabs(sommeDistance);
        }
        housingArray[i].distance = distance;
    }
}



/*!
    \fn Housing housingXDataFilling(){
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Permet d'entrer les valeurs des caractéristiques d'un logement
    \return Le logement 
*/
Housing housingXDataFilling(){
    Housing housing;
    printf("\nEntrez les informations du logement:\n");
    printf("Accommodates : ");
    scanf("%f", &housing.accommodates);
    printf("Bedrooms : ");
    scanf("%f", &housing.bedrooms);
    printf("Bathrooms : ");
    scanf("%f", &housing.bathrooms);
    printf("Beds : ");
    scanf("%f", &housing.beds);
    printf("Min nights : ");
    scanf("%f", &housing.min_nights);
    printf("Max nights : ");
    scanf("%f", &housing.max_nights);
    printf("Number of reviews : ");
    scanf("%f", &housing.number_of_reviews);
    housing.price = 0.0;
    housing.distance = NULL;
    return housing;
}


/*!
    \fn void shuffleHousingsArray(Housing *housingArray, size_t housingArrayLength)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction permettant de mélanger aléatoirement un tableau
    \param housingArray Tableau de logements d'on le prix est connu
    \param housingArrayLength Taille du tableau de logements
*/
void shuffleHousingsArray(Housing *housingArray, size_t housingArrayLength)
{
    size_t i, j;
    Housing buffer;
    if(housingArrayLength == 1 )
        return;

    srand(time(NULL));

    for(i = 0; i < housingArrayLength-1; i++){
        // j is a random number between i and n-1 (included)
        j = i + rand() % (housingArrayLength-i);
        //swap the values of tab[i] and tab[j]
        buffer = housingArray[i];
        housingArray[i] = housingArray[j];
        housingArray[j] = buffer;
    }
}


/*!
    \fn float pricePrediction(Housing *housingArray, size_t housingArrayLength, int k)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction calculant le prix prédit
    \param housingArray Tableau de logements d'on le prix est connu
    \param housingArraylength Taille du tableau de logements
    \param k Paramètre k déterminant le nombre d'élément du tableau impliqués dans la moyenne déterminant le prix prédit
    \return Prix prédit
*/
float pricePrediction(Housing *housingArray, size_t housingArrayLength, int k){
    float priceSum = 0;
    if(k <= housingArrayLength){
        for(int i = 0; i < k; i++){
            priceSum += housingArray[i].price;
        }
    }
    return priceSum/k;
}


/*!
    \fn float calculateMAE(Housing *housingArray, size_t housingArrayLength, float *pricePredictions)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction calculant la MAE 
    \param housingArray Tableau de logements tests
    \param housingArraylength Taille du tableau de logements
    \param pricePredictions Tableau de prix prédit
    \return MAE
*/
float calculateMAE(Housing *housingArray, size_t housingArrayLength, float *pricePredictions){
    float mae = 0;
    for(int i = 0; i < housingArrayLength; i++){
        mae += fabs(pricePredictions[i] - housingArray[i].price);
    }
    return mae/housingArrayLength;
}


/*!
    \fn inputInt(int lowerLimit, int upperLimit){
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction d'entrée d'un entier dans des bornes
    \param lowerLimit Borne inférieur
    \param upperLimit Borne superieur
    \return Valeur entrée
*/
int inputInt(int lowerLimit, int upperLimit){
    int wrong_input_value = 1;
    int input;
    while(wrong_input_value){
        scanf("%d", &input);
        if(input == round(input) && input >= lowerLimit && input <= upperLimit){
            wrong_input_value = 0;
        }
        else{
            printf("Vous devez entrer une valeur entre %d et %d. Réessayez.\n", lowerLimit, upperLimit);
        }
    }
    return input;
}


/*!
    \fn int inputNumCharac()
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Menu de choix de la caracteristique selon laquelle le prix va être prédit
    \return Numero de la caracteristique
*/
int inputNumCharac(){
    int input;
    printf("\nChoisissez la caracteristique utilisée lors de la prédictions :\n");
    printf("1. Nombre de places - accommodates\n");
    printf("2. Nombre de chambres - bedrooms\n");
    printf("3. Nombre de salle de bains - bathrooms\n");
    printf("4. Nombre de lits - beds\n");
    printf("5. Nombre de nuits minimum - min_nights");
    printf("6. Nombre de nuits maximum - max_nights\n");
    printf("7. Nombre de reviews - number_of_reviews\n");
    input = inputInt(1, 7);
    return input;
}


/*!
    \fn void impementationKnnAlgorithm()
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction principale permettant de prédire le prix d'un logement d'après ses caractéristique - Partie 1 du sujet
*/
void impementationKnnAlgorithm(){
    int number_housings_data_clean = 0;
    Housing* housingsArrayDataClean = NULL;
    int characteristicsIndex[8] = {0};
    char* characteristicsForCalcDist[7] = {"accommodates", "bedrooms", "bathrooms", "beds", "min_nights", "max_nights", "number_of_reviews"};
    int number_charac_dist = 7;

    number_housings_data_clean = numberLineFile(PATH_HOUSING_ARRAY_DATA_CLEAN_CSV) - 1;

    if((housingsArrayDataClean = (Housing*) malloc(number_housings_data_clean * sizeof(Housing))) == NULL){
        fprintf(stderr, "Error memory allocation\n");
        exit(1);
    }

    int num_charac = inputNumCharac();

    printf("Entrez une valeur de k entre 1 et le nombre de logements utilisés pour la prédiction :\n");
    int k_value = inputInt(1, number_housings_data_clean);

    Housing housingX = housingXDataFilling();

    housingArrayFilling(PATH_HOUSING_ARRAY_DATA_CLEAN_CSV, housingsArrayDataClean, characteristicsIndex);
    calculateDistance(housingsArrayDataClean, number_housings_data_clean, housingX, characteristicsForCalcDist, number_charac_dist);
    shuffleHousingsArray(housingsArrayDataClean, number_housings_data_clean);
    sortHousingArray(housingsArrayDataClean, number_housings_data_clean, num_charac);

    printf("\nLe prix estimé du logement pour k = %d et %s comme caractéristique de comparaison est de %.2f\n", k_value, characteristicsForCalcDist[num_charac-1], pricePrediction(housingsArrayDataClean, number_housings_data_clean, k_value));

}


/*!
    \fn void evalPredictionModel()
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction principale permettant de déterminer la caractéristique et le k permettant des prédictions plus précises  - Partie 2(Bonus) du sujet
*/
void evalPredictionModel(){
    /* Initialisation des variables */
    int number_housings_training = 0;
    int number_housings_test = 0;
    Housing* housingsArrayTraining = NULL;
    Housing* housingsArrayTest = NULL;
    float** pricePredictions = NULL;
    int characteristicsIndex[8] = {0};
    char* characteristicsForCalcDist[7] = {"accommodates", "bedrooms", "bathrooms", "beds", "min_nights", "max_nights", "number_of_reviews"};
    int number_charac_dist = 7;
    float mae = 0;
    RegisterMae* maeArray;
    RegisterMae registerMae;
    RegisterMae registerMae_min;

    /* Recherche de la taille des fichiers impliqués */
    number_housings_training = numberLineFile(PATH_HOUSING_ARRAY_TRAINING_CSV) - 1;
    number_housings_test = numberLineFile(PATH_HOUSING_ARRAY_TEST_CSV) - 1;

    /* Allocation de la mémoire pour les différents tableaux nécessaires */

    if((housingsArrayTraining = (Housing*) malloc(number_housings_training * sizeof(Housing))) == NULL){
        fprintf(stderr, "Error memory allocation\n");
        exit(1);
    }

    if((housingsArrayTest = (Housing*) malloc(number_housings_test * sizeof(Housing))) == NULL){
        fprintf(stderr, "Error memory allocation\n");
        exit(1);
    }

    
    if((pricePredictions = (float**) malloc(number_charac_dist * sizeof(float*))) == NULL){
        fprintf(stderr, "Error memory allocation\n");
        exit(1);
    }
    
    for(int k = 0; k < number_charac_dist; k++){
        if((pricePredictions[k] = (float*) malloc(number_housings_test * sizeof(float))) == NULL){
            fprintf(stderr, "Error memory allocation\n");
            exit(1);
        }
    }

    /* Entrée des bornes de recherche de k */

    printf("\nEntrez les bornes du k qui va être testé. Evitez un interval de plus de 25 entre les bornes.\n");
    printf("Un k allant de 1 à 10 implique une durée d'execution du programme de environ 1 min.\n");
    printf("Entrez le k minimum testé, la valeur de k doit être entre 1 et le nombre de logements d'entrainements :\n");
    int min_k = inputInt(1, number_housings_training);
    printf("Entrez le k maximum, la valeur entrée doit être entre le k minimum testé entré précedement et le nombre de logements d'entrainements :\n");
    int max_k = inputInt(min_k, number_housings_training);
    int number_k = max_k - min_k + 1;

    int maeArrayLenght = number_charac_dist * number_k;

    if((maeArray = (RegisterMae*) malloc(maeArrayLenght * sizeof(RegisterMae))) == NULL){
        fprintf(stderr, "Error memory allocation\n");
        exit(1);
    }

    /* Remplissage des tableaux de logement à partir des fichiers */
    housingArrayFilling(PATH_HOUSING_ARRAY_TRAINING_CSV, housingsArrayTraining, characteristicsIndex);
    housingArrayFilling(PATH_HOUSING_ARRAY_TEST_CSV, housingsArrayTest, characteristicsIndex);

    clock_t timeStart = clock();
    float temps_sec = 0;

    printf("\nDébut de la recherche.\n");

    /* Boucle permettant de rechercher le k et la carcatéristique les plus interessants */

    for(int k = min_k; k <= max_k; k++){
        for(int i = 0; i < number_housings_test; i++){
            calculateDistance(housingsArrayTraining, number_housings_training, housingsArrayTest[i], characteristicsForCalcDist, number_charac_dist);
            shuffleHousingsArray(housingsArrayTraining, number_housings_training);
            for(int c = 1; c <= number_charac_dist; c++){
                sortHousingArray(housingsArrayTraining, number_housings_training, c);
                pricePredictions[c-1][i] = pricePrediction(housingsArrayTraining, number_housings_training, k);
            }
        }
        for(int c = 1; c <= number_charac_dist; c++){
            mae = calculateMAE(housingsArrayTest, number_housings_test, pricePredictions[c-1]);
            registerMae.mae = mae;
            registerMae.characteristic_num = c;
            registerMae.k = k;
            maeArray[(number_charac_dist*(k-min_k))+c-1] = registerMae;
        }
    }
    qsort(maeArray, maeArrayLenght, sizeof(RegisterMae), maeComparator);
    maeFile(maeArray, maeArrayLenght, characteristicsForCalcDist);
    registerMae_min = maeArray[0];

    clock_t timeEnd = clock();
    temps_sec = (double)(timeEnd - timeStart) / (double)CLOCKS_PER_SEC;
    printf("\nLe temps de détermination des de la caractéristique et de la valeur de k les plus optimisés est de %f\n\n", temps_sec);

    printf("Après le calcul de la MAE, le modèle le plus interessant est celui selon la caractéristique %s avec une valeur de k = %d.\n", characteristicsForCalcDist[registerMae_min.characteristic_num-1], registerMae_min.k);   

    /* Prédiction des prix des logements du fichier test avec la caractéristique et le k trouvé */
    for(int i = 0; i < number_housings_test; i++){
        calculateDistance(housingsArrayTraining, number_housings_training, housingsArrayTest[i], characteristicsForCalcDist, number_charac_dist);
        shuffleHousingsArray(housingsArrayTraining, number_housings_training);
        sortHousingArray(housingsArrayTraining, number_housings_training, registerMae_min.characteristic_num);
        pricePredictions[0][i] = pricePrediction(housingsArrayTraining, number_housings_training, registerMae_min.k);
    }
    pricePredictedFile(pricePredictions[0], housingsArrayTest, number_housings_test);
}