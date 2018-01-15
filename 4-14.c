#include <stdio.h>
#define swap(t, x, y) ({t aux; aux = x; x = y; y = aux;})

int main()
{
    char a, b;
    int c; 
    scanf("%c", &a);
    scanf("%c", &b);
    scanf("%d", &c);

    if ( c > 0 ) 
        swap(char,a,b);
    else
        printf("%d", c);

    printf("a = %c b = %c", a, b);
}   
