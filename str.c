#include <stdio.h>
#include <stdlib.h>

    int 
main(int argc, char** argv)
{
    unsigned char buff[256];

    unsigned char src[46] = { \
        0x00, 0x0C, 0xFC, 0x00, 0x00, 0x02, 0x00, 0x0C, 0xFC, 0x00, 0x00, 0x07, 0x81, 0x00, 0x01, 0x10, \
            0x08, 0x00, 0x45, 0x00, 0x00, 0x32, 0x00, 0x01, 0x00, 0x00, 0x40, 0x11, 0x00, 0x00, 0x01, 0x01, \
            0x01, 0x0a, 0x01, 0x01, 0x01, 0x01, 0x27, 0x10, 0x13, 0x8A, 0x00, 0x1E, 0x00, 0x00 \

    };

    int i;
    int j=0;
    for ( i = 0; i <10; ++i) {

        j += sprintf(buff+j, "%02x", src[i]);
    }
    buff[i]= 0;
    printf("source string = %s\n", buff);
    return 0;
}	
