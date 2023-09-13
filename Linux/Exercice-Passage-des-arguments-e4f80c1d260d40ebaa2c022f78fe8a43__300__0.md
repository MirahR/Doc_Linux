# Exercice - Passage des arguments

Énoncé du TP :

Dans cet exercice, votre objectif est de créer un programme qui illustre les différentes méthodes de passage d'arguments en C++ : le passage par valeur et le passage par référence. Pour cela, vous allez devoir créer deux fonctions distinctes qui calculeront la somme et le produit de deux nombres entiers.

1. Écrivez une fonction `sommeParValeur` qui prend deux arguments entiers a et b par valeur et retourne la somme de ces deux nombres. Cette fonction ne doit pas modifier les valeurs des arguments reçus.
2. Écrivez une autre fonction `produitParReference` qui prend deux arguments entiers a et b par référence et modifie directement la valeur de a pour stocker le produit de a et b. La fonction ne retourne aucune valeur.

Dans la fonction main, vous devez faire ce qui suit :

- Demandez à l'utilisateur de saisir deux nombres entiers.
- Appelez la fonction `sommeParValeur` avec ces deux nombres et affichez le résultat.
- Appelez ensuite la fonction `produitParReference` avec ces deux nombres et affichez la nouvelle valeur de a, qui doit maintenant être le produit des deux nombres.

Voici un exemple de sortie attendue pour votre programme :

```
Entrez un nombre entier: 4
Entrez un autre nombre entier: 5

La somme de 4 et 5 est: 9
Le produit de 4 et 5 est: 20

```