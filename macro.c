
#include "include.h"
#include "assert.h"

#define SOME()  \#if 0
#define SOME_END()  \#endif

int main()
{
SOME()
    sss ssss;
SOME_END()
    return 0;
}
