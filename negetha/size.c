
#include "include.h"
#include "assert.h"

struct s
{
    int i;
    char c;
    long d;
    void *p;
    char e;
    int a[];
};

int main()
{
    struct s test;
    printf("size: %d \n", sizeof(struct s));
    printf("sizeof int: %d\n", sizeof(test.i));
    printf("sizeof char: %d\n", sizeof(test.c));
    printf("sizeof long: %d\n", sizeof(test.d));
    printf("sizeof pointer: %d\n", sizeof(test.p));
    printf("sizeof PAGE: %d\n", getpagesize());
    printf("\ndata address: %p %p %p %p %p %p\n", &test.i, &test.c, &test.d, &test.p, &test.a, &test.e);
    //printf("data address: %d %d %d %d %d %d\n", &test.i, &test.c, &test.d, &test.p, &test.a, &test.e);
    return 0;
}
