
#include "include.h"
#include "assert.h"


main()
{

    char string[] = "Thisss is in example;";
    char *cmd[10];
    char *p = NULL;
    int i = 0;

    printf("address of string: 0x%x\n", string);
    p = strtok(string, " ");
    printf("string: %s\n", string);
    printf("address of string: 0x%x, p: 0x%x\n", string, p);
    while (p != NULL)
    {
        cmd[i ++] = p;
        p = strtok(NULL, " ");
        printf("i: %d, p: 0x%x, string: %s\n", i, string, string);
    }
    printf("cmd :%s, %s, %s, %s\n", cmd[0], cmd[1], cmd[2], cmd[3]);

    printf("cmd[0]: 0x%x\n", cmd[0]);
    printf("cmd[1]: 0x%x\n", cmd[1]);
}
