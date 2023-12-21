#!/bin/sh

if [ -f $1 ]
then
	head -5 $1
else
	echo "Cannot find $1"
fi
exit 0
