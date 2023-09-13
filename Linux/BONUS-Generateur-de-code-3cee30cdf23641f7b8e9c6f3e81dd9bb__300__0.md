# BONUS - Générateur de code

### Liste de bonus à faire, non exhaustifs. Vous pouvez en selectionner un ou plusieurs, ou rajouter vos propres fonctionnalités si vous les trouver pertinentes, seule la gestion d’erreurs sera obligatoire d’ici à la fin du projet

1. **Personnalisation du Type d'Attributs :** Avant de générer la classe, demandez à l'utilisateur de spécifier le type des attributs qu'il souhaite inclure dans la classe. Vous pouvez permettre à l'utilisateur de saisir le type pour chaque attribut individuellement ou de spécifier un type global pour tous les attributs. Voici comment vous pouvez implémenter cette fonctionnalité dans votre programme :
    - Avant de générer la classe, demandez à l'utilisateur de spécifier le type des attributs. Vous pouvez utiliser la saisie standard pour cela.
    - Si l'utilisateur souhaite spécifier un type global pour tous les attributs, demandez-lui de le faire une seule fois.
    - Si l'utilisateur souhaite spécifier un type pour chaque attribut individuellement, demandez-lui de le faire pour chaque attribut en utilisant une boucle ou une série de saisies séparées.
    - Assurez-vous que le programme généré tienne compte du type spécifié par l'utilisateur lors de la création des attributs dans la classe.
    - Si l'utilisateur souhaite conserver le type par défaut pour certains attributs, proposez une option pour cela.
    - Une fois que l'utilisateur a spécifié les types des attributs, générez la classe avec les types corrects.
    
2. **Validation des Entrées Utilisateur :** Ajoutez une validation des entrées utilisateur pour vous assurer que les types d'attributs spécifiés sont valides. Par exemple, vérifiez que les types saisis correspondent à des types de données C++ valides.
3. **Génération de Commentaires :** Ajoutez une fonctionnalité qui génère automatiquement des commentaires de documentation pour la classe générée. Cela inclut la génération de commentaires pour les méthodes, les constructeurs et les attributs.
4. **Héritage :** Offrez la possibilité à l'utilisateur de spécifier si la classe générée doit hériter d'une autre classe. Si oui, demandez-lui de fournir le nom de la classe parente et générez la classe en conséquence.
5. **Regles Makefile** : Ajoutez des règles au Makefile (run, fclean, etc…)
6. **Gestion des Erreurs :** Implémentez une gestion des erreurs robuste pour gérer les éventuelles erreurs lors de la génération de la classe ou des fichiers. Informez l'utilisateur en cas d'échec de la génération et fournissez des informations utiles pour le débogage.
7. **Sauvegarde du Projet :** Ajoutez une option permettant de sauvegarder l'ensemble du projet généré (les fichiers .h, .cpp, le Makefile, etc.) dans un dossier spécifié par l'utilisateur. Cela permettra à l'utilisateur de conserver une copie du projet généré pour une utilisation ultérieure.
8. **Gestion des Noms de Fichiers :** Demandez à l'utilisateur de spécifier un nom de projet ou un préfixe de nom de fichier. Utilisez ce nom pour générer automatiquement les noms de fichiers (par exemple, mon_projet.h, mon_projet.cpp, etc.). Cela permettra de personnaliser davantage la structure des fichiers générés.
9. **Héritage Multiple :** Offrez la possibilité à l'utilisateur de spécifier si la classe générée doit utiliser l'héritage multiple et, le cas échéant, lui permettre de sélectionner plusieurs classes parentes.
10. **Gestion de la Visibilité :** Demandez à l'utilisateur de spécifier la visibilité (public, protected, private) des membres de la classe (attributs et méthodes) et générez la classe avec ces spécifications.
11. **Génération de Méthodes Supplémentaires :** En plus des méthodes getters et setters générées par défaut, demandez à l'utilisateur s'il souhaite ajouter des méthodes supplémentaires à la classe et générez-les en conséquence.
12. **Documentation de Code :** Ajoutez une fonctionnalité qui génère automatiquement des commentaires de documentation dans les fichiers de classe, y compris des descriptions pour les membres de la classe, les paramètres des méthodes, etc. Cela aidera les utilisateurs à comprendre rapidement l'utilisation de la classe générée.