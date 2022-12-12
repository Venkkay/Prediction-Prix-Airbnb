/*!
    \file functions_sort.h
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fichier d'en tête des fonctions de fonctions_sort.c
*/
#ifndef FUNCTIONS_SORT_H
#define FUNCTIONS_SORT_H

int floatComparator0(const void * first, const void * second);
int floatComparator1(const void * first, const void * second);
int floatComparator2(const void * first, const void * second);
int floatComparator3(const void * first, const void * second);
int floatComparator4(const void * first, const void * second);
int floatComparator5(const void * first, const void * second);
int floatComparator6(const void * first, const void * second);
void sortHousingArray(Housing *housingArray, size_t housingArrayLength, int num_charac_sort);
int maeComparator(const void * first, const void * second);

#endif