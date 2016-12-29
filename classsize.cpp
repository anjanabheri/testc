
#include "include.h"

class something
{
    int one;
};

class derived : public something
{
    int two;
};

int main()
{
    printf("size: something: %d, derived: %d \n", sizeof(something), sizeof(derived));
    return 0;
}
