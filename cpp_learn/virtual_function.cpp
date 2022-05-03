
#include <iostream>
using namespace std;
 
class A {
    public:
        virtual void foo()
        {
            cout << "A foo called" << endl;
        }
        A()
        {
            cout << "A constructor called" << endl;
        }
        virtual ~A()
        {
            cout << "A destructor called" << endl;
        }
};

class B: public A {
    public:
        void foo()
        {
            cout << "B foo called" << endl;
        }
        B()
        {
            cout << "B constructor called" << endl;
        }
        ~B()
        {
            cout << "B destructor called" << endl;
        }
};


int main()
{
    A *ptr;
    B *test1;

    test1 = new B();
    ptr = test1;

    ptr->foo();

    delete ptr;

    return 0;
}
