
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

    int i = 0;
    int j = 0;
    int position = 0;
    bool is_prime = false;
    printf("to find the prime number in poistion of: %d\n", number);

    for (i = 1;; i ++)
    {
        is_prime = true;
        for (j = 2; j <= (i/2); j ++)
        {
            if ((i % j) == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime == true)
        {
            position ++;
            if (position == number)
            {
                printf("prime number at position %d is: %d\n", number, i);
                break;
            }
        }
    }

    return 0;
}

