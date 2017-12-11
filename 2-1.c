#include <stdio.h>
#include <math.h>

/*The minimum and maximum range of a signed type is given by -
-(2^(N-1) to 2^(N-1) - 1 (Where N is sizeof(type) * 8 i.e. total number of bits used by the type)

The minimum and maximum range of an unsigned type is given by -
0 to 2^n - 1*/

int min_signed(int n)
{
    return (-1) * pow(2, (n-1));
}

int max_signed(int n)
{
    return pow(2, n-1) - 1;
}

int max_unsigned(int n)
{
    return pow(2, n) - 1;
}

int main()
{   
    printf("%d\n",sizeof(int)*8);
    printf("Minimum range for signed char: %d\n", min_signed(sizeof(char)*8));
    printf("Maximum range for signed char: %d\n", max_signed(sizeof(char)*8));
    printf("Minimum range for unsigned char: %d\n", 0);
    printf("Maximum range for unsigned char: %d\n", max_unsigned(sizeof(char)*8));

    printf("Minimum range for signed short: %d\n", min_signed(sizeof(short)*8));
    printf("Maximum range for signed short: %d\n", max_signed(sizeof(short)*8));
    printf("Minimum range for unsigned short: %d\n", 0);
    printf("Maximum range for unsigned short: %d\n", max_unsigned(sizeof(short)*8));

    printf("Minimum range for signed int: %d\n", min_signed(sizeof(int)*8));
    printf("Maximum range for signed int: %d\n", max_signed(sizeof(int)*8));
    printf("Minimum range for unsigned int: %d\n", 0);
    printf("Maximum range for unsigned int: %d\n", max_unsigned(sizeof(int)*8));

    printf("Minimum range for signed long: %d\n", min_signed(sizeof(long)*8));
    printf("Maximum range for signed long: %d\n", max_signed(sizeof(long)*8));
    printf("Minimum range for unsigned long: %d\n", 0);
    printf("Maximum range for unsigned long: %d\n", max_unsigned(sizeof(long)*8));
    return 0;
}
