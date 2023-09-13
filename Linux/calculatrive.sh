#! /bin/sh -xv
set -o noglob

echo "Entrez un nombre" ; read nb1 ; echo $nb1
echo "Entrez un opérateur" ; read op ; echo $op
echo "Entrez un autre nombre" ; read nb2 ; echo $nb2

 
result=`expr $nb1 $op $nb2`

echo $result 

