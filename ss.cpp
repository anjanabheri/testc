
#include "include.h"

stringstream ss;

int main()
{
    ss << "First ";
    ss << " Second";

    cout << "ss: " << ss.str();

    return 0;
}
