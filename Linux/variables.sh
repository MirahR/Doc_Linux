#! /bin/sh
echo [HOME] " : nom de votre répertoire d'acceuil : $HOME"
echo [PWD] " : votre répertoire courant : $PWD"
echo [OLDPWD] " : valeur du répertoire précédent un éventuel changement de répertoire : $OLDPWD"
echo [PATH] " : chemin de recherche des commandes : $PATH"
echo [SHELL] " : affiche le programme shell par défaut : $SHELL"
echo [LANG] " : définit la valeur de votre locale en France fr_FR.UTF-8 : $LANG"
echo [ENV] " : cette variable contient le nom d'un fichier qui définit les variables d'environnement à la place du fichier .profile. Ceci permet de plusieurs environnements Exemple : ENV=/$HOME/.setup : $ENV"
echo [DISPLAY] " : nom du serveur X d'affichage : $DISPLAY"
echo [$] " : est le numéro du processus courant : $$"
echo [?] " : est le code retour dune commande 0 si pas d'erreur autre valeur positive d'écrit le code d'erreur : $?"

