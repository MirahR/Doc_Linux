#! /bin/sh -xv

# affecte une variable var aux arguments $@
for var in $@
# récupère la variable var dans le fichier des utilisateurs
# -d: délimiteur :
# récupère le champ 1, 6 et 7
	do grep $var /etc/passwd | cut -d: -f1,6,7
	done
	
