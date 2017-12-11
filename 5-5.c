#include <stdio.h>

void my_strncpy(char *s, char *t, int n)
{
    while ((n--) && (*s++ = *t++))
        ;
}

int my_strncmp(char *s, char *t, int n)
{
       for ( ; *s == *t && (--n); s++, t++) 
           if (*s == '\0') 
               return 0; 
       return *s - *t; 
}

void my_strncat(char *s, char *t, int n)
{
    while (*s++ != '\0')
        ;
    *s--;
    while (--n && (*t != '\0'))
        *s++ = *t++;
}

int main()
{
    int r;
    char s[] = "destination", t[] = "source";
  
    my_strncat(s,t,3);
    printf("%s\n",s);
    return 0;
}
