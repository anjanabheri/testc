#include <assert.h>
#include <stdlib.h>

int fun1(void);
int fun2(void);

int main(void) {
    fun1();
    fun2();
    return EXIT_SUCCESS;
}
void *__wrap_malloc(long size)
{
    void *ptr = malloc(size);
    printf("Memory: size: %u, ptr: 0x%x\n", size, ptr);
    return ptr;
}
