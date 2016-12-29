
#include "include.h"

    template<typename Key, typename Value> class ContextTable
    {
        public:
            int getSizeOf() {return sizeof(Value);};
    };

template<typename T> class Global
{
    public:
   //typedef map <int, T> myMap; 
    typedef ContextTable<uint32_t, T> Table;
    Table t;
};

template<typename 0> class Global
{
    public:
   //typedef map <int, T> myMap;
};


class ONE
{
    int a;
};

class ONEd : public ONE 
{
    int b;
};

class MyGlobal : public Global<ONEd>
{
    public:
    int something;
};

int main()
{
    MyGlobal test;
    test.something = 1;
    printf("sizeof MyGlobal object: %d, CT: %d\n", sizeof(test), test.t.getSizeOf());
    return 0;
}
