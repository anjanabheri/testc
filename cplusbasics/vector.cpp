
#include "../include.h"

vector<string> vectStr;

class SOME
{
    public:
    std::string str1;
};

void fun(SOME* some)
{
    vectStr.push_back(some->str1); 
}

int main()
{
    SOME one;
    one.str1 = "";
    fun(&one);

    return 0;
}
