#! /bin/sh -xv

encadre()
texte=`$1`
longueur=`$texte | wc -L `
{ for i in seq(1 longueur)
	do nb=`longueur / 2`
	echo "* "
done

echo "*" $texte "*"

echo "*" "*"


}
