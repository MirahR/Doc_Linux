# Exercice - Liste de tâches

**Exercice : Gestion d'une liste de tâches**

**Objectif :** Créez un programme qui permet à l'utilisateur de gérer une liste de tâches à l'aide d'un vecteur.

**Instructions :**

1. Créez une classe **`Tache`** avec les attributs suivants :
    - **`std::string nom`** : le nom de la tâche.
    - **`bool terminee`** : un indicateur indiquant si la tâche est terminée ou non.
2. Créez un vecteur **`listeTaches`** qui stockera des objets de la classe **`Tache`**.
3. Implémentez un menu interactif permettant à l'utilisateur de choisir parmi les options suivantes :
    - Ajouter une nouvelle tâche à la liste.
    - Afficher la liste complète des tâches avec leur état (terminée ou non).
    - Marquer une tâche comme terminée en fonction de son numéro (indice dans le vecteur).
    - Supprimer une tâche de la liste en fonction de son numéro.
    - Quitter le programme.
4. Lorsque l'utilisateur choisit de quitter le programme, enregistrez la liste des tâches dans un fichier texte pour pouvoir la charger lors de la prochaine exécution du programme.

**Bonus :**

- Chargez la liste des tâches à partir du fichier texte au début du programme, si le fichier existe.
- Triez la liste des tâches en fonction de leur état (tâches terminées en premier).