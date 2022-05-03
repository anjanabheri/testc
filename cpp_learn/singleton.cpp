
#include <iostream>
using namespace std;
 
//making some singleton class - only one object can be created
class some
{
    public:
        static some *instance;
        int one;
        int foo() {
            cout << "foo called" << endl;
            one ++;
            return 0;
        }
        static some* get_some()
        {
            if(!instance)
                instance = new some(20);
            return instance;
        }
    private:
        //1. make constructor private, so that no instance can be created
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

some* some::instance = 0;

int main()
{
    some* s = s->get_some();
    return 0;
}
