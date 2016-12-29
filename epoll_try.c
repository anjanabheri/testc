
#include <sys/epoll.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

main()
{
   struct epoll_event ev = {0};

   int epfd = epoll_create(1);

   int fd = socket(AF_INET, SOCK_STREAM, 0);

   ev.data.fd = fd;
   ev.events = EPOLLIN;

   int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);

   printf("epoll_ctl: ret: %d, epfd: %d, fd: %d, ev.events: 0x%x, errno: %d\n", ret, epfd, fd, ev.events, (ret<0)? errno:0);
   fflush(0);
   
   ev.data.fd = fd;
   ev.events = EPOLLOUT;

   ret = epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);

   printf("epoll_ctl: ret: %d, epfd: %d, fd: %d, ev.events: 0x%x, errno: %d\n", ret, epfd, fd, ev.events, (ret<0)? errno:0);
   fflush(0);
   
   ev.data.fd = fd;
   ev.events = 0;
   ret = epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);

   printf("epoll_ctl: ret: %d, epfd: %d, fd: %d, ev.events: 0x%x, errno: %d\n", ret, epfd, fd, ev.events, (ret<0)? errno:0);
   fflush(0);


   ev.data.fd = fd;
   ev.events = EPOLLIN;

   ret = epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);

   printf("epoll_ctl: ret: %d, epfd: %d, fd: %d, ev.events: 0x%x, errno: %d\n", ret, epfd, fd, ev.events, (ret<0)? errno:0);
   fflush(0);

   close(fd);


   fd = socket(AF_INET, SOCK_STREAM, 0);

   ev.data.fd = fd;
   ev.events = EPOLLIN;

   ret = epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);

   printf("epoll_ctl: ret: %d, epfd: %d, fd: %d, ev.events: 0x%x, errno: %d\n", ret, epfd, fd, ev.events, (ret<0)? errno:0);
   fflush(0);


   ev.data.fd = fd;
   ev.events = EPOLLIN | EPOLLOUT;

   ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);

   printf("epoll_ctl: ret: %d, epfd: %d, fd: %d, ev.events: 0x%x, errno: %d\n", ret, epfd, fd, ev.events, (ret<0)? errno:0);
   fflush(0);

   ev.data.fd = fd;
   ev.events = EPOLLOUT;

   ret = epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &ev);

   printf("epoll_ctl: ret: %d, epfd: %d, fd: %d, ev.events: 0x%x, errno: %d\n", ret, epfd, fd, ev.events, (ret<0)? errno:0);
   fflush(0);


   ev.data.fd = fd;
   ev.events = EPOLLOUT;

   ret = epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);

   printf("epoll_ctl: ret: %d, epfd: %d, fd: %d, ev.events: 0x%x, errno: %d\n", ret, epfd, fd, ev.events, (ret<0)? errno:0);
   fflush(0);


}
