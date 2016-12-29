
#include "../include.h"

template <class T>
T print(T i)
{
    T j;
    j = i;
    cout << "input: " << hex << j << endl;
}

template <class T>
class TEST
{
    public:
    T i;
    void print();
};

template <class T>
void TEST<T>::print()
{
    cout << "CLASS input: " << hex << i << endl;
}

int main()
{
    int p = 0x01020304;
    long r = 0x0506070804030202;
    print(p);
    print(r);

    TEST<int> x;
    x.i = 0xAABBCCDD;
    x.print();
    TEST<long> y;
    y.i = 0xAABBCCDDAABBCCDD;
    y.print();

    return 0;
}
