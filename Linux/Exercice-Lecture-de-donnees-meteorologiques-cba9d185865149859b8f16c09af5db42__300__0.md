# Exercice - Lecture de données météorologiques

**Exercice : Lecture de données météorologiques**

Imaginez que vous travaillez dans un bureau de météorologie et que vous avez reçu un fichier de données météorologiques d'une station météorologique locale. Le fichier contient des enregistrements quotidiens de la température minimale, maximale et la précipitation pour chaque jour du mois.

Le format du fichier est le suivant :

```python
Jour,TempMin,TempMax,Precipitation
1,10,25,0.2
2,12,27,0
3,9,22,1.5

```

- Le fichier est au format CSV (Comma-Separated Values) avec une ligne d'en-tête.
- Chaque ligne contient la date (Jour), la température minimale (TempMin) en degrés Celsius, la température maximale (TempMax) en degrés Celsius et la précipitation (Precipitation) en millimètres.
- Les valeurs sont séparées par des virgules.

Votre tâche est de créer un programme en C++ qui lira ce fichier, puis calcule et affiche les statistiques suivantes pour le mois :

1. La température minimale moyenne.
2. La température maximale moyenne.
3. Le total des précipitations pour le mois.