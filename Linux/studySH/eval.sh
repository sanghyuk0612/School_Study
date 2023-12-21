#!/bin/sh
str="ls -l eval.sh"
echo $str
eval $str
echo $(ls -l eval.sh)
exit 0
