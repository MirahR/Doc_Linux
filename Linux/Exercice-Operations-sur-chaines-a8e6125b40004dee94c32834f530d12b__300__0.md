# Exercice - Opérations sur chaînes

Dans cet exercice, vous allez mettre en pratique les différentes opérations sur les chaînes de caractères en C++ en créant un programme de manipulation de noms de film.

Étape 1 :
Créez une chaîne de caractères `film1` en utilisant la classe `std::string` du C++ standard Library, qui contient le nom du film : "Bienvenue à Zombieland".

Étape 2 :
Créez une autre chaîne de caractères `film2` en utilisant la classe `std::array` ou `std::vector` de caractères de la bibliothèque standard, qui contient le nom du film : "Pirate des Caraibes".

Étape 3 :
Concaténez les noms de films contenus dans les variables `film1` et `film2`, en utilisant à la fois l'opérateur `+` et la méthode `append()` , et affectez les résultats à deux nouvelles chaînes de caractères `film_concate_1` et `film_concate_2`. Assurez-vous de séparer les noms de films par un caractère de saut de ligne: ('\n').

Étape 4 :
Affichez la longueur de la chaîne `film_concate_1` et `film_concate_2` . Veuillez noter que les deux chaînes doivent avoir la même longueur.

Étape 5 :
Comparez les chaînes de caractères `film_concate_1` et `film_concate_2` en utilisant l'opérateur `==` et affichez les résultats. En outre, comparez-les en utilisant la méthode `compare()` et affichez les résultats. Les résultats de ces deux comparaisons doivent être identiques.

Étape 6 :
En utilisant l'opérateur `!=`, vérifiez si les chaînes `film1` et `film2` sont différentes, et affichez les résultats de la comparaison.

Le programme doit afficher la concaténation des noms de films, la longueur des chaînes résultantes, les résultats des comparaisons entre les chaînes, ainsi que le résultat de la vérification effectuée à l'étape 6.