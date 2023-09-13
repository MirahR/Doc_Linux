# Exercice - Gestion d’une bibliothèque

Travail Pratique : Gestion d'une bibliothèque

Énoncé :

Vous devez créer un programme C++ pour gérer une bibliothèque. Pour cela, vous allez concevoir une classe "Livre" en utilisant les notions d'introduction aux classes.

Vous devrez créer :

1. La classe "Livre", qui aura les attributs suivants :
    - titre : une chaîne de caractères pour stocker le titre du livre
    - auteur : une chaîne de caractères pour stocker le nom de l'auteur du livre
    - anneePublication : un entier pour stocker l'année de publication du livre
    - nbrPages : un entier pour stocker le nombre de pages du livre
2. Un constructeur pour créer des objets "Livre" en initialisant les attributs avec des valeurs fournies en paramètre.
3. Un destructeur qui affiche un message indiquant que le livre a été supprimé.
4. Des méthodes pour accéder et modifier chacun des attributs :
    - get_titre() et set_titre()
    - get_auteur() et set_auteur()
    - get_anneePublication() et set_anneePublication()
    - get_nbrPages() et set_nbrPages()
5. Une méthode "afficherInfo()" qui affiche les informations du livre sous la forme suivante :
"Titre : [titre], Auteur : [auteur], Année de publication : [anneePublication], Nombre de pages : [nbrPages]"
6. Une méthode "estAncien()" qui retourne un booléen indiquant si le livre est considéré comme ancien (publié il y a plus de 30 ans).
7. Un main() qui crée trois objets Livre avec les informations suivantes :
    - Harry Potter, J.K. Rowling, 1997, 450 pages
    - Les Misérables, Victor Hugo, 1862, 1500 pages
    - Dune, Frank Herbert, 1965, 800 pages

Dans le main, vous allez afficher les informations de chaque livre et indiquer si chaque livre est ancien ou non. N'oubliez pas de tester les méthodes de modification d'attributs pour s'assurer que tout fonctionne correctement.

Bonne chance !

**Bonus 1 : Gestion des emprunts**

- Étendez la classe "Livre" pour inclure un attribut booléen "estEmprunte" pour indiquer si le livre est actuellement emprunté ou non.
- Créez une classe "Emprunteur" qui représente une personne qui peut emprunter des livres. L'Emprunteur peut avoir un nom et une liste de livres empruntés.
- Ajoutez des méthodes pour permettre à un Emprunteur d'emprunter un livre de la bibliothèque et de le retourner.

**Bonus 2 : Recherche de livres**

- Ajoutez une méthode à la classe "Bibliothèque" pour rechercher des livres par titre, auteur, ou année de publication.
- Implémentez une fonction de recherche dans le main pour permettre à l'utilisateur de rechercher des livres dans la bibliothèque en fonction de critères donnés.

**Bonus 3 : Classe Bibliothèque**

- Créez une classe "Bibliothèque" qui peut contenir plusieurs livres. Cette classe peut avoir un vecteur (ou une liste) de livres comme attribut et des méthodes pour ajouter un livre à la bibliothèque, supprimer un livre  et afficher la liste complète des livres.