
#include "include.h"
#include "assert.h"

int main()
{
    int array[] = {1, 4, -5, 7, 10};
    int sum = 2;
    int hash[1] = {0};

    hash[10] = 1;

    printf("hash: %x, +1: %x, -1: %x", hash, hash+1, hash-1);

    return;

    int i = 0;
    int len = 0;
    len = sizeof(array) / sizeof(array[0]);
    int addend = 0;

    for (i = 0; i < len; i ++)
    {
        addend = sum - array[i];
        if (hash[addend] == 1)
        {
            printf("pairs found\n");
            break;
        }
        hash[array[i]] = 1;
    }

    return 0;
}

int sum()
{
    int array[] = {1, 4, -5, 7, 10};
    int sum = 20;

    int len = 0;
    int i = 0;
    int j = 0;
    int pair_exists = 0;
    int num_iter = 0;

    len = sizeof(array) / sizeof(array[0]);

    for (i = 0; i < len - 1; i ++)
    {
        for (j = i+1; j < len; j ++ )
        {
            num_iter ++;

            if (sum == (array[i] + array[j]))
            {
                printf("pair exists\n");
                pair_exists = 1;
                break;
            }
        }

        if (pair_exists)
            break;
    }

    if (!pair_exists)
        printf("pair does not exist\n");

    printf("number of iterations: %d\n", num_iter);
    return 0;
}

