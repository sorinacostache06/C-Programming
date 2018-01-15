#include <stdio.h>
#include <time.h>

#define MAXLENGTH 100

int my_binsearch(int x, int a[], int n)
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

int binsearch(int x, int v[], int n) 
{ 
    int low, high, mid; 
    low = 0; 
    high = n - 1; 
    while (low <= high) { 
        mid = (low+high)/2; 
        if (x < v[mid]) 
            high = mid + 1; 
        else if (x  > v[mid]) 
            low = mid + 1; 
        else    /* found match */ 
            return mid; 
    } 
    return -1;   /* no match */ 
} 

int main()
{
    int a[MAXLENGTH];
    int n, x, pos;
    double time_mybs, time_bs;
    clock_t start, end;

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
    
    start = clock();
    pos = my_binsearch(x, a, n);
    end = clock();
    time_mybs = ((double) (end - start)) / CLOCKS_PER_SEC;

    if ( pos == -1)
        printf("Element %d is not found!", x);
    else
        printf("Element %d is on position %d.\n", x, pos);
    
    clock_t t;
    t = clock();
    int res = binsearch(x, a, n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("MyBinsearch took %f seconds to execute \n", time_mybs);
    printf("Binsearch took %f seconds to execute \n", time_taken);

}