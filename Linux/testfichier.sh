#! /bin/bash
echo $1
[ -z $1 ] && echo "cet argument est vide" && exit 1
[ ! -f $1 ] && echo "argument nest pas un fichier" && exit 2
[ ! -x $1 ] && [ -r $1 ] && [ -w $1 ] && echo "lecture du fichier :" && cat $1
[ ! -x $1 ] && [ ! -r $1 ] || [ ! -w $1 ] && echo "lecture impossible" && exit 3
[ -x $1 ] && echo "code 0: lancement du programme" $1 && ./$1 && echo "SUCCESS" && exit 4



