#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Problem: https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks
//Two cases are not passing due to timeout

typedef struct _node
{
    struct _node *next;
    int data;
} node;

node* stack1;
node* stack2;
node** data_stack;
int front_data_in_stack1 = -1;

void push(node** stack, node* new)
{
    new->next = *stack;
    *stack = new;

    return;
}

node* pop(node** stack)
{
    if (stack == NULL)
        return NULL;

    node* temp = *stack;
    *stack = (*stack)->next;

    return temp;
}

void enque(int data)
{
    node** other_stack;
    node* move = NULL;

    node* new = malloc(sizeof(node));
    new->data = data;

    if (data_stack == &stack1)
    {
        other_stack = &stack2;
    }
    else
    {
        other_stack = &stack1;
    }

    if (data_stack == &stack1)
    {
        if (stack1 == NULL)
            front_data_in_stack1 = new->data;
        push(data_stack, new);
    }
    else
    {
        if (stack2 == NULL)
            front_data_in_stack1 = new->data;
        while(*data_stack != NULL)
        {
            move = pop(data_stack);
            push(other_stack, move);
        }
        data_stack = other_stack;
        push(data_stack, new);
    }
}

int deque()
{
    node* move = NULL;
    int data = -1;

    node** other_stack = NULL;

    if (*data_stack == NULL)
        return -1;

    if (data_stack == &stack1)
    {
        other_stack = &stack2;
    }
    else
    {
        other_stack = &stack1;
    }

    if (data_stack == &stack1)
    {
        while(*data_stack != NULL)
        {
            move = pop(data_stack);
            push(other_stack, move);
        }
        data_stack = other_stack;
    }

    node* temp = pop(data_stack);
    data = temp->data;
    free(temp);

    if (*data_stack)
        front_data_in_stack1 = (*data_stack)->data;
    else
        front_data_in_stack1 = -1;

    return data;
}

void front()
{
    node* temp = *data_stack;
    int data = -1;

    if ((stack2 != NULL) && (data_stack == &stack2))
    {
        data = temp->data;
    }
    else
    {
        data = front_data_in_stack1;
    }

    printf("%d\n", data);
}

void debug()
{
    if (data_stack == &stack1)
        printf("Data stack: Stack1\n");
    else
        printf("Data stack: Stack2\n");

    node* temp = *data_stack;
    while (temp != NULL)
    {
        printf("[%d]", temp->data);
        if (temp->next != NULL)
            printf("<--");
        temp = temp->next;
    }

    printf("\n");
    return;
}

int main()
{
    int input_type = 0;
    int data;
    int q = 0;
    int i = 0;

    data_stack = &stack1;

    scanf("%d", &q);

    for (i = q; i > 0; i --)
    {
        scanf("%d", &input_type);

        switch(input_type)
        {
            case 1:
                scanf("%d", &data);
                if ((data < 1) || (data > 1000000000))
                    return 0;
                enque(data);
                break;

            case 2:
                deque();
                break;

            case 3:
                front();
                break;

            case 9:
                debug();
                break;

            default:
                return 0;
        }
    }

    return 0;
}

