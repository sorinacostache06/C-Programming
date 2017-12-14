#include <stdio.h>

void *calloc(size_t nitems, size_t size)
{
    void *p;
    p = malloc(nitems * size);

    if (p == NULL)
        return p;
    memset(p, 0, nitems);

    return p;
}

int main()
{
    int *p;
    p = (int *)calloc(20,  sizeof(int));

    for (int i = 0; i <= 20; i++)
        printf("%d ",p[i]);
}