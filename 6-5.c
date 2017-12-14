#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define HASHSIZE 101 
#define MAXWORD 100

struct nlist {       
    struct nlist *next;   
    char *name;            
    char *defn;           
}; 


static struct nlist *hashtab[HASHSIZE];  

unsigned hash(char *); 
struct nlist *lookup(char *); 
struct nlist *install(char *, char *); 
int getword(char *, int);
void undef(char *, char *);
void printhash();

int main()
{
    char name[MAXWORD];
    char definition[MAXWORD];

    while ((getword(name, MAXWORD) != -1) && (getword(definition, MAXWORD) != -1)) 
        install(name, definition);

    undef("yes","no");

    printhash();
}

void undef(char *s, char *t)
{
    int hashval, flag = 0, prev;
    hashval = hash(s);

    if (hashtab[hashval]) {
        struct nlist *np = (struct nlist *) malloc(sizeof(*np)); 
        np = hashtab[hashval];
        if (strcmp(hashtab[hashval]->name, s) == 0 && strcmp(hashtab[hashval]->defn, t) == 0) {
            hashtab[hashval] = np->next;
            free(np->name);
            free(np->defn);
            free(np);
        }
    }
}

void printhash()
{
    for (int i = 0; i <= HASHSIZE; i++) 
        if (hashtab[i] != NULL)
            printf("%d %s %s\n", i, hashtab[i]->name, hashtab[i]->defn);
}

/* hash:  form hash value for string s */ 
unsigned hash(char *s) 
{ 
    unsigned hashval; 
    for (hashval = 0; *s != '\0'; s++) 
        hashval = *s + 31 * hashval; 
    return hashval % HASHSIZE; 
} 

/* lookup:  look for s in hashtab */ 
struct nlist *lookup(char *s) 
{ 
    struct nlist *np; 
    for (np = hashtab[hash(s)];  np != NULL; np = np->next) 
        if (strcmp(s, np->name) == 0) 
            return np;     /* found */ 
    return NULL;           /* not found */ 
} 

/* install:  put (name, defn) in hashtab */ 
struct nlist *install(char *name, char *defn) 
{ 
    struct nlist *np; 
    unsigned hashval; 
    if ((np = lookup(name)) == NULL) { /* not found */ 
        np = (struct nlist *) malloc(sizeof(*np)); 
        if (np == NULL || (np->name = strdup(name)) == NULL) 
            return NULL; 
        hashval = hash(name); 
        np->next = hashtab[hashval]; 
        hashtab[hashval] = np; 
    } else       /* already there */ 
        free((void *) np->defn);   /*free previous defn */ 
    if ((np->defn = strdup(defn)) == NULL) 
        return NULL; 
    return np; 
} 

int getword(char *word, int lim) 
{ 
    int c, getch(void); 
    void ungetch(int); 
    char *w = word; 
    if ( c == '0')
        return -1;
    while (isspace(c = getch())) 
        ; 
    if (c != EOF) 
        *w++ = c; 
    if (!isalpha(c)) { 
        *w = '\0'; 
        return c; 
    } 
    for ( ; --lim > 0; w++) 
        if (!isalnum(*w = getch())) { 
            ungetch(*w); 
            break; 
        }
    *w = '\0'; 
    return word[0]; 
} 

#define BUFSIZE 100 
char buf[BUFSIZE];    
int bufp = 0;        
int getch(void) 
{ 
    return (bufp > 0) ? buf[--bufp] : getchar(); 
} 
void ungetch(int c)   
{ 
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n"); 
    else 
        buf[bufp++] = c; 
} 
