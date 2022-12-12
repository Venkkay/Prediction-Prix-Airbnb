/*!
    \file functions_sort.c
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonctions de tri
*/

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "defines.h"
#include "functions_sort.h"


/*!
    \fn int floatComparator0(const void * first, const void * second)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction permettant de comparer le champ 0 du tableau de distance
    \param first Première valeur à comparer
    \param second Seconde valeur à comparer
    \return l'état de la comparaison
*/
int floatComparator0(const void * first, const void * second){
    int stateCmp = 0;
    float firstFloat = ((Housing *)first)->distance[0];
    float secondFloat = ((Housing *)second)->distance[0];
    float diff = firstFloat - secondFloat;

    if(diff < 0) stateCmp = -1;
    else if(diff > 0) stateCmp = 1;
    else stateCmp = 0;

    return stateCmp;
}


/*!
    \fn int floatComparator1(const void * first, const void * second)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction permettant de comparer le champ 1 du tableau de distance
    \param first Première valeur à comparer
    \param second Seconde valeur à comparer
    \return l'état de la comparaison
*/
int floatComparator1(const void * first, const void * second){
    int stateCmp = 0;
    float firstFloat = ((Housing *)first)->distance[1];
    float secondFloat = ((Housing *)second)->distance[1];
    float diff = firstFloat - secondFloat;

    if(diff < 0) stateCmp = -1;
    else if(diff > 0) stateCmp = 1;
    else stateCmp = 0;

    return stateCmp;
}


/*!
    \fn int floatComparator2(const void * first, const void * second)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction permettant de comparer le champ 2 du tableau de distance
    \param first Première valeur à comparer
    \param second Seconde valeur à comparer
    \return l'état de la comparaison
*/
int floatComparator2(const void * first, const void * second){
    int stateCmp = 0;
    float firstFloat = ((Housing *)first)->distance[2];
    float secondFloat = ((Housing *)second)->distance[2];
    float diff = firstFloat - secondFloat;

    if(diff < 0) stateCmp = -1;
    else if(diff > 0) stateCmp = 1;
    else stateCmp = 0;

    return stateCmp;
}


/*!
    \fn int floatComparator3(const void * first, const void * second)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction permettant de comparer le champ 3 du tableau de distance
    \param first Première valeur à comparer
    \param second Seconde valeur à comparer
    \return l'état de la comparaison
*/
int floatComparator3(const void * first, const void * second){
    int stateCmp = 0;
    float firstFloat = ((Housing *)first)->distance[3];
    float secondFloat = ((Housing *)second)->distance[3];
    float diff = firstFloat - secondFloat;

    if(diff < 0) stateCmp = -1;
    else if(diff > 0) stateCmp = 1;
    else stateCmp = 0;

    return stateCmp;
}


/*!
    \fn int floatComparator4(const void * first, const void * second)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction permettant de comparer le champ 4 du tableau de distance
    \param first Première valeur à comparer
    \param second Seconde valeur à comparer
    \return l'état de la comparaison
*/
int floatComparator4(const void * first, const void * second){
    int stateCmp = 0;
    float firstFloat = ((Housing *)first)->distance[4];
    float secondFloat = ((Housing *)second)->distance[4];
    float diff = firstFloat - secondFloat;

    if(diff < 0) stateCmp = -1;
    else if(diff > 0) stateCmp = 1;
    else stateCmp = 0;

    return stateCmp;
}


/*!
    \fn int floatComparator5(const void * first, const void * second)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction permettant de comparer le champ 5 du tableau de distance
    \param first Première valeur à comparer
    \param second Seconde valeur à comparer
    \return l'état de la comparaison
*/
int floatComparator5(const void * first, const void * second){
    int stateCmp = 0;
    float firstFloat = ((Housing *)first)->distance[5];
    float secondFloat = ((Housing *)second)->distance[5];
    float diff = firstFloat - secondFloat;

    if(diff < 0) stateCmp = -1;
    else if(diff > 0) stateCmp = 1;
    else stateCmp = 0;

    return stateCmp;
}


/*!
    \fn int floatComparator6(const void * first, const void * second)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction permettant de comparer le champ 6 du tableau de distance
    \param first Première valeur à comparer
    \param second Seconde valeur à comparer
    \return l'état de la comparaison
*/
int floatComparator6(const void * first, const void * second){
    int stateCmp = 0;
    float firstFloat = ((Housing *)first)->distance[6];
    float secondFloat = ((Housing *)second)->distance[6];
    float diff = firstFloat - secondFloat;

    if(diff < 0) stateCmp = -1;
    else if(diff > 0) stateCmp = 1;
    else stateCmp = 0;

    return stateCmp;
}


/*!
    \fn void sortHousingArray(Housing *housingArray, size_t housingArrayLength, int num_charac_sort)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction de tri du tableau de logements utilisant un switch pour choisir le champ du tableau de ditance à utiliser pour le tri
    \param housingArray Tableau de logements à trier
    \param housingArrayLength Taille du tableau de logements à trier
    \param num_charac_sort Le numero de la caractèristique selon laquelle le tableau est trié
    \return l'état de la comparaison
*/
void sortHousingArray(Housing *housingArray, size_t housingArrayLength, int num_charac_sort){
    switch (num_charac_sort)
    {
    case 1:
        qsort(housingArray, housingArrayLength, sizeof(Housing), floatComparator0);
        break;
    case 2:
        qsort(housingArray, housingArrayLength, sizeof(Housing), floatComparator1);
        break;
    case 3:
        qsort(housingArray, housingArrayLength, sizeof(Housing), floatComparator2);
        break;
    case 4:
        qsort(housingArray, housingArrayLength, sizeof(Housing), floatComparator3);
        break;
    case 5:
        qsort(housingArray, housingArrayLength, sizeof(Housing), floatComparator4);
        break;
    case 6:
        qsort(housingArray, housingArrayLength, sizeof(Housing), floatComparator5);
        break;
    case 7:
        qsort(housingArray, housingArrayLength, sizeof(Housing), floatComparator6);
        break;
    default:
        break;
    }
}


/*!
    \fn int maeComparator(const void * first, const void * second)
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fonction permettant de comparer le tableau de MAE
    \param first Première valeur à comparer
    \param second Seconde valeur à comparer
    \return l'état de la comparaison
*/
int maeComparator(const void * first, const void * second){
    int stateCmp = 0;
    float firstFloat = ((RegisterMae *)first)->mae;
    float secondFloat = ((RegisterMae *)second)->mae;
    float diff = firstFloat - secondFloat;

    if(diff < 0) stateCmp = -1;
    else if(diff > 0) stateCmp = 1;
    else stateCmp = 0;

    return stateCmp;
}