
#include "include.h"

int main()
{
    char *ptr = NULL;
    int i = 1;

    do
    {
        if (ptr)
            free(ptr);
        ptr = malloc (1024 * 1024 * i);
        if (ptr != NULL)
            printf("memory allocated: %d MB \n", i);
        i ++;
    } while (ptr != NULL);

    return 0;
}
