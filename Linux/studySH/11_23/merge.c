#include<stdio.h>
#include<string.h>
int main(int argc, char *fname[]){
	int cnt;
	char buffer[10] = {0,};
	char destfile[100] = {0,};
	FILE *src1 = fopen(fname[1],"r");
	FILE *src2 = fopen(fname[2],"r");

	if(argc<3) return -1;
	strcat(destfile, fname[1]);
	strcat(destfile,fname[2]);
	FILE *dest = fopen(destfile, "w");

	if(src1 == NULL || src2 == NULL|| dest ==NULL)
		perror("fopen:");
	while(!feof(src1)){
		cnt = fread(buffer,sizeof(char),10,src1);
		fwrite(buffer,sizeof(char),cnt,dest);
		memset(buffer,0,10);
	}
	while(!feof(src2)){
		cnt = fread(buffer,sizeof(char),10, src2);
		fwrite(buffer,sizeof(char),cnt,dest);
		memset(buffer,0,10);
	}
	fclose(dest);
	fclose(src1);
	fclose(src2);
	return 0;
}
