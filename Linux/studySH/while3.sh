#!/bin/sh
echo "y나 Y를 입력하세요."
read mypass
while [ $mypass != "y" ] && [ $mypass != "Y" ]
do
	echo "y나 Y를 입력하세요"
	read mypass
done
echo "통과~~~~"
exit 0

