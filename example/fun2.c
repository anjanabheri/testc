#include "fun2.h"
#include "malloc.h"

int fun2(void) {
    int *ptr1 = malloc(20);
    printf("FUN2: malloced: 0x%x\n", ptr1);
    return 1;
}
~   
