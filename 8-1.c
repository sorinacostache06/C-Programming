#include <stdio.h> 
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{ 
    int fp; 
    char *prog = argv[0];  
    char buf[BUFSIZ]; 
    int n; 

    if (argc == 1 ) 
        printf("error: no args\n");
    else 
        while (--argc > 0) 
            if ((fp = open(*++argv, O_RDONLY, 0)) == -1) { 
                fprintf(stderr, "%s: can't open %s\n", prog, *argv); 
                exit(1); 
            } else { 
                while ((n = read(fp, buf, BUFSIZ)) > 0) {
                     if (write(1, buf, n) != n) 
                        error("cp: write error on file %s", argv[2]); 
                }
            }
    return 0;
} 