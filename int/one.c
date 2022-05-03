
#include "../include.h"
#include "assert.h"

void main()
{
    char *p = NULL;
    p = malloc(10);
    p ++;
    free (p);
}
