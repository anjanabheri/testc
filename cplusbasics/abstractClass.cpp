
#include "../include.h"

class exam;

class test 
{
    private:
        int data;

    public:
        void setData(int input) {data = input;};
        void setExamData(exam moreData);
        int getData() {return data;};
};

class exam
{
    private:
        int finalData;

    public:
        void setFinalData(int input) {finalData = input;};
        int getFinalData() {return finalData;};

        friend class test;
};

void test::setExamData(exam moreData) 
{
    moreData.finalData = 55;
}

int main()
{
    test obj1;
    exam obj2;
    obj1.setExamData(obj2);
    

    return 0;
}
