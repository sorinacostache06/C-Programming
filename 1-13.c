#include <stdio.h>

int frequency[100];

struct Freq{
    int len;
    int frequency;
};

struct Freq v[100];

int main()
{
    char c;
    int len, count = 0, flag = 0;
    printf("Enter text: ");
    while ((c = getchar()) != '0') {
        if (c == '\n' || c == '\t' || c == ' ') {
            flag = 0;
            for(int i = 0; i < count && flag == 0; i++) 
                if (v[i].len == len) {
                    v[i].frequency++;
                    flag = 1;
                }
            if (flag == 0) {
                v[count].frequency = 1;
                v[count].len = len;
                count++;
            }
            len = 0;
            putchar('\n');
        }
        else {
            len++;
        }
    }

    struct Freq aux;
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if(v[i].frequency < v[j].frequency) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < v[i].len; j++)
            printf("-");
    printf("\n");
    }
        
    return 0;
}
