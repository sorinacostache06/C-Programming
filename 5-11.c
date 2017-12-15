#include <stdio.h>
#include <stdlib.h>

#define STOPTAB 4  

int space(int pos, int stoptab)
{
    return pos % stoptab;
}

int detab(int stoptab)
{
    char c;
    int spaces;
    int pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            spaces = space(pos, stoptab);
            while (spaces--) {
                putchar('-');
                pos++;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 0;
        }
        else {
            putchar(c);
            pos++;
        }      
    }
}

int main(int argc, char *argv[])
{
    char c;
    int spaces, stoptab;
    int i = 1;
    printf("Enter text:\n");

    if (argc == 1)
        detab(STOPTAB);
    else {
        while (--argc) {
            printf("%d\n", atoi(argv[i]));
            stoptab = atoi(argv[i++]);
            detab(stoptab);
        }
    }
    return 0;
}
