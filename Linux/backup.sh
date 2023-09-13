#! /bin/sh 



#daterep=date -r /tmp/backup1.tar.gz

echo "Veuillez sélectionner un choix : \n 1) effectuer un backup \n 2) afficher la liste des backups \n 3) supprimer les anciens backups"

read choix



case $choix in
1) echo effectue un backup
datebackup=`date +%Y-%m-%d`
echo $datebackup
heurebackup=`date +%H-%M-%S`
echo $heurebackup
nombackup=`echo "backup1-"$datebackup"-"$heurebackup`
echo $nombackup
tar zcvf /tmp/backup1/$nombackup.tar.gz /home/mirah

;;
2) echo affiche la liste des backups
ls /tmp/backup1

;;
3) echo supprime les anciens backup

delete=`ls /tmp/backup1 --sort time | tail -n +2`
nbligne=`wc -l`
for i in $(seq 1 $nbligne)
	do rm $delete
	done
ls /tmp/backup1
;;
esac
