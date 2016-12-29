
#include <stdio.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
    struct rlimit       rl;
    int                 resource = RLIMIT_NOFILE;

    rl.rlim_cur = 2500;
    rl.rlim_max = 2500;

    if (setrlimit(resource, &rl) == 0) {
        printf("Increasing File Descriptors to %d \n", (int)rl.rlim_cur);
    } else {
        printf("setrlimit error. Cannot increase file descriptors \n");
    }


    if (getrlimit(resource, &rl) != 0) {
        printf("getrlimit error\n");
    }
    printf("Current File Descriptors size: cur:%d/max:%d \n", (int)rl.rlim_cur, (int)rl.rlim_max);


    return 0;

}

