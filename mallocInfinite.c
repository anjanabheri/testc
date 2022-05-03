
#include "include.h"

int main()
{
    int count = 0;

while (1) {}

    while(1)
    {
        int size = 1024 * 1024 * 1024;
        void * ptr = malloc(size);
        if (ptr == NULL)
            break;
        memset(ptr, 0xAB, size);
        count ++;
        if ((count % 1024) == 0)
        printf("ptr (%d): %x\n", count, ptr);
    }

    while(1)
    {
    }

    return 0;
}
