#!/bin/sh
hap(){
	echo `expr $1 + $2`
}
echo "10 더하기 20을 실행합니다"
hap 10 20
exit 0
