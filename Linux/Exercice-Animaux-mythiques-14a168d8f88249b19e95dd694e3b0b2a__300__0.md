# TP - Animaux mythiques

**Énoncé :** Le monde fantastique des animaux mythiques

Imaginez un monde fantastique peuplé d'animaux mythiques tels que les dragons, les licornes et les griffons. Créez une hiérarchie de classes en utilisant l'héritage en C++ pour représenter ces créatures. Chaque créature mythique a certaines caractéristiques communes, mais elles possèdent également des attributs et des comportements spécifiques à leur espèce.

1. Créez une classe de base appelée **`CreatureMythique`** avec les attributs suivants :
    - **`nom`** (une chaîne de caractères)
    - **`taille`** (un double)
    - **`pouvoir`** (une chaîne de caractères)
2. Définissez un constructeur pour la classe **`CreatureMythique`** qui permet de spécifier les valeurs initiales de **`nom`**, **`taille`** et **`pouvoir`**.
3. Créez trois classes dérivées : **`Dragon`**, **`Licorne`** et **`Griffon`**. Chacune de ces classes doit hériter de **`CreatureMythique`** et ajouter des attributs spécifiques à l'espèce. Par exemple, un dragon pourrait avoir un attribut **`nombreEcailles`**, une licorne pourrait avoir un attribut **`couleurCriniere`**, et un griffon pourrait avoir un attribut **`vitesseVol`**.
4. Définissez des constructeurs pour les classes dérivées (**`Dragon`**, **`Licorne`**, **`Griffon`**) qui appellent le constructeur de la classe de base (**`CreatureMythique`**) pour initialiser les attributs communs et ajoutent leurs attributs spécifiques.
5. Implémentez une méthode **`afficherDetails()`** dans chaque classe (y compris la classe de base) qui affiche les détails de la créature mythique, y compris ses attributs spécifiques à l'espèce.
6. Dans la fonction **`main()`**, créez une instance de chaque type de créature mythique (dragon, licorne, griffon) et appelez la méthode **`afficherDetails()`** pour chacune d'elles.