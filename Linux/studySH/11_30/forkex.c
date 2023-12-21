#include<stdio.h>
#include<unistd.h>
int main(void){
	int x;

	x=0;
	fork();
	x =1;
	printf("I am process %Id and my x is %d\n",(long)getpid(),x);
	return 0;
}
