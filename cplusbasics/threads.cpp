
#include "../include.h"
#include <sys/time.h>
#include <sys/resource.h>

void* thread_entry(void*)
{
    //while(1)
    {
        system("date");
        cout << "thread_entry 1: priority: " << getpriority(PRIO_PROCESS, 0) << endl; 
        cout << "scheduler param: " << sched_getscheduler(getpid()) << endl;
    }
}

void* thread_entry_2(void*)
{
    //while(1)
    {
        system("date");
        cout << "thread_entry 2: priority: " << getpriority(PRIO_PROCESS, 0) << endl; 
    }
}

int main()
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, thread_entry, NULL);
    pthread_create(&t2, NULL, thread_entry_2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
