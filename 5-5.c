#include <stdio.h>
#include <string.h>

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

char *my_strncat(char *dest, char *source, int n)
{
    char *aux = dest;
    while (*dest)
        dest++;

    while(n--) {
        if ((*dest++ = *source++) == '\0')
            return aux;
    }
    *dest = 0;
    return aux;
}

int main()
{
    char s[] = "destination", t[] = "source";
    printf("%s\n",my_strncat(s,t,3));
    return 0;
}
