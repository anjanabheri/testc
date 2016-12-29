#include <stdio.h>
#include <malloc.h>


typedef struct _slnode
{
    int data;
    struct _slnode *next;
}slnode;

slnode *list;


slnode* new_node(int data)
{
    slnode* node = malloc(sizeof(slnode));
    node->data = data;
    node->next = 0;
    return node;
}

void insert_at_tail(data)
{
    printf("%s(): %d :\n", __FUNCTION__, __LINE__);

    slnode *cur = list;
    
    if(0 == list)
    {
        list = new_node(data);
        return;
    }
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = new_node(data);
    return;
}


display_sll()
{
    slnode *cur = list;

    printf("\n");

    while (cur)
    {
        printf("  %d  --> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");

}

void sort_insert_2(int data)
{
    slnode* node = new_node(data);

    slnode* temp = 0;
    slnode* cur  = list;
    
    if (list == 0)
    {
        list = node;
        return;
    }
    
    cur = list;

    while (cur)
    {
        if ((cur->data <= data) && (cur->next->data < data))
        {
            temp = cur->next;
            cur->next = node;
            node->next = temp;
        }
        else if
    }
}

void sort_insert(int data)
{
    slnode* next = 0;
    slnode* cur  = 0;
    slnode* new  = 0;
    slnode* temp = 0;

    new = new_node(data);

    if(list == 0)
    {
        list = new;
        return;
    }

    cur = list;
    next = cur->next;

    while(cur)
    {
        if((cur->data <= data) && ((next == NULL) || (next->data >= data)))
        {
            temp = cur->next;
            cur->next = new;
            new->next = temp;
            return;
        }
        else if ((cur->data > data) || (next == NULL))
        {
            list = new;
            new->next = cur;
            return;
        }
        cur = next;
        next = next->next;
    }
}

void delete(int data)
{
    slnode* traverse = list;
    slnode* temp = list;

    printf("%s(): %d : data: %d\n", __FUNCTION__, __LINE__, data);

    if (list == 0)
    {
        return;
    }

    while (traverse->next)
    {
        if (traverse->data == data)
        {
            break;
        }
        temp = traverse;
        traverse = traverse->next;
    }

    if (traverse->data == data)
    {
        temp->next = traverse->next; 
        if (traverse == list)
        {
            list = traverse->next;
        }
        free(traverse);
    }

    return;
}

void delete_all_occurance(int data)
{
    slnode* traverse = list;
    slnode* temp = list;

    printf("%s(): %d : data: %d\n", __FUNCTION__, __LINE__, data);

    if (list == 0)
    {
        return;
    }

    while (traverse->next)
    {
        if (traverse->data == data)
        {
            temp->next = traverse->next;
            free(traverse);
        }
        temp = traverse;
        traverse = traverse->next;
    }

    return;
}

void reverse_list()
{
    slnode* prev;
    slnode* cur;
    slnode* temp;

    prev = 0;
    cur  = list;

    if (0 == list)
    {
        return;
    }

    while(cur)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    list = prev;

}

void find_middle_node()
{
    slnode* scan        = list;
    slnode* scan_double = list;

    if (list == 0)
    {
        printf("\n List Empty \n");
        return;
    }

    while (scan_double)
    {
        scan = scan->next;
        scan_double = (scan_double->next)->next;
    }

    printf("\n Middle Node: %p, data: %d \n", scan, scan->data);
}


void test_1_reverse_sll()
{
    display_sll();
    reverse_list();
    display_sll();
    insert_at_tail(5);
    insert_at_tail(3);
    insert_at_tail(9);
    insert_at_tail(10);
    display_sll();
    reverse_list();
    display_sll();
}

void test_2_sorted_insert_and_find_middle()
{
    display_sll();
    sort_insert(10);
    sort_insert(8);
    sort_insert(49);
    sort_insert(25);
    sort_insert(41);
    sort_insert(3);
    sort_insert(33);
    sort_insert(13);
    sort_insert(3);
    sort_insert(21);
    display_sll();
    find_middle_node();
}

void test_3_insert_and_delete()
{
    printf("SLL first\n");
    display_sll();
    delete(10);
    printf("SLL after deleting non-existing node\n");
    display_sll();
    insert_at_tail(9);
    insert_at_tail(4);
    insert_at_tail(1);
    insert_at_tail(4);
    insert_at_tail(5);
    insert_at_tail(3);
    insert_at_tail(7);
    insert_at_tail(4);
    insert_at_tail(9);
    insert_at_tail(8);
    printf("SLL after inserting all nodes\n");
    display_sll();
    delete(9);
    printf("SLL after deleting first node\n");
    display_sll();
    delete(1);
    printf("SLL after deleting middle node 1\n");
    display_sll();
    delete(8);
    printf("SLL after deleting last node 8\n");
    display_sll();

}

void test_4_insert_and_delete_all_occurance()
{
    printf("SLL first\n");
    display_sll();
    insert_at_tail(9);
    insert_at_tail(4);
    insert_at_tail(1);
    insert_at_tail(4);
    insert_at_tail(5);
    insert_at_tail(3);
    insert_at_tail(7);
    insert_at_tail(4);
    insert_at_tail(9);
    insert_at_tail(8);
    printf("SLL after inserting all nodes\n");
    display_sll();
    delete_all_occurance(4);
    printf("SLL after deleting all occurance of 4\n");
    display_sll();
    reverse_list();
    printf("SLL after reversing the list\n");
    display_sll();

}

void test_5_sort_insert()
{
    printf("SLL first\n");
    display_sll();
    sort_insert_2(9);
    sort_insert_2(4);
    printf("SLL after inserting new node\n");
    display_sll();
    sort_insert_2(1);
    printf("SLL after inserting new node\n");
    display_sll();
    sort_insert_2(4);
    sort_insert_2(5);
    sort_insert_2(3);
    sort_insert_2(7);
    sort_insert_2(4);
    sort_insert_2(9);
    sort_insert_2(8);
    printf("SLL after inserting all nodes\n");
    display_sll();

}

main()
{
    //test_1_reverse_sll();
    //test_2_sorted_insert_and_find_middle();
    //test_3_insert_and_delete();
    //test_4_insert_and_delete_all_occurance();
    test_5_sort_insert();
}



