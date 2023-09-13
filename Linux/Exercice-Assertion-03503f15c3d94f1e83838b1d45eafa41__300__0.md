# Exercice - Assertion

Travail Pratique : Assertions en C++

Énoncé :

Dans cet exercice, vous allez utiliser les assertions pour vérifier la validité des préconditions et postconditions de fonction. Plus précisément, vous devrez :

1. Créez une fonction appelée "racineCarree" qui prend un nombre entier non négatif "n" en argument et retourne sa racine carrée (également un nombre entier).
2. Utilisez l'assertion "assert" pour vérifier que l'argument "n" est non négatif à l'intérieur de la fonction "racineCarree". Si "n" est négatif, interrompez l'exécution du programme et affichez un message d'erreur.

Instructions :

1. Incluez la bibliothèque "cassert".
2. Implementez la fonction "racineCarree":
    - Vérifiez, à l'aide de "assert", que l'argument "n" est non négatif et affichez un message d'erreur si nécessaire.
    - Calculez la racine carrée entière de "n" et retournez-la.
3. Utilisez "static_assert" pour vérifier la taille du type "int".
4. Dans la fonction "main", testez votre fonction "racineCarree" avec quelques valeurs de "n" valides et une valeur de "n" invalide.
