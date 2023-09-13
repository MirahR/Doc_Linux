# Exercice - Pair ou non

Énoncé de TP : Les Templates de fonctions en C++

Objectif : Dans cet exercice, vous allez créer et utiliser un template de fonction pour implémenter une fonction générique "pairOuNon" qui détermine si un nombre est pair ou non, sans distinction de type de nombre (entier, flottant, etc.).

Instructions :

1. Utilisez la syntaxe appropriée pour créer un template de fonction appelé "pairOuNon" qui prend en entrée un argument générique de type T.
2. Implémentez la fonction "pairOuNon" pour qu'elle retourne vrai (true) si le nombre passé en argument est pair, et faux (false) sinon. Vous devez utiliser l'opérateur modulo (%) pour déterminer si le nombre est pair. 
3. Testez votre fonction "pairOuNon" avec différents types de nombres (comme int, float et double) et différentes valeurs.

Conseils : Veillez à utiliser correctement les mots-clés "template" et "typename" ou "class" pour définir le template de fonction. Afin de tester votre fonction "pairOuNon", assurez-vous d'ajouter un main() dans votre programme pour appeler la fonction avec différentes valeurs et vérifier les résultats.