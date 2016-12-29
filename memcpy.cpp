
#include "include.h"

char source[] = "This is a testing string";
char dest1[100];
char dest2[100];

void myCopy(void* dst, void* src, int count)
{
    char* cdst = (char*)dst;
    char* csrc = (char*)src;

    while (count --)
    {
        *cdst ++ = *csrc ++;
    }

    return;
}

int main()
{
    myCopy(dest1, source, 10);
    printf("dest: %s \n", dest1);
    return 0;
}
