# Exercice - Surchage d’opérateurs avancés

Énoncé du TP :

Dans cet exercice, vous allez devoir créer une classe Matrice qui représente une matrice de nombres entiers 3x3. Vous allez implémenter les opérateurs avancés de la classe Matrice pour faciliter les manipulations de celle-ci.

Les opérations que vous devez implémenter sont les suivantes :

1. Opérateurs de flux d'entrée/sortie (<<, >>) : Ils permettront d'entrer et d'afficher une matrice de manière élégante. Lors de la saisie, les nombres seront séparés par un espace et lors de l'affichage, les nombres seront affichés en lignes et colonnes avec des barres verticales et horizontales.
2. Opérateur d'appel de fonction (operator ()) : Il permettra d'accéder à un élément de la matrice en utilisant deux arguments d'entiers (ligne et colonne). La matrice commencera à l'indice 1 pour plus de lisibilité. Par exemple, m(2, 3) renverra l'élément à la 2ème ligne et 3ème colonne de la matrice 'm'.
3. Opérateur de conversion de type : Implémentez un opérateur de conversion qui convertit une matrice en une chaîne de caractères. La chaîne doit contenir les valeurs de chaque élément de la matrice, séparées par des virgules et entre crochets. Par exemple, pour une matrice m, la chaîne résultante sera : "[1, 2, 3],[4, 5, 6],[7, 8, 9]".

Exemple d'utilisation :

```cpp
int main() {
    Matrice m;

    // Saisie et affichage de la matrice
    std::cin >> m;
    std::cout << "La matrice saisie est : " << std::endl;
    std::cout << m << std::endl;

    // Accéder à un élément de la matrice et l'afficher
    int element = m(1, 2); // Récupère l'élément en (1, 2)
    std::cout << "L'élément en (1, 2) est : " << element << std::endl;

    // Conversion de la matrice en chaîne de caractères
    std::string str_m = static_cast<std::string>(m);
    std::cout << "La matrice en chaîne de caractères est : " << str_m << std::endl;

    return 0;
}

```

Assurez-vous de bien comprendre et implémenter chaque opérateur selon sa description. Testez votre code avec plusieurs matrices pour vérifier que vos opérateurs fonctionnent correctement.