#include <stdio.h> 

int main(int argc, char *fname[]) { 
  char *file1 = fname[1], *file2 = fname[2]; 

  FILE *fp1 = fopen(file1, "r"); 
  FILE *fp2 = fopen(file2, "r"); 
  if (fp1 == NULL || fp2 == NULL) 
    perror("Error:"); 
  while (1) { 
    int char1 = fgetc(fp1); 
    int char2 = fgetc(fp2); 
    if (char1 == EOF && char2 == EOF) break; 
    if (char1 != char2) { 
      printf("%s %s are different.\n",fname[1], fname[2]);
      fclose(fp1); fclose(fp2); 
      return 0; 
    } 
   } 
   printf("They are the same.\n"); 
   fclose(fp1); fclose(fp2); 
   return 0; 
}
