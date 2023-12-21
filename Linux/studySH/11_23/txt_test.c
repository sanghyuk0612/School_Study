#include<stdio.h>
main(){
	int i ,sum2 =0;
	FILE *f2;

	f2 = fopen("int_data.txt","w");
	for(i=10;i<15;i++)
		fprintf(f2,"%d\n",i);
	fclose(f2);
	f2 = fopen("int_data.txt","r");
	while((fscanf(f2,"%d",&i)!=EOF))
	{
		sum2 +=i;
		printf("text file: i = %d\n",i);
	}
	printf("text sum = %d",sum2);
	fclose(f2);
}
