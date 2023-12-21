#include<stdlib.h>
#include<sys/types.h>
#include<stdio.h>

int global =10;
main(){
	int i =20;
	pid_t pid;
	int status;
	if((pid =fork()) ==0){
			global = global+10;
			i= i+10;
	}
	else{
		global = global+100;
		i= i+100;
	}
	printf("global = %d; i= %d\n",global,i);
}
