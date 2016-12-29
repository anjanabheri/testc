
#include "../include.h"

typedef struct _node
{
    struct _node* next;
    int           data;
} node;

node* createNode(int data);
void insert(node** head, int data);
void sortInsert(node** head, int data);
void display(node* head);
node* mergeTwoSortedList(node* list1, node* list2);

int main()
{
    node* list1 = NULL;
    node* list2 = NULL;
    node* list3 = NULL;

    insert(&list1, 10);
    insert(&list1, 12);
    insert(&list1, 11);
    insert(&list1, 18);
    insert(&list1, 18);
    insert(&list1, 19);
    insert(&list1, 20);
    insert(&list1, 30);
    insert(&list1, 25);

    cout << "list 1" << endl;
    display(list1);

    sortInsert(&list2, 5);
    sortInsert(&list2, 12);
    sortInsert(&list2, 21);
    sortInsert(&list2, 33);
    sortInsert(&list2, 7);
    sortInsert(&list2, 7);
    sortInsert(&list2, 10);
    sortInsert(&list2, 3);
    sortInsert(&list2, 8);

    cout << "list 2" << endl;
    display(list2);

    sortInsert(&list3, 2);
    sortInsert(&list3, 13);
    sortInsert(&list3, 21);
    sortInsert(&list3, 35);
    sortInsert(&list3, 8);
    sortInsert(&list3, 8);
    sortInsert(&list3, 11);
    sortInsert(&list3, 1);
    sortInsert(&list3, 2);

    cout << "list 3" << endl;
    display(list3);

    node* mergeList = NULL;

    mergeList = mergeTwoSortedList(list2, list3);

    cout << "merging list 2 & 3" << endl;
    display(mergeList);

    return 0;
}

node* createNode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void insert(node** head, int data)
{
    node* newNode = NULL;
    node* temp = NULL;

    newNode = createNode(data);

    if (*head == NULL)
    {
        //first node
        *head = newNode;
        return;
    }
    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return;
}

void sortInsert(node** head, int data)
{
    node* newNode = NULL;
    node* temp = NULL;

    newNode = createNode(data);

    if ((*head == NULL) || ((*head)->data >= data))
    {
        //first node
        temp = *head;
        *head = newNode;
        newNode->next = temp;
        return;
    }
    temp = *head;

    while((temp->next != NULL) && (temp->next->data < data))
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return;
}

void display(node* head)
{
    node* temp = head;

    cout << endl;

    while (temp != NULL)
    {
        cout << " " << temp->data << " --> ";
        temp = temp->next;
    }
    cout << " NULL" << endl << endl;

    return;
}

node* mergeTwoSortedList(node* list1, node* list2)
{
    node* head = NULL;
    node* tail = NULL;

    if (list1->data < list2->data)
    {
        head = list1;
        tail = head;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        tail = head;
        list2 = list2->next;
    }

    while((list1 != NULL) && (list2 != NULL))
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
        } 
        else
        { 
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }
    }

    if (list1 != NULL)
        tail->next = list1;
    else if (list2 != NULL)
        tail->next = list2;

    return head;
}
