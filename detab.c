#include <stdio.h>

#define TABSTOP 4 
int main()
{
    char c;
    int spaces;
    int pos = 0;
    printf("Enter text:\n");

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            spaces = pos % TABSTOP;
            while (spaces--) {
                putchar('-');
                pos++;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 0;
        }
        else {
            putchar(c);
            pos++;
        }      
    }
}
