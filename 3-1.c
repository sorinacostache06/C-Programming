#include <stdio.h>
#define MAXLENGTH 100

int binsearch(int x, int a[], int n)
{
    int li, ls, m;
    li = 0;
    ls = n-1;
    m = (li + ls)/2;

    while (li < ls && a[m] != x)
    {
        if (a[m] < x)
            li = m + 1;
        else 
            ls = m - 1;
        m = (li + ls)/2;
    }

    if (a[m] == x)
        return m;
    else 
        return -1;
}

int main()
{
    int a[MAXLENGTH];
    int n, x, pos;

    printf("Search element:\n ");
    scanf("%d", &x);

    printf("Number of elements: \n");
    scanf("%d", &n);

    /*Assume that the input items are sorted*/
    for (int i = 0; i < n; i++)
    {
        printf("\na[%d] = ", i);
        scanf("%d", &a[i]);
    }
    
    pos = binsearch(x, a, n);
    if ( pos == -1)
        printf("Element %d is not found!", x);
    else
        printf("Element %d is on position %d.\n", x, pos);
}