#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>
#define ADLEN (sizeof(struct sockaddr))
#define PORT 6801
#define CLIENT_PORT 7001
extern int errno;

main()
{
    int fdc, chk;
    struct sockaddr_in saddr;
    struct sockaddr_in caddr;

    fdc = socket(PF_INET, SOCK_STREAM, 0);
    if (fdc < 0)
    {
        printf("Socket error : %d\n", errno);
        exit(1);
    }

    /* Client bind */

    caddr.sin_family = AF_INET;
    caddr.sin_port = htons(CLIENT_PORT);
    //caddr.sin_addr.s_addr = htonl(0x7f000001);
    caddr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(caddr.sin_zero, 0, sizeof(caddr.sin_zero));

    int flags = 1;
    if (setsockopt(fdc, SOL_SOCKET, SO_REUSEADDR, &flags, sizeof(flags)) < 0)
    {
        printf("setsockopt Error : %d\n", errno);
        exit(1);
    }

    if ((chk = bind(fdc, (struct sockaddr*)&caddr, sizeof(struct sockaddr_in))) < 0)
    {
        printf("bind Error : %d\n", errno);
        exit(1);
    }

    /* Server socket */
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(PORT);
    saddr.sin_addr.s_addr = 0;
    memset(saddr.sin_zero, 0, sizeof(saddr.sin_zero));

    chk = connect(fdc, (struct sockaddr*)&saddr, sizeof(saddr));

    if (chk < 0)
    {
        printf("Connect error : %d\n", errno);
        exit(1);
    }

    printf("\nSending some message\n");

    char buf[] = "<<<<< This is message from client >>>>>";
    chk = send(fdc, buf, sizeof(buf), 0);

    sleep(200);

}
