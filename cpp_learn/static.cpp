
#include <iostream>
using namespace std;
 
class some
{
    public:
        static int foo() {
            std::cout << "foo called" << std::endl;
            one ++;
            return 0;
        }
    private:
        static int one;
};

//without this, we will get undefined reference
int some::one;


int main()
{
    //if static, it can be called without class object
    some::foo();
    return 0;
}
