
#include "include.h"
#include "assert.h"

//#pragma pack(1)
typedef struct
{
    int i;
    int j;
    char a;
    int b;
} some;


int main()
{
    //printf(" offset of b: %u\n", (unsigned int)((char *)(&((some*)0)->b)));
    printf(" offset of b: %u\n",  &((some*)0)->b    );
    return 0;
}

