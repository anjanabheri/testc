
#include "include.h"
#include "assert.h"

typedef struct test
{
    int a;
    char b;
    int c:1;
    int d:2;
}test;

void fun1()
{
    test one;
    one.a = 0xAABBCCDD;
    one.b = 0xEE;
    one.c = 1;
    one.d = 3;
    printf("%d\n", sizeof(one)); 
    printf("a: 0x%x, b: 0x%x, c: 0x%x\n", one.a, one.b, one.c); 
}


#if 0
struct test1 { 
    unsigned int x; 
    unsigned int y : 33; 
    unsigned int z; 
}; 
int fun2() 
{ 
    printf("%lu", sizeof(struct test1)); 
    return 0; 
}
#endif

struct test3 { 
    unsigned int x; 
    long int y : 33; 
    unsigned int z; 
}; 
int fun3() 
{ 
    struct test3 t; 
    unsigned int* ptr1 = &t.x; 
    unsigned int* ptr2 = &t.z; 
    printf("diff: %u, p2: 0x%x, p1: 0x%x\n", ptr2 - ptr1, ptr2, ptr1); 
    return 0; 
} 

union test4 { 
    unsigned int x : 3; 
    unsigned int y : 3; 
    int z; 
}; 
  
int fun4() 
{ 
    union test4 t; 
    t.x = 5; 
    t.y = 4; 
    t.z = 1; 
    printf("t.x = %d, t.y = %d, t.z = %d", 
           t.x, t.y, t.z); 
    return 0; 
} 

//TODO: Check endian type of the system using bit field
struct test5 {
    int a:1;
};

void main()
{
    struct test5 t;
    t.a = 1;
    fun4();
}
