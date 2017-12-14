#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f, *g;
    if (argc == 3) {
        f = fopen(argv[1], "r");
        g = fopen(argv[2], "r");
    } else {
        printf("error: wrong number of args");
        return -1;
    }

    if (f == NULL) {
        printf("error: can't open %s\n", argv[1]);
        return -1;
    }

    if (g == NULL) {
        printf("error: can't open %s\n", argv[2]);
        return -1;
    }

    size_t buffer_size = 100;
    char *buffer_f = malloc(buffer_size * sizeof(char));
    char *buffer_g = malloc(buffer_size * sizeof(char));
    

    while ((getline(&buffer_f, &buffer_size, f) != -1) && (getline(&buffer_g, &buffer_size, g)) != -1) {
        if (strcmp(buffer_f, buffer_g) != 0) {
            printf("First diff line in %s: %s\n", argv[1], buffer_f);
            printf("First diff line in %s: %s\n", argv[2], buffer_g);
            return 0;
        }
    }

    if ((getline(&buffer_f, &buffer_size, f) != -1) && (getline(&buffer_g, &buffer_size, g)) == -1)
        printf("First diff line in %s: %s\n", argv[1], buffer_f);

    if ((getline(&buffer_f, &buffer_size, f) == -1) && (getline(&buffer_g, &buffer_size, g)) != -1)
        printf("First diff line in %s: %s\n", argv[2], buffer_g);

    fclose(f);
    fclose(g);

    return 0;
}
