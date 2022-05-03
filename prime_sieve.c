
#include "include.h"
#include "assert.h"
#include "stdbool.h"

int main(int argc, char* argv[])
{

    if (argc < 2)
    {
        printf("\npass the number to test\n");
        return 0;
    }

    int number = atoi(argv[1]);

    int a[number + 1];
    //memset(a, 0, number*sizeof(int));

    int i = 0;

    for (i = 1; i <= number; i ++)
        a[i] = i;

    int m = 0;
    int j = 0;

    for (j = 2; j <= number; j ++)
    {
        //printf("j: %d\n", j);

        for (m = j*j; m <= number; m = m + j)
        {
            //printf("m: %d\n", m);
            a[m] = 0;
        }
    }

    printf("\nprimes less than number: %d are: \n", number);
    for (i = 1; i <= number; i ++)
    {
        if (a[i] != 0)
            printf("%d ", a[i]);
    }
    return 0;
}

