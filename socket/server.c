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

extern int errno;

main()
{
    int chk, fdc, fds, inlen = 0;
    struct sockaddr_in saddr, daddr;

    fds = socket(PF_INET, SOCK_STREAM, 0);
    if (fds < 0)
    {
        printf("error : %d\n", errno);
        exit(1);
    }

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(PORT);
    saddr.sin_addr.s_addr = htonl(0x7f000001);
    memset(saddr.sin_zero, 0, sizeof(saddr.sin_zero));

    int flags = 1;
    if (setsockopt(fds, SOL_SOCKET, SO_REUSEADDR, &flags, sizeof(flags)) < 0)
    {
        printf("setsockopt Error : %d\n", errno);
        exit(1);
    }

    if ((chk = bind(fds, (struct sockaddr*)&saddr, sizeof(struct sockaddr_in))) < 0)
    {
        printf("bind Error : %d\n", errno);
        exit(1);
    }


    if ((chk = listen(fds, 5)) < 0)
    {
        printf("listen error : %d\n", errno);
        exit(1);
    }
    memset(&daddr, 0, sizeof(daddr));

    if ((fdc = accept(fds, (struct sockaddr*) &daddr, (socklen_t*)&inlen)) < 0)
    {
        printf("accept error : %d\n", errno);
        exit(1);
    }

    printf("New client connection arrived, client socket: %d, Port: %d, Address: 0x%x, inlen: %d \n",
           fdc, daddr.sin_port, daddr.sin_addr.s_addr, inlen);
    fflush(stdout);

    char buf[300];
    memset(buf, 0, sizeof(buf));

    while (1)
    {
        chk = recv(fdc, buf, sizeof(buf), 0);
        if (chk > 0)
        {
            printf("Server: %s\n", buf);
            fflush(stdout);
        }
        fflush(stdout);
    }
}
