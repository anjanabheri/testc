
#include "include.h"

int main()
{
    string str = "hello";

    string str2;
    str2.assign("");

    str2 = "rooooommm";

    if (str != "")
        str2 += str;

    cout << "str2: " << str2 << endl;
    
    return 0;
}
