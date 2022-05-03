
#include "include.h"

typedef union ip6_union_ipv6_address {
    UINT8   address8[16];
    UINT16  address16[8];
    UINT32  address32[4];
} IP6_UNION_IPV6_ADDRESS;

typedef struct {
    IP6_UNION_IPV6_ADDRESS address;
} IPV6_ADDRESS;

USHORT checksum = 0x85;
UINT32  old_addr[4] = {0xEE000081, 0x0, 0x0, 0x01};
UINT32  new_addr[4] = {0x26200107, 0x90d0aa09, 0x0, 0x0192};
//UINT32  new_addr[4] = {0xEE000081, 0x0, 0x0, 0x01};
//UINT32  new_addr[4] = {0, 0, 0, 0};

//USHORT data1[] = {0x000c, 0x0011, 0xee00, 0x0081, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x2620, 0x0107, 0x90d0, 0xa192, 0x0250, 0x56ff, 0xfeb8, 0xa5d9, 0xc20f, 0xeddd, 0x000c, 0x0000, 0x0004, 0x0971};
//USHORT data2[] = {0x000c, 0x0011, 0x2620, 0x0107, 0x90d0, 0xaa09, 0x0000, 0x0000, 0x0000, 0x0192, 0x2620, 0x0107, 0x90d0, 0xa192, 0x0250, 0x56ff, 0xfeb8, 0xa5d9, 0xc20f, 0xeddd, 0x000c, 0x0000, 0x0004, 0x0971};
USHORT data1[] = {0x000c, 0x0011, 0xee00, 0x0081, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x2620, 0x0107, 0x90d0, 0xa192, 0x0250, 0x56ff, 0xfeb8, 0xa5d9, 0xc20f, 0xeddd, 0x000c, 0x0000, 0x0004, 0x0971};
USHORT data2[] = {0x000c, 0x0011, 0x2620, 0x0107, 0x90d0, 0xaa09, 0x0000, 0x0000, 0x0000, 0x0192, 0x2620, 0x0107, 0x90d0, 0xa192, 0x0250, 0x56ff, 0xfeb8, 0xa5d9, 0xc20f, 0xeddd, 0x000c, 0x0000, 0x0004, 0x0971};

USHORT ip_calculate_incr_checksum_for_4byte_data (USHORT orig_checksum, UINT32 old_data, UINT32 new_data);
USHORT ip6_calculate_incr_checksum_for_ipv6_address(USHORT orig_checksum, UINT32* old_address, UINT32* new_address);
USHORT ip_calculate_incr_checksum (USHORT rx_checksum, USHORT rx_mss, USHORT new_mss);
USHORT new_ip_calculate_incr_checksum (USHORT rx_checksum, USHORT rx_mss, USHORT new_mss);
USHORT add_words_and_return_checksum(USHORT* bytes, USHORT len);

void main()
{
    USHORT new_checksum = 0;

    USHORT checksum1 = add_words_and_return_checksum(data1, sizeof(data1)/2);
    printf("data 1, checksum1: 0x%x\n", checksum1);

    printf("-----------------\n");

    USHORT checksum2 = add_words_and_return_checksum(data2, sizeof(data2)/2);
    printf("data 2, checksum2: 0x%x\n", checksum2);
    printf("-----------------\n");

#if 0
    new_checksum = ip6_calculate_incr_checksum_for_ipv6_address(checksum1, old_addr, new_addr);
    printf("INCR ON FULL DATA: old checksum: 0x%x, new: 0x%x\n", checksum1, new_checksum);

    new_checksum = ip6_calculate_incr_checksum_for_ipv6_address(checksum1, old_addr, new_addr);
    printf("INCR ON ADDR DATA: old checksum: 0x%x, new: 0x%x\n", checksum1, new_checksum);
#endif

    USHORT checksum3 = 0;
    USHORT checksum4 = 0;
    checksum3 =  ~checksum1 - (0xEE00 + 0x0081 + 0x0001);

    checksum4 = checksum3 + (0x2620 + 0x0107 + 0x90d0 + 0xaa09 + 0x0 + 0x0192);

    checksum4 = ~checksum4;

    printf("new checksum: 0x%x\n", checksum4);
    

    return;

#if 1

    USHORT old_1 = 0x117d;
    printf("ip_calculate_incr_checksum: old: %x, new: %x\n", old_1 , ip_calculate_incr_checksum(old_1, 0xEE82, 0x0000));
#endif

    new_ip_calculate_incr_checksum(old_1, 0xEE82, 0x0000);
}

USHORT my_incr_checksum(USHORT rx_checksum, USHORT rx_mss, USHORT new_mss)
{
    USHORT new = 0;

    new = ~(~rx_checksum - rx_mss + new_mss);
    //new = rx_checksum - ~rx_mss r - new_mss;

    return new;
}

USHORT new_ip_calculate_incr_checksum (USHORT rx_checksum, USHORT rx_mss, USHORT new_mss)
{
    USHORT new = 0;

    new = ~(~rx_checksum + ~rx_mss + new_mss);

    printf("new: 0x%x\n");  
}

USHORT ip_calculate_incr_checksum (USHORT rx_checksum, USHORT rx_mss, USHORT new_mss)
{
    UINT32 temp;
    USHORT new;

    //printf("rx: %x, ~rx: %x\n", rx_checksum, ~(rx_checksum));
    rx_checksum = ~(rx_checksum);

    //printf("rx_mss: %x, ~rx_mss: %x\n", rx_mss, ~(rx_mss));
    rx_mss = ~rx_mss;

    temp = (UINT32)(rx_checksum + rx_mss + new_mss);

    //printf("temp: 0x%x\n", temp);

#if 0
    if (temp == 0xFFFF)
        return temp;
#endif

    new = (~((USHORT)(temp >> 16) + (temp & 0xffff)));

    return new;
}

USHORT ip_calculate_incr_checksum_for_4byte_data (USHORT orig_checksum, UINT32 old_data, UINT32 new_data)
{       
    USHORT new_checksum = 0;
    USHORT old_data_word[2];
    USHORT new_data_word[2];
        
    old_data_word[0] = old_data & 0xFFFF;
    old_data_word[1] = old_data >> 16;
    
    new_data_word[0] = new_data & 0xFFFF;
    new_data_word[1] = new_data >> 16;
    
    new_checksum = my_incr_checksum(orig_checksum, old_data_word[0], new_data_word[0]);
    new_checksum = my_incr_checksum(new_checksum, old_data_word[1], new_data_word[1]);
    
    return new_checksum;
}   
        
USHORT ip6_calculate_incr_checksum_for_ipv6_address(USHORT orig_checksum, UINT32* old_address, UINT32* new_address)
{   
    USHORT new_checksum = 0;
    UINT32 index = 0;
                
    new_checksum = orig_checksum;
        
    for (index = 0; index < 4; index ++)
    {   
        new_checksum = ip_calculate_incr_checksum_for_4byte_data(new_checksum, old_address[index], new_address[index]);
    }
            
    return new_checksum;
}

USHORT add_words_and_return_checksum(USHORT* bytes, USHORT len)
{
    unsigned int sum = 0;
    unsigned int carry = 0;
    int i = 0;
    printf("num words: %u \n", len);


    for (i = 0; i < len; i ++)
    {  
        //printf("adding: 0x%x\n", bytes[i]);
        sum += bytes[i];
    }

    //printf("sum: 0x%x\n", sum);
    carry = sum >> 16;
    printf("carry: 0x%x\n", carry);

    USHORT checksum = (sum & 0xFFFF) + carry;

    printf("checksum calculated: 0x%x\n", ~checksum);

    return ~checksum;
}
