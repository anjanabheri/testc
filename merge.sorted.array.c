
#include "include.h"
#include "assert.h"

//int a1[5] = {4, 8, 9, 15, 16};
//int a2[4] = {2, 5, 10, 12};
int a2[4] = {1,1,1,1};
int a1[5] = {1, 2, 5, 10, 12};

main()
{
    print();

    //approach_1();
    approach_2();

}

int approach_1()
{
    int i1 = 0;
    int i2 = 0;

    for (i1 = 0; i1 < 4 ; i1 ++)
    {
        {
            adjust(i1);
        }
    }
}

int approach_2()
{
    int i1 = 0;
    int i2 = 0;
    int temp = 0;

    for (i1 = 0; i1 < 5; i1 ++)
    {
        if (a1[i1] > a2[0])
        {
            temp = a1[i1];
            a1[i1] = a2[0];
            a2[0] = temp;

            for (i2 = 0; i2 < (4-1); i2 ++)
            {
                if (a2[i2] > a2[i2+1])
                {
                    temp = a2[i2];
                    a2[i2] = a2[i2+1];
                    a2[i2+1] = temp;
                }
            }
            print();
        }
    }
}

int sae(int index)
{
    if (index < 5)
        return a1[index];
    else
        return a2[index-5];
}

int set_sae(int index, int data)
{
    if (index < 5)
        return a1[index] = data;
    else
        return a2[index-5] = data;
}

print()
{
    int i1 = 0;
    int i2 = 0;
    printf("arr1: ");
    for (i1 = 0; i1 < 5; i1 ++)
    {
        printf("%d ", a1[i1]);
    }
    printf("\narr2: ");
    for (i1 = 0; i1 < 4; i1 ++)
    {
        printf("%d ", a2[i1]);
    }
    printf("\n");
}

adjust(int index)
{
    int i = 0;
    int temp = 0;
    
    for (i = 0; i < 5+4; i ++)
    {
        if (a2[index] < sae(i))
        {
            temp = a2[index];
            a2[index] = sae(i);
            set_sae(i, temp);
        }
    }

    printf("index: %d\n", index);
    print();
}
