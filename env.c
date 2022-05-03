
#include "include.h"
#include "assert.h"

int main()
{
#ifdef CLEARCASE_ROOT
    printf("CLEARCASE ROOT DEFINE");
#else
    printf("NOT A CLEARCASE REPO");
#endif
    return 0;
}
