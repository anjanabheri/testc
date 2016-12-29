
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

float find_median(int* a, int total);
int sort_insert(int* a, int new, int index);

void print_array(int *a, int index)
{
    int i = 0;
    printf("array: ");
    for (i = 0; i <= index; i ++)
        printf("[%d]%d ", i, a[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    int new = 0;
    int a_i = 0;

    int *a = malloc(sizeof(int) * n);

    for(a_i = 0; a_i < n; a_i++)
    {
        scanf("%d", &new);
        sort_insert(a, new, a_i);
        //print_array(a, a_i);
        printf("%.1f\n", find_median(a, a_i + 1));
    }
    return 0;
}

int sort_insert(int* a, int new, int index)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < index; i ++ )
    {
        if (a[i] > new)
        {
            for (j = index; j > i; j --)
                a[j] = a[j-1];

            a[i] = new;
            break;
        }
    }
    if (i == index)
        a[index] = new;

    return 0;
}

float find_median(int* a, int total)
{
    float median = 0;

    if (total%2 == 0)
        median = ((float)(a[total/2] + a[(total/2)-1])/2);
    else
        median = a[total/2];

    return median;
}

