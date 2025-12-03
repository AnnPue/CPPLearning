#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main()
{   
    char *r = fgets(r, 100, stdin);
    size_t n = strlen(r);
    char *t = (char*)malloc(n * sizeof(char) + 1);
    strcpy(t, r);

    printf("r: %s\n", r);
    printf("t: %s\n", t);
    free(t);
    return 0;
}
