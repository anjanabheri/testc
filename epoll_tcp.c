#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
#include <assert.h>

pthread_t s_thread;
pthread_t c_thread;
pthread_t c_thread2;
int   g_test_server_socket             = -1;
int   g_test_accept_socket_array[2]    = {0};
int   g_test_accept_socket_array_index = 0;
void* end_trigger_h            = NULL;
int   epfd    = -1;

void* ipv4_tcp_server()
{
    struct sockaddr_in  sad;
    int                 n       = 0;
    int                 optval  = 1;
    int                 ret     = 0;
    struct epoll_event  ev      = {0};

    epfd = epoll_create(10);

    printf("%s(): epfd: %d created\n", __FUNCTION__, epfd);

    memset(&sad, 0, sizeof(sad));

    sad.sin_family = AF_INET; 
    sad.sin_port = 6767;
    sad.sin_addr.s_addr = INADDR_ANY;

    g_test_server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    assert(g_test_server_socket > 0);

    printf( "%s(): Socket %d created\n", __FUNCTION__, g_test_server_socket);

    ev.events = EPOLLIN;
    ev.data.fd = g_test_server_socket;
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, g_test_server_socket, &ev);
    assert(ret != -1);

    ret = bind(g_test_server_socket, (struct sockaddr *)&sad, sizeof(sad));
    assert(ret == 0);

    ret = listen(g_test_server_socket, 3);
    assert(ret == 0);

    while(1) {
        go_to_poll();
    }

    return 0;

}

int go_to_poll(void)
{
    struct sockaddr_in  cad;
    int                 len    = sizeof(struct sockaddr_in);
    int                 new_fd = 0;
    int                 index  = 0;
    char                buf[100];
    int                 bytes  = -1;
    int                 ret    = 0;
    struct epoll_event  eva[10]= {0};
    struct epoll_event  ev     = {0};

    printf( "%s(): called: \n", __FUNCTION__);

    ret = epoll_wait(epfd, eva, 1, 1000);
    if(ret < 0) {
        return;
    }

    printf( "%s(): out of epoll wait\n", __FUNCTION__);

    if (eva[0].data.fd == g_test_server_socket) {

        new_fd = accept(g_test_server_socket, (struct sockaddr*)&cad, 
                                    (socklen_t *)&len);

        g_test_accept_socket_array[0] = new_fd;

        new_fd = -1;

        ev.events = EPOLLIN;
        ev.data.fd = g_test_accept_socket_array[0];
        ret = epoll_ctl(epfd, EPOLL_CTL_ADD, g_test_accept_socket_array[0], &ev);
        assert(ret != -1);

        printf("%s(): New connection from 0x%x on socket %d\n",
               __FUNCTION__, cad.sin_addr.s_addr,
               g_test_accept_socket_array[0]);

    } else if (eva[0].data.fd == g_test_accept_socket_array[0]){

        printf("%s(): data on socket: %d, event: 0x%x\n",
               __FUNCTION__,
               g_test_accept_socket_array[0], eva[0].events);

        char buf[100];
        ret = recv(g_test_accept_socket_array[0], buf, sizeof(buf), 0);

        printf("%s(): ret: %d\n", __FUNCTION__, ret);

        if (ret == 0) {
            close(g_test_accept_socket_array[0]);
        }

    }

    return 0;
}

void* ipv4_tcp_client(void* param)
{
    struct sockaddr_in  sad;
    int                 sd   = 0;
    char                buf[50];
    int                 n = 0;
    int                 bytes = 0;

retry_client:
    memset(&sad, 0, sizeof(sad));

    sad.sin_family = AF_INET; 
    sad.sin_port = 6767;
    sad.sin_addr.s_addr  = 0;
   
    sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf( "%s(%d): addr 0x%x\n",
            __FUNCTION__, sd,sad.sin_addr.s_addr);


    if (sd < 0) {
        printf( "%s(): Socket creation failed\n", __FUNCTION__);
        return 0;
    }

    sleep(5);

    while (connect(sd, (struct sockaddr *)&sad, sizeof(sad)) < 0) {
        printf( "%s(): addr 0x%x\n",
                __FUNCTION__, sad.sin_addr.s_addr);
        printf( "%s(): Connect failed, retrying....\n", __FUNCTION__);
        close(sd);
        usleep(1000000);
        goto retry_client;
    }

    sleep(1);
    close(sd);
    
    printf( "%s(): client closed\n", __FUNCTION__);


    sleep(10);

    printf("%s(): closing epfd: %d\n", __FUNCTION__, epfd);

    close(epfd);

    return 0;

}
#if 0
void prepare_client_file()
{
    int   i = 0;
    int   j = 0;

    memset(client_filename, 0, sizeof(client_filename));
    snprintf((client_filename, sizeof(client_filename), "/tmp/%s.tmp.socketserver.test.file.client",
        getenv("USER"));

    memset(server_filename, 0, sizeof(server_filename));
    snprintf(server_filename, sizeof(server_filename), "/tmp/%s.tmp.socketserver.test.file.server",
        getenv("USER"));

    client_file_p = fopen(client_filename, "w");

    for (i = 0; i < 10; i ++) {
        for (j = 0; j < 10; j ++) {
            fprintf(client_file_p, "This is test file to transfer, count %d:%d\n", i, j);
        }
    }

    fclose(client_file_p);

    return;

}
#endif

int main()
{
    //prepare_client_file();

    if (pthread_create(&s_thread, NULL, ipv4_tcp_server, 0))
    {
        printf( "%s(): pthread_create() failed\n", __FUNCTION__);
        return 0;
    }

    if (pthread_create(&c_thread, NULL, ipv4_tcp_client, 0))
    {
        printf( "%s(): pthread_create() failed\n", __FUNCTION__);
        return 0;
    }
#if 0
    client_param2[0] = 0; // to send file
    client_param2[1] = server_param[0];
    client_param2[2] = ip2;
    if (pthread_create(&c_thread2, NULL, ipv4_tcp_client, client_param2))
    {
        printf( "%s(): pthread_create() failed\n", __FUNCTION__);
        return FAIL;
    }
    pthread_join(c_thread2, 0);

#endif

    pthread_join(c_thread, 0);

    pthread_join(s_thread, 0);


    return 0;
}

