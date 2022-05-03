#include "fun1.h"
#include "malloc.h"

int fun1(void) {
    int *ptr1 = malloc(10);
    printf("FUN1: malloced: 0x%x\n", ptr1);
    return 1;
}
