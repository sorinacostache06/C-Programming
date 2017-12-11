#include <stdio.h>
#define MAXSTRING 100

void itob(int n, char s[], int b)
{
    int r;
    int i = 0;

    if (b > 1 && b < 17)
    {
         while (n != 0)
        {
            r = n % b;
            n = n / b;
            if ( r < 10)
                s[i++] = r + '0';
            else if ( r == 10)
                s[i++] = 'A';
            else if ( r == 11)
                s[i++] = 'B';
            else if ( r == 12)
                s[i++] = 'C';
            else if ( r == 13)
                s[i++] = 'D';
            else if ( r == 14)
                s[i++] = 'E';
            else if ( r == 15)
                s[i++] = 'F';
        }
        s[i] = '\0';
    }
    else
        printf("You enter a wrong number!");
}

int main()
{
    int n , b;
    char s[MAXSTRING];
    printf("Enter number:\n");
    scanf("%d",&n);
    printf("Enter base:\n");
    scanf("%d",&b);
    itob(n,s,b);
    printf("%s\n",s);
}
