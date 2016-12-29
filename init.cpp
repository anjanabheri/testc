
#include "include.h"


int main()
{
    char* str1 = "testing";
    char* str2;
    char str3a[] = "testing";
    char str4a[];

    str2 = "Testing 1";
    str2 = "Testing 2";

    str1 = "Testing 2";
    //This doesn't work
    //str3a = "Testing";
 
    //This doesn't work
    //str4a[] = "Testing";

    strcpy(str3a, "Testing");

    cout << "str1: " << str1 << std::endl;
    cout << "str2: " << str2 << std::endl;
    cout << "str3a: " << str3a << std::endl;

    return 0;
}
