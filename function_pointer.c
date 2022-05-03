
#include "include.h"
#include "assert.h"

int add(int a, int b)
{
    return (a + b);
}

int difference(int a, int b)
{
    return (a - b);
}

typedef int (*fptr)(int a, int b);
fptr f1;

int main()
{
#if 1
    f1 = add;
    printf("add: %x, difference: %x, fptr: %x\n", add, difference, f1); 
    printf("1st call: %d\n", f1(5,6));
    f1 = difference;
    printf("2nd call: %d\n", f1(5,6));
#endif

    return 0;
}

