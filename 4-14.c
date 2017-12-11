#include <stdio.h>
#define swap(t, x, y) {t aux; aux = x; x = y; y = aux;}

int main()
{
    char a, b;
    scanf("%c", &a);
    scanf("%c", &b);
    swap(char,a,b);
    printf("a = %c b = %c", a, b);
}
