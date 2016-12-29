
#include "include.h"

class ONE
{
    public:
        int j;
        ONE(int k){j = k;};
        void hi() {cout << "ONE hi: " << j << endl;};
        int* hello;
};

class TWO: public ONE
{
    public:
        TWO(int k):ONE(k){};
        void hi() {cout << "TWO hi: " << j << endl;};
        char* hello;
};

template <class T>
class NEW
{
    public:
        T* p;
};

int main()
{
    NEW<TWO> brave;
    brave.p = new TWO(3);
    brave.p->hi();

    TWO *test;
    test = new TWO(2);
    test->hi();

    return 0;
}
