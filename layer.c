
#include "include.h"
#include "assert.h"

typedef unsigned char uchar;

typedef struct _packet_node
{
    struct _packet_node *next;
    uchar *packet;
    int size;

} packet_node;

int recv_packet(uchar* packet, int size);
int get_packet(uchar* buffer, int size, int offset);
int init();
//int free();

packet_node* head = NULL;

int recv_packet(uchar* packet, int size)
{
    packet_node* last_node = head;
    packet_node *new = malloc(sizeof(packet_node));

    if (new == NULL)
        return -1;

    new->size = size;
    new->packet = packet;

    if (head == NULL)
        head = last_node = new;
    else
    {
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new;
    }

    printf("debug: new packet, size: %d, new node: %p\n", size, new);

    return 0;
}

int get_packet(uchar* buffer, int size, int offset)
{
    packet_node* node = NULL;

    if ((buffer == NULL) ||
        (size == 0))
        return 0;

    printf("debug: packet read, size: %d, offset: %d \n");

    node = head;
    int remaining_len = size;
    int buffer_position = offset;
    int copy_length = 0;
    int copy_offset = 0;

    int debug_count = 0;

    while ((node != NULL) && (remaining_len > 0))
    {

        printf("debug: node count: %d, remaining_len: %d, buf_pos: %d, copy_offset: %d \n",
            debug_count, remaining_len, buffer_position, copy_offset);

        if (buffer_position > node->size)
        {
            buffer_position -= node->size;
        }
        else
        {
            if (remaining_len >= node->size)
                copy_length = node->size;
            else
                copy_length = remaining_len;

            memcpy(buffer + copy_offset, node->packet + buffer_position, copy_length);

            buffer_position = 0;

            copy_offset += copy_length;

            remaining_len -= copy_length;
        }
        node = node->next;
    }
}

int main()
{
    char s1[] = "My name is Anjan. ";
    char s2[] = "This is testing. ";
    char s3[] = "Let me see if this works";

    recv_packet(s1, strlen(s1));
    recv_packet(s2, strlen(s2));
    recv_packet(s3, strlen(s3));

    char *s = malloc(strlen(s1) + 100);

    get_packet(s, strlen(s1), 0);
    printf("packet: %s\n\n", s);

    memset(s, 0, strlen(s));
    get_packet(s, 25, 0);
    printf("packet2: %s\n\n", s);

    memset(s, 0, strlen(s));
    get_packet(s, 44, 0);
    printf("packet3: %s\n\n", s);


    memset(s, 0, strlen(s));
    get_packet(s, 80, 0);
    printf("packet4: %s\n\n", s);

    memset(s, 0, strlen(s));
    get_packet(s, 10, 5);
    printf("packet5: %s\n\n", s);

    memset(s, 0, strlen(s));
    get_packet(s, 10, 25);
    printf("packet5: %s\n\n", s);

    return 0;
}
