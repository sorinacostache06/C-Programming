#include <stdio.h>

int main()
{
    char c;
    printf("Enter text:\n");
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('-');
        }
        else
        {
            putchar(c);
        }
    }
}