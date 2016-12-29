
#include "include.h"
#include <unistd.h>


int main()
{
    execve("env.exe", 0, 0);
    return 0;
}
