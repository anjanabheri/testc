
#include "include.h"
#include "assert.h"


void fun()
{
    fork();
    int a = 0;
    int *b;
    b = malloc(sizeof(int));

    printf("address of a (stack): 0x%x\n", &a);
    printf("address of b (heap) : 0x%x\n", b);
}

int main()
{
    fun();
    return 0;
}

