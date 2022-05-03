
#include <iostream>
using namespace std;
 
class A {
    public:
        virtual void foo() = 0;
};

class B: public A {
    public:
#if 1
        void foo()
        {
            cout << "B foo called" << endl;
        }
#endif
};


int main()
{
    A *test1;
    test1 = new B;

    return 0;
}
