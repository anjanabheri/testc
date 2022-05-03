
#include "../include.h"
#include "assert.h"

typedef struct node
{
    int data;
    struct node * next;
} node;

node* new_node(int data)
{
    node * new = malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

node *head;

void init()
{
    head = new_node(2); 
    head->next = new_node(3);
#if 0
    head->next->next = new_node(5);
    head->next ->next->next= new_node(7);
    head->next->next->next->next = new_node(8);
    head->next->next->next->next->next = new_node(9);
    head->next->next->next->next->next->next = new_node(12);
    head->next->next->next->next->next->next->next = new_node(13);
#endif
}

void print()
{
    int count = 0;
    node *traverse = head;
    printf("\n");
    while (traverse != NULL)
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;

        count ++;

        if (count > 10)
            break;
    }
}

void reverse()
{
    node* prev;
    node* curr;
    node* next;

    prev = NULL;
    curr = head;
    next = head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void reverse2(node* prev, node* current)
{

}

int main()
{
    init();
    print();
    print();

    reverse(head);
    print();

    return 0;
}

