#include "include.h"

typedef struct Queue {
    int *enqueue_stack;
    int *dequeue_stack;
    int  etop;
    int  dtop;
} Queue;

#define ENQUEUE (1)
#define DEQUEUE (2)
#define PRINT   (3)

void enqueue(Queue *queue, int data) {
    queue->enqueue_stack[++queue->etop] = data;
}

static void get_data(Queue *queue) {
    while(queue->etop >= 0) 
        queue->dequeue_stack[++queue->dtop] = queue->enqueue_stack[queue->etop--];
}

int dequeue(Queue *queue) {
    if(queue->dtop < 0) 
        get_data(queue);

    return queue->dequeue_stack[queue->dtop--];
}

void print(Queue *queue) {
    if(queue->dtop < 0)
        get_data(queue);

    printf("%d\n", queue->dequeue_stack[queue->dtop]);
}

void init_queue(Queue **queue, int stack_size) {
    *queue = (Queue *)malloc(sizeof(Queue));
    
    (*queue)->enqueue_stack = malloc(sizeof(int) * stack_size);
    (*queue)->dequeue_stack = malloc(sizeof(int) * stack_size);
    (*queue)->etop          = -1;
    (*queue)->dtop          = -1;
}

void free_queue(Queue *queue) {
    if(queue) {
        free(queue->enqueue_stack);
        free(queue->dequeue_stack);
        free(queue);
    }
}

int main() {
    int n;
    int i;
    scanf("%d", &n);

    Queue *queue;
    init_queue(&queue, n);

    for(i=0; i<n; i++) {
        int op;
        scanf("%d", &op);

        int data;
        switch(op) {
            case ENQUEUE:
                scanf("%d", &data);
                enqueue(queue, data);
                break;

            case DEQUEUE:
                dequeue(queue);
                break;

            case PRINT:
                print(queue);
                break;
        }
    } /* for */

    free_queue(queue);

    return 0;
}


