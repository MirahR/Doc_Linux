#! /bin/sh
mavariable1=1
. ./shell2.sh
echo "ma variable 1 = " $mavariable1
echo "ma variable 2 exportée = " $mavariable2
echo $*
echo $#
echo $1
echo $@
echo $#
echo $$

