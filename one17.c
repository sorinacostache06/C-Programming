#include <stdio.h>
#define MAXLINE 1000

int getLine(char s[], int lim)
{
    char c;
    int i;

    for (i = 0;  i < lim && (c = getchar()) != EOF && c != '\n'; i++) {
       s[i] = c;      
    }
    if (c == '\n') {
        s[i] = c;
        i++; 
    }
    s[i] = '\0';

    return i;
}

int main()
{
    int len;
    char line[MAXLINE];
    printf("Enter multiple lines\n");
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len >= 80) {
            puts(line);
        }
    }
}