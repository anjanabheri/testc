#include <stdio.h>
#include <stdlib.h>

struct hello
{
    int i;
    char c;
    int j;
    int *b[0];
};

void main()
{
    printf("size: %d\n", sizeof(struct hello));
    struct hello h[2];
    printf("my size: %d\n", (char*)&h[1] - (char*)&h[0]);
}
