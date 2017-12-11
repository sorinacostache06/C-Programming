#include <stdio.h> 
#include <string.h> 

#define MAXLINES 5000  
#define MAXLEN 1000

char *lineptr[MAXLINES];
char  store_array[MAXLINES];

int readlines(char *lineptr[], char *store_array, int nlines); 
void writelines(char *lineptr[], int nlines); 
void qsort(char *lineptr[], int left, int right);      
int  my_getline(char *, int); 

int main() 
{ 
    int nlines;    
    if ((nlines = readlines(lineptr, store_array, MAXLINES)) >= 0) { 
        qsort(lineptr, 0, nlines-1); 
        writelines(lineptr, nlines); 
        return 0; 
    } else { 
        printf("error: input too big to sort\n"); 
        return 1; 
    } 
} 

int readlines(char *lineptr[], char *store_array, int maxlines) 
{ 
    int len, nlines; 
    char *p = store_array, line[MAXLEN]; 
    nlines = 0; 
    char *maxline = store_array + MAXLEN;

    while ((len = my_getline(line, MAXLEN)) > 0) 
        if (nlines >= maxlines || p + len > maxline) 
            return -1; 
        else { 
            line[len-1] = '\0'; 
            strcpy(p, line); 
            lineptr[nlines++] = p; 
            p = p + len;
        } 
    return nlines; 
} 

void writelines(char *lineptr[], int nlines) 
{ 
    int i; 
    for (i = 0; i < nlines; i++) 
        printf("%s\n", lineptr[i]); 
}

void qsort(char *v[], int left, int right) 
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
    qsort(v, left, last-1); 
    qsort(v, last+1, right); 
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
