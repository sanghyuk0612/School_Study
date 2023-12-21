#include<stdio.h>
main(){
	int i ,sum1 =0;
	FILE *f1;

	f1 = fopen("int_data.bin","w");
	for(i=10;i<15;i++)
		putw(i,f1);
	fclose(f1);
	f1 = fopen("int_data.bin","r");
	while((i=getw(f1))!=EOF)
	{
		sum1 +=i;
		printf("binary file: i = %d\n",i);
	}
	printf("binary sum = %d",sum1);
	fclose(f1);
}
