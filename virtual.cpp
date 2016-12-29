
#include "include.h"


class base
{
   public:
   virtual void fun2();
};

class other
{
    private:
        base* basep;

    public:
        void registerUp() {basep->fun2();};
};

int main()
{
    other one;
    one.registerUp();
    return 0;
}
