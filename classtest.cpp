
#include "include.h"

class ONE
{
    public:
    virtual void fun() = 0;
};
void ONE::fun()
{
    printf("Hi I am ONE \n");
}

class TWO : public ONE
{
};

void ONE::TWO::fun()
{
        printf("Hi I am TWO \n");
}

int main()
{
    TWO test;
    test.fun();
    return 0;
}
