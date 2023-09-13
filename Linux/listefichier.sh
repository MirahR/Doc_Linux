#! /bin/sh


for file in *
do 
type=`file -b $file`
taille=`du -sh $file | cut -f1`
echo $file '\t' $type '\t' $taille
done
#type=`ls -l | cut -c1`
#taille=`ls -l | cut -d' ' -f5- | cut -c1-6`
