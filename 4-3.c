#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSTRING 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100 

double val[MAXVAL];
int sp = 0;
char buf[BUFSIZE];    
int bufp = 0; 

void push(double);
double pop();
double getop(char []);
int getch(void);
void ungetch(int);

int main()
{
    int type;
    char s[MAXSTRING];
    double aux;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                aux = pop();
                push(pop() - aux);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                aux = pop();
                if (aux != 0)
                    push(pop() / aux);
                else
                    printf("Invalid operation!");
                break;
            case '%':
                aux = pop();
                if (aux != 0)
                    push((int)pop() % (int)aux);
                else
                    printf("Invalid operation!");
                break;
            case '\n': 
               printf("\t%.8g\n", pop()); 
               break; 
            default:
                printf("Unknown command!");
        }
    }
return 0;
}

void push(double f)
{
    if (sp > MAXVAL)
        printf("To many values!");
    else 
        val[sp++] = f;
}

double pop()
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0;
    }
}

double getop(char s[])
{
    int i, c, d; 
    while ((s[0] = c = getch()) == ' ' || c == '\t'); 
    s[1] = '\0'; 
    if (!isdigit(c) && c != '.' && c != '-') 
        return c;
    
    i = 0; 
    if (isdigit(c))    
        while (isdigit(s[++i] = c = getch()));

     if (c == '-')
        if (isdigit(c=getch()) || c == '.') {
            s[i++] = '-';
            s[i++] = c;
            while (isdigit(s[i++] = c = getch()));
        }
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    s[i] = '\0';

    if (c == '.')      
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';

     
    if (c != EOF) 
        ungetch(c);

    return NUMBER; 
}
        
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