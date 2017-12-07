#include <stdio.h>
#define MAXSTRING 100

void escape(char s[], char t[])
{
    int i = 0;
    int j = 0; 
    while (s[i] != '\0')
    {
        switch (s[i])
        {
            case '\n': 
                s[i++] = '\\';
                s[i++] = 'n';
                break; 
            case '\t': 
                s[i++] = '\\';
                s[i++] = 't';
                break;
            default:
                t[j++] = s[i++];
                break;
        }
    }
    t[j] = '\0';
}

int main()
{
    char str1[MAXSTRING], str2[MAXSTRING];
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && c != '0')
        str1[i++] = c;
    str1[i] = '\0';

    escape(str1, str2);
    printf("S string: %s\n",str1);
    printf("T string: %s\n",str2);
}