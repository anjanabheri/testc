
#include <iostream>
using namespace std;
 
class some
{
    public:
        int one;
        int foo() {
            cout << "foo called" << endl;
            one ++;
            return 0;
        }
        some(int one)
        {
            this->one = 20;
            this->one += one;
            cout << "some class, constructor called, one: " << this->one << endl;
        }
        ~some()
        {
            cout << "some class, destructor called" << endl;
        }
};

int main()
{
    some test(10);
    test.foo();
    return 0;
}
