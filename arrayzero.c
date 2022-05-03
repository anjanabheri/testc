
#include "include.h"
#include "assert.h"


typedef struct {
    int type;
    unsigned char data[];
} test;


main()
{

    const char* s = getenv("USER");

    printf("user: %s, %s\n", s, getenv("USER"));

    test *one;
    one = malloc(sizeof(test))+4;
    int some = 55;
    memcpy(one->data, &some, 4);

    test *two;
    two = malloc(sizeof(test))+4;
    memcpy(two, one, sizeof(test)+4);
    printf("two size: %u, data: %u\n", sizeof(two), two->data[0]);
}

