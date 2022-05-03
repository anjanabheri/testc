
#include "include.h"
#include "assert.h"


int print(int n, int j)
{
    int k = n;
    if (n < -j)
        return;
    printf("%d ", n);
    print(n-j, j);
    if (k > -j)
        printf("%d ", k);
}

int main()
{
    int n = 5;
    int j = 5;

    print(n, j);
    

    return 0;
}

