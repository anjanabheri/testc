
#include "include.h"

int main()
{
    char buf[16];
    char buf2[100];
    memset(buf, 0, sizeof(buf));
    memset(buf2, 0, sizeof(buf2));
    string ip = "1111:2222::3333:4444";
    string result;

    if(!inet_pton(AF_INET6, ip.c_str(), buf)){
        fprintf(stderr, "Could not convert address\n");
        return 0;
    }

    if(inet_ntop(AF_INET6, buf, buf2, 100) == NULL)
    {
        fprintf(stderr, "Could not convert byte to address\n");
        fprintf(stderr, "%s\n",strerror(errno));
        return -3;
    }

    cout << "converted: " << buf2 << endl;

    return 0;
}
