
#include "include.h"

int add(int a, int b)
{
    cout << "add: " << (a + b) << endl;
}

int mul(int a, int b)
{
    cout << "mul: " << (a * b) << endl;
}

int op(int(*fp)(int, int), int c, int d)
{
    return fp(c, d);
}

int main()
{
    int (*fptr)(int, int);
    fptr = add;
    //fptr = &add;
    fptr(4, 5);
    op(add, 5, 6);
    op(mul, 5, 6);
    return 0;
}



