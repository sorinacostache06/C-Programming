#include <stdio.h>
#include <string.h>

int main()
{    
    char c;

    printf("Enter text: ");

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else {
            putchar(c);
        }
    }
    return 0;
}
