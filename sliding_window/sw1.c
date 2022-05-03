
#include "../include.h"
#include "assert.h"
#include "limits.h"

int window = 2;

int main()
{
    int a[] = {-1, 2, -4, -3, 1, 2, -3, 2};
    int sum = 0;
    int position = 0;
    int max = INT_MIN;
    int i = 0;

    int elements = sizeof(a) / sizeof(a[0]);

    printf("num elements: %d\n", elements);

    if (elements < window)
    {
        printf("Elements are less than window size");
        return;
    }

    for (i = 0; i < (elements - window); i ++)
    {
        sum = a[i] + a[i+1];
        if (max < sum)
        {
            max = sum;
            position = i;
        }
    }

    printf("sum: %d, elements position: %d & %d\n", max, position, position + 1);
}

