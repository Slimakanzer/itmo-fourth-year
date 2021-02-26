#include <stdio.h>

int main () {
   FILE *fp;
   int rc;
  
   fp = fopen("/dev/var5","w+");

   char str[1001];
   int i;
   for (i = 0; i < 1001; i++)
   {
       str[i] = 'A';
   }

   if ((rc = fprintf(fp, str)) < 0)
   {
       printf("Error occour: %d", rc);
   }

   fclose(fp);
   return(0);
}