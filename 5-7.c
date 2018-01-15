#include <stdio.h> 
#include <string.h> 
#include <time.h>
#include <stdlib.h>

#define MAXLINES 5000  
#define MAXLEN 1000

char *lineptr[MAXLINES];
char  store_array[MAXLINES];
clock_t start, end;

int readlines(char *lineptr[], int nlines); 
void writelines(char *lineptr[], int nlines); 
void my_qsort(char *lineptr[], int left, int right);      
int  my_getline(char *, int); 
char *alloc(int); 

/* Program with malloc is much faster:
 ana
are
mere
0
ana
are
mere
Program with malloc took 0.000195 seconds to execute

ana
are
mere
0
ana
are
mere
Program with alloc took 0.000255 seconds to execute*/

int main() 
{ 
    double time_malloc;
    start = clock();

    int nlines;    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) { 
        my_qsort(lineptr, 0, nlines-1); 
        writelines(lineptr, nlines); 
        // return 0; 
    } else { 
        printf("error: input too big to sort\n"); 
        // return 1; 
    } 
    end = clock();
    time_malloc = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Program with alloc took %f seconds to execute \n", time_malloc);
} 

int readlines(char *lineptr[], int maxlines) 
{ 
    int len, nlines; 
    char *p, line[MAXLEN]; 
    nlines = 0; 
    while ((len = my_getline(line, MAXLEN)) > 0) 
        if ((nlines >= maxlines) || (p = (char *)malloc(len)) == NULL) 
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

void my_qsort(char *v[], int left, int right) 
{ 
    int i, last; 
    void swap(char *v[], int i, int j); 
    if (left >= right)  
        return;         
    swap(v, left, (left + right)/2); 
    last = left; 
    for (i = left+1; i <= right; i++) 
        if (strcmp(v[i], v[left]) < 0) 
            swap(v, ++last, i); 
    swap(v, left, last); 
    my_qsort(v, left, last-1); 
    my_qsort(v, last+1, right); 
} 
 
   void swap(char *v[],int i,int j)
{
    char *temp;

    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
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

   #define ALLOCSIZE 10000 /* size of available space */ 
   static char allocbuf[ALLOCSIZE]; /* storage for alloc */ 
   static char *allocp = allocbuf;  /* next free position */ 
   char *alloc(int n)    /* return pointer to n characters */ 
   { 
       if (allocbuf + ALLOCSIZE - allocp >= n) {  /* it fits */ 
           allocp += n; 
           return allocp - n; /* old p */ 
       } else      /* not enough room */ 
           return 0; 
   } 
   void afree(char *p)  /* free storage pointed to by p */ 
   { 
       if (p >= allocbuf && p < allocbuf + ALLOCSIZE) 
           allocp = p; 
   } 