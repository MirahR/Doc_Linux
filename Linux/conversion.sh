#! /bin/sh -xv
x=$1
h=`expr $x / 3600`
m=`expr $x / 60` 
m=`expr $m % 60`
s=`expr $x % 60`

[ $s -gt 1 ] && sec=secondes || sec=seconde
[ $m -gt 1 ] && min=minutes || min=minute
[ $h -gt 1 ] && heu=heures || heu=heure

echo "il est $h $heu, $m $min et $s $sec"

#if [ $s -gt 1 ]
#then sec=secondes
#else sec=seconde
#fi

#if [ $m -gt 1 ]
#then min=minutes
#else min=minute
#fi

#if [ $h -gt 1 ]
#then heu=heures
#else heu=heure
#fi 

#echo "il est $h $heu, $m $min et $s $sec"



 
