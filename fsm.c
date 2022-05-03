
#include "include.h"
#include "assert.h"

typedef enum 
{
    s_idle,
    s_connect,
    s_establish
} e_states;

typedef enum
{
    e_start,
    e_ack_received,
    e_close_received,
    e_admin_down,
    e_interrupt
} e_events;

#define num_states 3
#define num_events 5

typedef int (*event_handler)(int peer, int state, int event);

typedef struct
{
    event_handler handler;
}fsm_event_s;

int receive_start(int peer, int state, int event)
{
    printf("started \n");
}

fsm_event_s fsm[num_states][num_events] = 
{
    //idle
    {receive_start, 0, 0, 0, 0},
    //connect
    {},
    //establish
    {}
};

int main()
{
    fsm[s_idle][e_start].handler(0,0,1);

    return 0;
}

