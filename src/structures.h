/*!
    \file structures.h
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fichier de structures
*/
#ifndef STRUCTURES_H
#define STRUCTURES_H

/*!
    \struct Housing
    \brief Structure d'un logement
*/
typedef struct defHousing{
    float accommodates;         /*!<Nombre de places*/
    float bedrooms;             /*!<Nombre de chambres*/
    float bathrooms;            /*!<Nombre de salles de bains*/
    float beds;                 /*!<Nombre de lits*/
    float price;                /*!<Prix*/
    float min_nights;           /*!<Nombre de nuits minimum*/
    float max_nights;           /*!<Nombre de nuits maximum*/
    float number_of_reviews;    /*!<Nombre de reviews*/
    float *distance;            /*!<Tableau des distances*/
}Housing;

/*!
    \struct RegisterMae
    \brief Structure d'un enregistrement de mae
*/
typedef struct defregisterMae{
    float mae;                  /*!<Valeur de la MAE*/
    int characteristic_num;     /*!<Numero de la caractèristique ayant donnée cette MAE*/
    int k;                      /*!<Valeur de k ayant donnée cette MAE*/
}RegisterMae;

#endif