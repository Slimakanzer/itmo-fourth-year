#include <stdio.h>

int main () {
   FILE *fp;
  
   fp = fopen("/dev/var5","w+");

   char str[1001];
   int i;
   for (i = 0; i < 1001; i++)
   {
       str[i] = 'A';
   }

   fprintf(fp, str);
   fclose(fp);
   return(0);
}