#!/bin/sh
echo "보고 싶은 파일명을 입력하세요."
read fname
if [ -f $fname ] && [ -s $fname ] && [ -r $fname ]
then
	head -5 $fname
else
	echo "파일이 없거나, 크기가 0이거나, 읽기권한이 없습니다."
	exit 1
fi
exit 0
