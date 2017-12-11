#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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
    int i, c;
    static char buf[MAXSTRING]; 

    while ((s[0] = c = getch()) == ' ' || c == '\t'); 
    s[1] = '\0'; 
    if (!isdigit(c) && c != '.' && c != '-') 
        return c;
    
    i = 0; 
    if (isdigit(c))    
        while (isdigit(s[++i] = c = getch()));

     if (c == '-')
        if (isdigit(c = getch())) {
            s[i++] = '-';
            s[i++] = c;
           while (isdigit(c = getch()) || c == '.')
                s[i++] = c;
        }
        else {
            if (c != EOF)
                strncat(buf, &c, 1);
            return '-';
        }

    if (c == '.')      
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';

     
    if (c != EOF) 
        strncat(buf, &c, 1);

    return NUMBER; 
}
        
int getch(void)  
{ 
    char c;
    if (strlen(buf) > 0) {
        c = buf[0];
        memmove(buf, buf+1, strlen(buf));
        return c;
    } 
    return getchar();
} 
