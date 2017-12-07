#include <stdio.h>

char lower(char s)
{
    return (s >= 'A' && s <= 'Z') ? (char)(s += 32) : s;
}

int main()
{
    char c;
    while ((c = getchar()) != EOF)
        putchar(lower(c));
}