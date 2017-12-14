#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int type_sort);
int numcmp(char *, char *);
int my_getline(char *,int);
char *alloc(int);

int main(int argc, char *argv[])
{
    int numeric = 0;
    int nlines;
    int reverse_sort = 0;
    if (argc > 1 && strcmp(argv[1],"-n") == 0 ) {
        numeric = 1;
    }

    if (argc > 1 && strcmp(argv[1],"-r") == 0 ) {
        reverse_sort = 1;
    }

    if (argc > 2 && strcmp(argv[2],"-r") == 0) {
        reverse_sort = 1;
    }
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        my_qsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp), reverse_sort);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *), int type_sort) 
{ 
    int i, last; 
    void swap(void *v[], int, int); 
    if (left >= right)    
        return;           
    swap(v, left, (left + right)/2); 
    last = left; 
    
    for (i = left+1; i <= right;  i++) 
        if (type_sort == 0) {
            if ((*comp)(v[i], v[left]) < 0) 
                swap(v, ++last, i);
        } else {
            if ((*comp)(v[i], v[left]) > 0) 
                swap(v, ++last, i);
        }
             
    swap(v, left, last); 
    my_qsort(v, left, last-1, comp, type_sort); 
    my_qsort(v, last+1, right, comp, type_sort); 
} 

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else return 0;
}

void swap(void *v[], int a, int b)
{
    void *temp;
    temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int readlines(char *lineptr[], int maxlines) 
{ 
    int len, nlines; 
    char *p, line[MAXLEN]; 
    nlines = 0; 
    while ((len = my_getline(line, MAXLEN)) > 0) 
        if ((nlines >= maxlines) || (p = alloc(len)) == NULL) 
            return -1; 
        else { 
            line[len-1] = '\0';  
            strcpy(p, line); 
            lineptr[nlines++] = p; 
        } 
    return nlines; 
} 

void writelines(char *lineptr[], int nlines) 
{ 
    int i; 
    for (i = 0; i < nlines; i++) 
        printf("%s\n", lineptr[i]); 
} 

int my_getline(char *s,int lim)
{
    int c;
    char *t=s;

    while(--lim >0 && (c=getchar())!='0' && c!='\n')
        *s++ = c;
    if( c == '\n')
        *s++ = c;

    *s= '\0';

    return s-t;
}

#define ALLOCSIZE 10000 
static char allocbuf[ALLOCSIZE]; 
static char *allocp = allocbuf;  

char *alloc(int n)    
{ 
    if (allocbuf + ALLOCSIZE - allocp >= n) {   
        allocp += n; 
        return allocp - n; 
    } else      
        return 0; 
} 
