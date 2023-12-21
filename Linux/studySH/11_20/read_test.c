#include<stdio.h>
main(){
	FILE *f1;
	char c;
	f1 = fopen("INPUT","w");

	while((c=getchar())!= EOF)
		putc(c,f1);
	fclose(f1);
	f1=fopen("INPUT","r");
	while((c=getc(f1))!=EOF)
		printf("%c",c);
	fclose(f1);
	return 0;
}
