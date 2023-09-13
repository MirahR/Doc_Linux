
# Projet

Projet de géneration de code
Le projet génere  les fichiers suivants :
Un fichier <nom_de_la_classe>.h contenant le prototype complet d'une  classe entrée par l'utilisateur
Un fichier <nom_de_la_classe>.cpp contenant la déclaration de la classe et les implémentations des méthodes de la classe.
Un fichier main.cpp avec des tests pour la classe générée.
Un fichier Makefile qui compile le projet avec g++.

## Auteurs

- [@Christopher]
- [@Mirah]
- [@Patrice]

## Roadmap

Il reste  à traiter les bonus

## Lancement du programme

Compiler et Lancer le fichier projet.cpp  pour génerer les classes:

```text
 <nom_de_la_classe>.h
 <nom_de_la_classe>.cpp
 main.cpp
 makefile
 ```

commande  pour compiler:

```bash
g++  -o  projet   projet.cpp
```

commande  pour lancer le programme :

```bash
 ./projet   
```

L'utilisateur doit entrer le nom de la classe et choisir le nom des attributs
et leur type

Pour lancer le programme, il faut exécuter make
puis éxécuter make run

```bash
  make  
  make run
```

## Nettoyage  du programme

Ne pas hésiter à faire un  clean avec la commande:

```bash
  make clean
```

## Fonctionnalités

-génerer une classe à partir d'un nom de classe
-possibilité d'entrer des attributs de  type int
-possibilité d'entrer des attributs de  même type
-possibilité d'entrer des attributs de type différents
-génerer les getters et setters d'une classe à partir d' attributs en entrée

## Comportements anormaux du programme

problème au niveau des types  des attributs  de la classe (par exemple lors de la saisie d'un int et d'un string )
