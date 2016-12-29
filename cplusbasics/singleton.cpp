
#include "../include.h"

class singleton
{
    private:
        static singleton* instance;
        singleton() {}

    public:
        static singleton* getInstance()
        {
            if (instance == NULL)
            {
                instance = new singleton();
            }

            return instance;
        }
};

singleton* singleton::instance = NULL;

int main()
{

    singleton *obj1, *obj2;
    obj1 = singleton::getInstance();
    obj2 = singleton::getInstance();

    cout << "obj1: " << obj1 << ", obj2: " << obj2 << endl;

    return 0;
}
