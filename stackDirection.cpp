
#include "include.h"

long fun1ptr;
long fun2ptr;


void fun2(int passed)
{
    int local;
    void *funHeap = malloc(4);
    cout << "fun2: passed: " << &passed << ", local: " << &local << ", heap: " << funHeap << endl;
    fun2ptr = (long int)&local;
}

void fun(int passed)
{
    int local;
    void *funHeap = malloc(4);
    cout << "fun1: passed: " << &passed << ", local: " << &local << ", heap: " << funHeap << endl;
    fun1ptr = (long int)&local;
    fun2(local);
}

int main()
{
    int a[2];
    int i;

    cout << "main: a[0]: " << &a[0] << ", a[1]: " << &a[1] << endl;

    fun(i);

    if (fun1ptr > fun2ptr)
        cout << "stack is growing Downwards" << endl;
    else
        cout << "stack is growing Upwards" << endl;

    return 0;
}
