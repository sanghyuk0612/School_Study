#!/bin/sh
hap=0
for i in $*
do
	hap=`expr $hap + $i`
done
echo "sum= " $hap
echo hap
exit 0
