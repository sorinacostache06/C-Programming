#include <stdio.h>

/* Two complement number transform a positiv number in a negativ number:
    1. 0 is replaced with 1 and 1 is replaced with 0
    2. add 1
    (Exemple: 0011 -> 3
              1101 -> -3)
 */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= x - 1)
        b++;
    return b;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("Binar number has %d one bits\n", bitcount(x));
}