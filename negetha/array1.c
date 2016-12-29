
#include "../include.h"
#include "assert.h"

// Given an unsorted array, find all possible pairs which sum to
// a given number with log(n) complexity

int a[] = {1, 4, 5, 7, 3, 0, 2};

int main()
{
    int i = 0;
    int j = 0;
    int number = 19;
    int array_len = sizeof(a) / sizeof(a[0]);

    //printf ("Enter the number:");
    //scanf("%d", &number);

    printf("array len: %d\n", array_len);

    for (i = 0; i < array_len; i ++)
        for (j = i + 1; j < array_len; j ++)
        {
            //printf("checking for: %d, %d\n", a[i], a[j]);
            usleep(100000);
            if ((a[i] + a [j]) == number)
                printf("pair: %d, %d\n", a[i], a[j]);
        }

    return 0;
}
