
#include "include.h"
#include "assert.h"

struct gl
{
    int a;
};

struct gl* pn1;
#define n1 (*pn1)

int main()
{
    pn1 = malloc(sizeof(struct gl));
    n1.a = 2;
    printf("%d\n", n1.a);
    return 0;
}
