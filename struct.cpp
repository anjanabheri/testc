
#include "include.h"

typedef struct 
{
    char c;
    char j;
    int p;
} test;

int main()
{
    test *one;
    one = (test*)malloc(2*sizeof(test));

    printf("one: %p \n", one);

    one ++;
    printf("one: %p \n", one);

    //one = (test*)((char*)one) + 1;
    one = (test*)((char*)one) + 1;
    printf("typecasted one: %p \n", one);

    return 0;
}
