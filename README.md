# Prediction-Prix-Airbnb

## Introduction

Ce programme à deux objectifs. le premier est de pouvoir déterminer un prix approprié à un logement et le second est de déterminer la caractéristique et la valeur de k permttant de prédir avec le plus de précision le prix d'un logement.

Ainsi lors de son lancement, le programme commance par demander à l'utilisateur ce qu'il veut faire.

## Prédire un prix

Pour déterminer un prix, le programme commence par demander la caractéritique utilisée à la comparaison avec les autre logements dont le prix et connu ainsi que la valeur de k qui représente la précision de la prédiction.

Ensuite els différentes caractéristiques du logement dont le prix est a déterminer sont entrées. le prix va alors être estimé.

## Détermination du meilleur model

Pour cela, le programme va demander les bornes de l'intervalle dans lequel k va être cherché. Cela permet un plus grand contrôl de la recherche et également puisque cela peut prendre du temps, cela permet également de centrer la recherche sur un intervalle précis et voulu.

Ensuite le programme va lancer la recherche. Cette dernière peut prendre du temps, par exemple sur un intervalle entre 1 et 10, cela peut prendre environ 1 min.

Finalement le programme va nous indiquer grâce à la MAE la caractéristique et le k le plus interessant et prédisant le prix d'un logement avec le plus de précision. 

Aussi un fichier va être généré avec toutes les MAE permettant de voir les caractéristiques et les k les plus interessants parmis toutes les combinaisons. Et un second fichier est généré avec les prix donné et le prix prédit du fichier de test permettant de voir l'efficacité de la meilleur conbinaison de prédiction.
