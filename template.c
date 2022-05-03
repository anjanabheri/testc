
#include "include.h"
#include "assert.h"

struct test
{
    int one:1;
    int two:1;
};

int main()
{


    int n = 1;
    int x = n << 39;

    printf("x: %d\n", x);



    return 0;
}
/*
0xB01: "1"

0xAB01: 04
             
    04: 01
01
*/
