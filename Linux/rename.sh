#! /bin/sh -xv

for var in $@
	do nom=`echo $var | tr 'a-z' 'A-Z'`
		if [ -e $nom ] 
			then echo "Le fichier existe déjà"
			else mv $var $nom
		fi
	done
	
