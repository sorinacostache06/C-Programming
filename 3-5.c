#include <stdio.h>
#include <string.h>
#define MAXSTRING 100

char *strrev(char *str)
{
    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

void itob(int n, char s[], int b)
{
    int r;
    int i = 0;

    if (b > 1 && b < 37)
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
            else if ( r == 16 )
                s[i++] = 'G';
            else if ( r == 17)
                s[i++] = 'H';
            else if ( r == 18)
                s[i++] = 'I';
            else if ( r == 19)
                s[i++] = 'J';
            else if ( r == 20)
                s[i++] = 'K';
            else if ( r == 21)
                s[i++] = 'L';
            else if ( r == 22)
                s[i++] = 'M';
            else if ( r == 23)
                s[i++] = 'N';
            else if ( r == 24)
                s[i++] = 'O';
            else if ( r == 25)
                s[i++] = 'P';
            else if ( r == 26)
                s[i++] = 'Q';
            else if ( r == 27)
                s[i++] = 'R';
            else if ( r == 28)
                s[i++] = 'S';
            else if ( r == 29)
                s[i++] = 'T';
            else if ( r == 30)
                s[i++] = 'U';
            else if ( r == 31)
                s[i++] = 'V';
            else if ( r == 32)
                s[i++] = 'W';
            else if ( r == 33)
                s[i++] = 'X';
            else if ( r == 34)
                s[i++] = 'Y';
            else if ( r == 35)
                s[i++] = 'Z';
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
    strrev(s);
    printf("%s\n",s);
}
