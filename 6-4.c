#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *, int);
struct tnode *addtree(struct tnode*, char *);
void printtree(struct tnode*); 
char *my_strdup(char *);

int main()
{
    char word[MAXWORD];
    struct tnode *root;

    while (getword(word, MAXWORD) != -1) 
        if (isalpha(word[0]))
            root = addtree(root, word);
    printtree(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
    if (p == NULL) {
        printf("sfsf");
        p = (struct tnode *)malloc(sizeof(struct tnode));
        p->word = my_strdup(w);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
    } else if (strcmp(p->word, w) == 0) {
        p->count++;
    } else if (strcmp(p->word, w) < 0) {
        p->left = addtree(p->left, w);
    } else if (strcmp(p->word, w) > 0) {
        p->right = addtree(p->right, w);
    }
    return p;
}

void printtree(struct tnode *p)
{
    if (p != NULL) {
        printtree(p->left);
        printf("%s %d \n", p->word, p->count);
        printtree(p->right);
    }
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

char *my_strdup(char *w)
{
   char *p = (char *)malloc(strlen(w) + 1);
    
    if (p != NULL)
        strcpy(p, w);
    return p;
}