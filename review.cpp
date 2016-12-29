#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define FAILURE -1
#define MAX_SITE_BYTES 100000
#define MAX_IMAGE_LENGTH 200 ;

// Error Strings
#define USAGE "Usage: get-image-urls <url>\r\n"
#define DNS_FAIL "DNS Lookup Failed\r\n" 
#define SOCKET_FAIL "Failed to Open Socket\r\n"
#define CONNECT_FAIL "Failed on Connect Call\r\n"
#define WRITE_FAIL "Failed on Write\r\n"
#define CLOSE_FAIL "Failed on Close\r\n"

// Macros
#define EXIT( STRING ) printf( STRING ) ; _exit( FAILURE ) 
#define forever for ( ; ; ) 

typedef char* String ;

int main( int argc, const String argv[] ) {
    if( argc != 2 ) {
        EXIT( USAGE ) ;
    }
    String url = argv[ 1 ] ;
    String in = strstr( url, "http://" ) ;
    char host[1000] ;
        if( in ) {
                strcpy( url, (String) ( url  + 7  ) ) ;
        }
        in = index ( url, '/' ) ;
        String path ;
        if( in ) {
                int div = in - url;
                path = (String)(url + div) ;
                strncpy( host, url, div ) ;
                host[ div ] = '\0' ;
        } else {
                path = "/" ;
                strcpy( host, url ) ;
        }

    printf("in: %s, host: %s \n", in, host);
    
    return 0 ;
}

