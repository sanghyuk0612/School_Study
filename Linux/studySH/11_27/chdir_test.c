#include<unistd.h>
#include<stdio.h>

int main(void){
	if (chdir("/tmp")<0){
		perror("chdir");
		exit(1);
	}
	printf("chdir to /tmp succeeded\n");
}
