
#include "../include.h"

class test 
{
    private:
        int data;

    public:
        void setData(int input) {data = input;};
        int getData() {return data;};

    friend void super(test&);
};

void super(test& obj)
{
    cout << "super(): data: " << obj.data << endl;
}

int main()
{
    test obj1;
    obj1.setData(59);

    cout << "data: " << obj1.getData() << endl;
    super(obj1);
    

    return 0;
}
