
#include "include.h"
#include "assert.h"

typedef struct node
{
    struct node* next;
    char* ptr;
    int len;
} NODE;

NODE* head = NULL;

void new_packet(char* buffer, int length)
{
    NODE* traverse = NULL;
    NODE* new_node = NULL;

    new_node = malloc(sizeof(NODE));
    new_node->next = NULL;
    new_node->ptr = buffer;
    new_node->len = length;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        traverse = head;
        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }

        traverse->next = new_node;
    }
}

void print_buffers()
{
    NODE* traverse = head;
    while (traverse)
    {
        printf("node: %x, buffer: %s, len: %u\n", traverse, traverse->ptr, traverse->len);
        traverse = traverse->next;
    }
}

int get_packet(char* buffer, int length, int offset)
{
    NODE* packet = NULL;
    int copy_length = 0;

    if (head == NULL)
    {
        return 1;
    }
    
    packet = head;

    while (packet != NULL)
    {
        printf("offset: %u, packet buffer: 0x%x \n", offset, packet);
        if (offset >= packet->len)
        {
            offset -= packet->len;
            packet = packet->next;
            printf("offset is not falling in this packet buffer, skipping this, offset reduced to: %u \n", offset);
            continue;
        }

        if (length > (packet->len - offset))
        {
            printf("length %u is still more, copying: %u bytes\n", length, packet->len - offset);
            memcpy(buffer + copy_length, packet->ptr + offset, packet->len - offset);
            length -= packet->len - offset;
            copy_length += packet->len - offset;
        }
        else if (length <= (packet->len - offset))
        {
            printf("copying length %u is needed, last copy\n", length);
            memcpy(buffer + copy_length, packet->ptr + offset, length);
            copy_length += length;
            length = 0;
        }

        offset = 0;

        if (length == 0)
        {
            break;
        }

        packet = packet->next;
    }

    return 0;
}

int main()
{
    char *s1 = "Twinkle twinkle "; 
    char *s2 = "little star. How "; 
    char *s3 = "I wonder what you are "; 
    char *s4 = "Up above the world so high"; 

    new_packet(s1, strlen(s1));
    new_packet(s2, strlen(s2));
    new_packet(s3, strlen(s3));
    new_packet(s4, strlen(s4));

    print_buffers();

    char buffer[300] = {0};
    int ret = get_packet(buffer, 30, 25);

    if (ret == 0)
    {
        printf("valid buffer, buffer: %s\n", buffer);
    }
    else
    {
        printf("buffers invalid\n");
    }


    return 0;
}

