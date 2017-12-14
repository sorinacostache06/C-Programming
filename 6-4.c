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

struct frequency {
    struct tnode *word;
    struct frequency *left;
    struct frequency *right;
};

struct frequency *first = NULL;

int getword(char *, int);
struct tnode *addtree(struct tnode*, char *);
void printtree(struct tnode*); 
char *my_strdup(char *);
struct frequency *create_binay_frequency(struct tnode*, struct frequency*);
void print_frequency_tree(struct frequency*);
void create(struct tnode*);

int main()
{
    char word[MAXWORD];
    struct tnode *root = NULL;

    while (getword(word, MAXWORD) != -1) 
        if (isalpha(word[0]))
            root = addtree(root, word);

    // printtree(root);
    create(root);
    print_frequency_tree(first);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
    if (p == NULL) {
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

void create(struct tnode *p)
{
    if (p != NULL) {
        create(p->left);
        first = create_binay_frequency(p, first);
        create(p->right);
    }
}

struct frequency *create_binay_frequency(struct tnode *p, struct frequency *f)
{
    if (f == NULL) {
        f = (struct frequency *)malloc(sizeof(struct frequency));
        f->word = p;
        f->left = f->right = NULL; 
    } else if (p->count < f->word->count) {
        f->left = create_binay_frequency(p, f->left);
    } else if ((p->count > f->word->count) || (p->count == f->word->count)) {
        f->right = create_binay_frequency(p, f->right);
    } 
    
    return f;
}

void printtree(struct tnode *p)
{
    if (p != NULL) {
        printtree(p->left);
        printf("%s %d \n", p->word, p->count);
        printtree(p->right);
    }
}

void print_frequency_tree(struct frequency *p)
{
    if (p != NULL) {
        print_frequency_tree(p->right);
        printf("%s %d \n", p->word->word, p->word->count);
        print_frequency_tree(p->left);
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
