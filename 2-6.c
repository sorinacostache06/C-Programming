#include <stdio.h>

int setbits(int x, int p, int n, int y)
{
    int pre_x, pre_y;
    pre_x = x & ~ (~ (~0 << n) << (p + 1 - n)); 
    pre_y = (y & ~ (~0 << n)) << (p + 1 - n); 
    return (pre_x | pre_y);
}

int main()
{
    printf("%d\n", setbits(4, 2, 2, 7));
}
