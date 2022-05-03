
#include "../include.h"
#include "assert.h"

//Finding kth element

typedef struct node
{
    int data;
    struct node *next; 
} NODE ;

NODE* head;
NODE* mid;

int main()
{
    int data = 0;
    int operation = 0;

    head = NULL;

    while (1)
    {
        printf("input format: operation (0: del, 1: add, 2: display, 3: kth element from last, 4: find mid, 8: add few, 9: exit)\n");
        scanf("%d", &operation);

        switch (operation)
        {
            case 0:
                printf("\nenter the number: ");
                scanf("%d", &data);
                break;
            case 1:
                printf("\nenter the number: ");
                scanf("%d", &data);
                break;
            case 3:
                printf("\nenter the k value: ");
                scanf("%d", &data);
                break;
            case 9:
                printf("exiting\n");
                break;
            default:
                break;
        }

        handle(operation, data);
    }
}

int handle(int operation, int data)
{
    switch (operation)
    {
        case 0:
            delete(data);
            break;
        case 1:
            insert(data);
            break;
        case 2:
            display();
            break;
        case 3:
            find_k_data(data);
            break;
        case 4:
            find_mid();
            break;
        case 8:
            insert(9);
            insert(2);
            insert(1);
            insert(6);
            insert(7);
            insert(10);
            break;
        default:
            printf("invalid input\n");
    }
}

int insert(int data)
{
    NODE* current = head;
    NODE* prev = head;
    NODE* new = NULL;

    new = malloc(sizeof(NODE));
    new->data = data;
    new->next = NULL;

    /*case: first node or if needs to be inserted as first node*/
    if ((head == NULL) || (head->data >= data))
    {
        new->next = head;
        head = new;
    }
    else
    {
        while ((current->next) && (current->next->data < data))
        {
            current = current->next;
        }

        new->next = current->next;
        current->next = new;
    }

    display();
}

int insert_and_return_mid(int data)
{
    NODE* current = head;
    NODE* prev = head;
    NODE* new = NULL;
    NODE* mid = NULL;
    boolean slow_move = FALSE;
    boolean op_done = FALSE;
    NODE* slow = NULL;

    new = malloc(sizeof(NODE));
    new->data = data;
    new->next = NULL;

    while (1)
    {
        if (head == NULL)
            head = temp;
        else if (current->data >= data)
            current = current->next;
    }

    /*case: first node or if needs to be inserted as first node*/
    if ((head == NULL) || (head->data >= data))
    {
        new->next = head;
        head = new;
    }
    else
    {
        while ((current->next) && (current->next->data < data))
        {
            current = current->next;
        }

        new->next = current->next;
        current->next = new;
    }

    display();
}

int delete(int data)
{
    display();
}

int find_mid()
{

    NODE* slow = NULL;
    NODE* fast = NULL;

    slow = head;
    fast = head;

    while ((fast != NULL) && (fast->next != NULL))
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (slow)
        printf("mid element: %d\n", slow->data);
    else
        printf("no mid element\n");

}

int find_k_data(int k)
{
    NODE* current = head;
    NODE* knode = head;
    int count = 0;

    while (current)
    {
        current = current->next;
        count ++;

        if (count > k)
        {
            knode = knode->next;
        }
    }

    if (knode)
        printf("kth node: %d\n", knode->data);
    else
        printf("kth node: not found\n");
}

int display()
{
    NODE* temp = head;

    printf("list: ");

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("null\n");
}
