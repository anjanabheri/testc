
#include "include.h"

int main()
{

    string num = "1F";
    char *end;
    int j = strtol(num.c_str(), 0, 16);
    cout << "j: " << j << endl;

    return 0;
}
