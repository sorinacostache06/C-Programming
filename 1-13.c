#include <stdio.h>

int main()
{
    char c;
    printf("Enter text: ");
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            putchar('\n');
        }
        else {
            putchar('-');
        }
    }
    return 0;
}
