
#include "../include.h"
#include "assert.h"

#define MB (1024*1024)

int main(int argc, char* argv[])
{
    char *c = 0;
    int i = 0;
    while(1)
    {
        i ++;
        c = malloc(MB);
        if (c == NULL)
            break;
        printf("Allocated memory: %d M\n", i);
    }

    return 0;
}
