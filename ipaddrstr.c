
#include "include.h"
#include "assert.h"


int ip_string_to_address(const char* ip_string, unsigned int* ip)
{
    struct in_addr ip_address;
    if(inet_pton(AF_INET, ip_string, &ip_address))
    {
        *ip = ip_address.s_addr;
        return 1;
    }
    return 0;
}

const char * ip_std_lib_ip_addr_to_string (const void *src)
{
    static char buf[INET_ADDRSTRLEN];

    if (!src) {
        snprintf(buf, INET_ADDRSTRLEN, "Err::Err");
        return buf;
    }

    return inet_ntop(AF_INET, src, buf, INET_ADDRSTRLEN);
}

void convert_ip_address(char *str)
{
    int address = 0;

    int result = ip_string_to_address(str, &address);

    printf("result: %u, address: 0x%x (%u)\n", result, address, ntohl(address));

    char buf[50];

    printf("converting back to string, ip address: %s\n", ip_std_lib_ip_addr_to_string(&address));
    
}

main()
{
    convert_ip_address("10.11.12.13");
    convert_ip_address("172.26.67.235");
}
