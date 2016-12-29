
#include "../include.h"

template <class T>
void hello(T var)
{
    T var2;
    var2 = var;

    cout << "var2: " << var2 << endl;

    return;
}

template <class T>
class ONE
{
    T some;
};

int main()
{
    int i = 3;
    long j = 33;

    ONE<string> one;

    hello(i);
    hello(j);

    return 0;
}
