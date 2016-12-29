
#include "include.h"

main()
{
    char* ptr = "something";
    char ptr2[] = "something";

    ptr = "new value";
    //*ptr2 = "new value";

    cout << "ptr: " << *ptr << endl;
}
