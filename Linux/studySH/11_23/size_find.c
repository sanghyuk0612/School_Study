#include<stdio.h>
int main(int argc, char* fname[]){
	int size;
	FILE *f1 = fopen(fname[1],"r");
	fseek(f1,0,SEEK_END);
	size = ftell(f1);
	printf("size is %d\n",size);
	fclose(f1);
}
	

