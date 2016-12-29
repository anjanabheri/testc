
#include "include.h"
#include "assert.h"

int main(int argc, char* argv[])
{
    char *c = 0;
    int i = atoi(argv[1]);
    int s = atoi(argv[2]);

    printf("size: %d M, sleep: %d\n", i, s);

    c = malloc(i*1024*1024);
    memset(c, 4, i*1024*1024);

    int m = i;
    int inc = 100;

    while(1)
    {
        m += inc;
        c = malloc(inc*1024*1024);
        memset(c, 4, inc*1024*1024);
        printf("Allocated memory: %d M\n", m);
        sleep(1);
    }

    sleep(s);
    return 0;
}
