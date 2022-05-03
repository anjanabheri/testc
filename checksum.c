
#include "include.h"
#include "assert.h"


#define BYTE unsigned char
#define UCHAR   unsigned char
    
#define WORD unsigned short
#define USHORT unsigned short
#define U16 unsigned short
#define UINT32 unsigned int
        
#define ULONG   unsigned long

char buffer[] = { 

0x00, 0x00, 
//length
0x00, 0x20,
0x00, 0x00, 0x00, 0x00,
//ttl
0x00, 
//proto
0x11, 
//checksum
0x00, 0x00,
//0xf3, 0xaf, 
//SIP
0x0a, 0xb1, 0x70, 0x22,
0x0a, 0x88, 0xc1, 0xad, 

//UDP data:
0xae, 0x71, 0x00, 0x45,
//length
0x00, 0x20, 
//checksum
0x00, 0x00, 
//data
0x00, 0x01, 0x6f, 0x6e,
0x65, 0x2e, 0x74, 0x78, 0x74, 0x00, 0x6f, 0x63,
0x74, 0x65, 0x74, 0x00, 0x74, 0x73, 0x69, 0x7a,
0x65, 0x00, 0x30, 0x00
};

char buffer2[] = { 

0x45, 0x00, 0x00, 0x34, 0x00, 0x01, 0x40, 0x00,
0x40, 0x11, 0xf3, 0xaf, 0x0a, 0xb1, 0x70, 0x22,
0x0a, 0x88, 0xc1, 0xad, 0xae, 0x71, 0x00, 0x45,
0x00, 0x20, 0x82, 0x20, 0x00, 0x01, 0x6f, 0x6e,
0x65, 0x2e, 0x74, 0x78, 0x74, 0x00, 0x6f, 0x63,
0x74, 0x65, 0x74, 0x00, 0x74, 0x73, 0x69, 0x7a,
0x65, 0x00, 0x30, 0x00
};


void print_packet2(char* buf, int num_bytes )
{
    int i;

    for(i=0; i < num_bytes; i++) {

        printf( "0x%02x, ", (int)buf[i] );
        if((i) && ((i%8)==7))
            printf( "\n" );
    }
    printf( "\n" );
}

static USHORT end_around_carry (ULONG sum)              /* Carries in high order 16 bits */
{
    USHORT csum;
    USHORT return_value;

    csum = (USHORT) (sum >> 16);

    while (csum != 0x0000)
        {
        sum = csum + (sum & 0xffffL);

        csum = (USHORT) (sum >> 16);
        }

    /* Chops to 16 bits */

    return_value = (USHORT) (sum & 0x0000ffffL);

    return (return_value);
}


static USHORT calculate_word_checksum (USHORT *usptr_short, USHORT length)
{
    ULONG sum;
    USHORT result;

    sum = 0x00000000L;
    
    while (length != 0x0000)
        {
        --length;

        sum += *usptr_short;
        printf("word: 0x%x\n", *usptr_short);
        
        ++usptr_short;
        }
        
    result = end_around_carry (sum);

    return (result);
}

USHORT calculate_ip_checksum (BYTE *from, USHORT length)
{
    USHORT word_checksum;
    ULONG sum; 
    ULONG checksum;
    USHORT return_value;

    sum = 0x00000000L;

#if 0
    if (sptr_pseudo_header != NULL)
        {    
        word_checksum = calculate_word_checksum ((USHORT *) sptr_pseudo_header, (USHORT) (sizeof (PSEUDO_IP_PARAMETERS)) >> 1);

        sum = word_checksum;
        }    
#endif

    checksum = 0x00000000L;

    if (length > 1) 
        {    
        /* ptr_start_from must be on short word boundary */

        word_checksum = calculate_word_checksum ((USHORT *) from, (USHORT) (length >> 1)); 

        checksum += word_checksum;
        }    

#if 0
    /* Handle odd trailing byte */

    if (length & 1) 
        {    
#ifndef BIG_ENDIAN
        checksum += (unsigned char) (from[--length]);
#else
        checksum += (USHORT) (((unsigned char) (from[--length])) << 8);
#endif
        }    
#endif

    sum += checksum;

    /* Do final end-around carry, complement and return */

    return_value = (USHORT) (~end_around_carry (sum) & 0xffff);

    return (return_value);
}

USHORT words[] =
{
0x0ab1,
0x7022,
0x0a88,
0xc1ad, 
0x0011,
0x0020,

0xae71, 
0x0045,
0x0020,

0x0001,
0x6f6e,
0x652e,
0x7478,
0x7400,
0x6f63,
0x7465,
0x7400,
0x7473,
0x697a,
0x6500,
0x3000

};


USHORT words2[] =
{
0xc0a8,
0x001f,
0xc0a8,
0x001e,
0x0011,
0x000a,
0x0014,
0x000a,
0x000a,
0x4869
};

USHORT ip1[] = {
0x4500, 0x0026, 0xcc9d, 0x0000,
0x3a11, 0x0000, 0x0a88, 0xc1ad,
0x1801, 0x0101, 0xa0b9, 0x8ba2,
0x0012, 0x0000, 0x0006, 0x7473,
0x697a, 0x6500, 0x3600,
};

USHORT add_words(USHORT* bytes, USHORT len)
{
    unsigned int sum = 0;
    unsigned int carry = 0;
    int i = 0;
    printf("num words: %u \n", len);


    for (i = 0; i < len; i ++)
    {
        printf("adding: 0x%x\n", bytes[i]);
        sum += bytes[i];
    }

    printf("sum: 0x%x\n", sum);
    carry = sum >> 16;
    printf("carry: 0x%x\n", carry);

    USHORT checksum = (sum & 0xFFFF) + carry;

    return checksum;
    
}


void calc()
{
    int length = sizeof(buffer);
    int i = 0;

    //print_packet2(buffer, length);

    //USHORT checksum = calculate_word_checksum((USHORT*)buffer, 52);
    //unsigned int checksum = add_words(words, 21);
    //USHORT len = sizeof(words2)/sizeof(words2[0]);
    //USHORT checksum = add_words(words2, len);

    //USHORT len = sizeof(words)/sizeof(words[0]);
    //USHORT checksum = add_words(words, len);

    USHORT len = sizeof(ip1)/sizeof(ip1[0]);
    USHORT checksum = add_words(ip1, len);
    printf("checksum: 0x%x \n", checksum);
    printf("checksum: 0x%x \n", ~checksum);
}

USHORT ip_calculate_incr_checksum (USHORT rx_checksum, USHORT rx_mss, USHORT new_mss)
{
     UINT32 temp;
     rx_checksum = ~(rx_checksum);
     rx_mss = ~rx_mss;
     temp = (UINT32)rx_checksum + rx_mss + new_mss;
     return (~((USHORT)(temp >> 16) + (temp & 0xffff)));
}

USHORT data1[] = 
{
0x0000, 0x0000, 0x002d, 0x0011,
0x5001, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0002,
0x5001, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0001,
0xa1ba, 0x0045, 0x002d, 0x0,
0x0001, 0x6f6e, 0x652e, 0x6366,
0x6700, 0x6f63, 0x7465, 0x7400,
0x626c, 0x6b73, 0x697a, 0x6500,
0x3134, 0x3638, 0x0074, 0x7369,
0x7a65, 0x0030, 0x00
};

//Received in DUT1
USHORT data2[] =
{
0x00, 0x0000, 0x002d, 0x11,
0x5001, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0002,
0x5001, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0001,
0xbd73, 0x0045, 0x002d, 0x0,
0x0001, 0x6f6e, 0x652e, 0x6366,
0x6700, 0x6f63, 0x7465, 0x7400,
0x626c, 0x6b73, 0x697a, 0x6500,
0x3134, 0x3638, 0x0074, 0x7369,
0x7a65, 0x0030, 0x00
};

//Received in DUT2

USHORT data3[] = 
{
0x00, 0x0000, 0x0020, 0x11,
0x5001, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0001,
0x5001, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0002,
0x9cef, 0xc030, 0x0020, 0x0,
0x0006, 0x626c, 0x6b73, 0x697a,
0x6500, 0x3134, 0x3638, 0x0074,
0x7369, 0x7a65, 0x0032, 0x3700
};

void main()
{
    int length = sizeof(data3)/2;

    printf("length: %d\n", length);
    USHORT checksum = add_words(data3, length);

    printf("checksum: 0x%x \n", ~checksum);
}


void fun1()
{
    USHORT origc = 0x8683;
    UINT32 origsip = 0x15010101;
    UINT32 newsip = 0x0ab17094;

    USHORT newc = 0;

    USHORT old_data_word[2];
    USHORT new_data_word[2];
    old_data_word[0] = origsip & 0xFFFF;
    old_data_word[1] = origsip >> 16;

    new_data_word[0] = newsip & 0xFFFF;
    new_data_word[1] = newsip >> 16;

    newc = ip_calculate_incr_checksum(origc, old_data_word[0], new_data_word[0]);
    newc = ip_calculate_incr_checksum(newc, old_data_word[1], new_data_word[1]);

    printf("oldc: 0x%x, newc: 0x%x\n", origc, newc);
}
