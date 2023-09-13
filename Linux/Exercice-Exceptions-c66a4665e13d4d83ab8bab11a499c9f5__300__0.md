# Exercice - Exceptions

## TP: Gestion des erreurs avec des exceptions en C++

Dans cet exercice, vous allez mettre en pratique les notions d'exceptions pour gérer les erreurs dans le langage C++. Vous devez écrire un programme qui gère les opérations arithmétiques de base et les erreurs associées à ces opérations.

Voici les instructions pour votre programme :

1. Créez une fonction `int divise(int numerateur, int denominateur)` qui divise deux entiers (`numerateur` et `denominateur`). Cette fonction doit lancer une exception de type `std::runtime_error` si le dénominateur est égal à zéro.
2. Dans la fonction `main`, utilisez la structure `try` pour appeler la fonction `divise`. Affichez le résultat si l'opération de division est effectuée avec succès.
3. Utilisez la structure `catch` pour capturer l'exception lancée par la fonction `divise`. Affichez un message d'erreur approprié si une exception est capturée.
4. Testez votre programme avec différents ensembles de valeurs pour le numérateur et le dénominateur (y compris des cas où le dénominateur est égal à zéro).

Voici un exemple d'affichage de votre programme:

```
Entrez le numerateur: 10
Entrez le denominateur: 2
Resultat: 5

Entrez le numerateur: 5
Entrez le denominateur: 0
Erreur: Division par zero detectee.

```