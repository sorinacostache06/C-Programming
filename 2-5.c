#include <stdio.h>

#define MAXSTRING 100

int any(char str1[], char str2[]){
   int i,j;

   for (i = 0;  str2[i] != '\0'; i++) {
        for (j = 0; str1[j] != '\0'; j++) {
            if (str1[j] == str2[i]) {
                return j;
            }
        }
   }
   return -1;
}

int main () {
   char str1[MAXSTRING];
   char str2[MAXSTRING];
   char c;
   int i;

   printf("First string: \n");
   for (i = 0; i <= MAXSTRING && (c = getchar()) != EOF && c != '\n'; i++) 
        str1[i] = c;
    str1[i] = '\0';

   printf("Secound string: \n");
   for (i = 0; i <= MAXSTRING && (c = getchar()) != EOF && c != '\n'; i++) 
       str2[i] = c;
    str2[i] = '\0';

   printf("%d\n", any(str1, str2));

return 0; 
}
