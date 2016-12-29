
#include "include.h"

namespace ONE
{
    class some
    {
        public:
        int i;
    };
};

namespace TWO
{
    class some : public ONE::some
    {
        public:
        int j;
    };
};

int main()
{
    ONE::some test;
    test.i = 5;

    TWO::some test2;
    test2.i = 6;
    test2.j = 7;

    printf("test i: %d\n", test.i);
    printf("test 2 i: %d\n", test2.i);
    printf("test 2 j: %d\n", test2.j);

    return 0;
}
