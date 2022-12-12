/*!
    \file defines.h
    \author Lucas Velay
    \date 10 décembre 2022
    \brief Fichier de définitions
*/
#ifndef DEFINES_H
#define DEFINES_H

/*!
    \def PATH_SRC
    \brief Chemin du dossier contenant les sources du projet
*/
#define PATH_SRC "src"

/*!
    \def NAME_HOUSING_FILE_DATA_CLEAN_CSV
    \brief Nom du fichier CSV contenant les données propres
*/
#define NAME_HOUSING_FILE_DATA_CLEAN_CSV "airbnb_donnees_propre.csv"

/*!
    \def NAME_HOUSING_FILE_TRAINING_CSV
    \brief Nom du fichier CSV contenant les données d'entrainement
*/
#define NAME_HOUSING_FILE_TRAINING_CSV "airbnbEntrainement.csv"

/*!
    \def NAME_HOUSING_FILE_TEST_CSV
    \brief Nom du fichier CSV contenant les données de test
*/
#define NAME_HOUSING_FILE_TEST_CSV "airbnbTest.csv"

/*!
    \def PATH_HOUSING_ARRAY_DATA_CLEAN_CSV
    \brief Chemin du fichier CSV contenant les données propres
*/
#define PATH_HOUSING_ARRAY_DATA_CLEAN_CSV "../" PATH_SRC "/" NAME_HOUSING_FILE_DATA_CLEAN_CSV

/*!
    \def PATH_HOUSING_ARRAY_TRAINING_CSV
    \brief Chemin du fichier CSV contenant les données d'entrainement
*/
#define PATH_HOUSING_ARRAY_TRAINING_CSV "../" PATH_SRC "/" NAME_HOUSING_FILE_TRAINING_CSV

/*!
    \def PATH_HOUSING_ARRAY_TEST_CSV
    \brief Chemin du fichier CSV contenant les données de test
*/
#define PATH_HOUSING_ARRAY_TEST_CSV "../" PATH_SRC "/" NAME_HOUSING_FILE_TEST_CSV

#endif