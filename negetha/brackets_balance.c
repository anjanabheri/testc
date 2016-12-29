#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct _node
{
    struct _node *next;
    char data;
} node;

node *top = NULL;

void push(char input)
{
    node * new = malloc(sizeof(node));
    new->next = top;
    new->data = input;
    top = new;
}

char pop()
{
    node* temp = top;
    top = top->next;
    char c = temp->data;
    free (temp);
    return c;
}

void empty()
{
    node *temp = top;
    while (top != NULL)
    {
        temp = top;
        top = top->next;
        free (temp);
    }
}


bool is_balanced(char expression[])
{
    int i = 0;

    empty();

    for (i = 0; i < strlen(expression); i ++)
    {
        if ((expression[i] == '{') || (expression[i] == '[') || (expression[i] == '('))
            push(expression[i]);
        else
        {
            if (top == NULL)
                return 0;
            char c = pop();
            if ((expression[i] == '}') && (c == '{'))
                continue;
            else if ((expression[i] == ']') && (c == '['))
                continue;
            else if ((expression[i] == ')') && (c == '('))
                continue;
            else
            {
                empty();
                return 0;
            }
        }
    }

    if (top == NULL)
        return 1;
    else
    {
        empty();
        return 0;
    }
}

int main(){
    int t;
    int a0;

    scanf("%d",&t);

    for(a0 = 0; a0 < t; a0++){
        char* expression = (char *)malloc(512000 * sizeof(char));
        scanf("%s",expression);
         bool answer = is_balanced(expression);
         if(answer)
          printf("YES\n");
         else
          printf("NO\n");
    }
    return 0;
}

