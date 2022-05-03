
#include <iostream>
using namespace std;
 
class A {
    public:
        void foo() {
            cout << "A foo called" << endl;
    }
};

//In this case without virtual, code won't even compile
//There will be ambiguity
class B: public virtual A {
};

class C: public virtual A {
};

class D: public B, public C {
};

int main()
{
    D test;
    test.foo();
    return 0;
}
