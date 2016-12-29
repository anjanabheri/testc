
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "../include.h"

int i = 4;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* Thread1(void* arg)
{
    printf("Thread1 called \n");

    pthread_mutex_lock(&mutex);
    printf("Thread1 mutex taken\n");
    if (i != 10)
    {
        printf("Thread1 cond wait\n");
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Thread1 signalled and about to unlock\n");
    pthread_mutex_unlock(&mutex);
    printf("Thread1 unlocked\n");
    printf("Thread1 finished, i: %d \n", i);
    pthread_exit(&i);
}

void* Thread2(void* arg)
{
    printf("Thread2 called \n");
    pthread_mutex_lock(&mutex);
    printf("Thread2 mutex taken\n");
    i = 10;
    printf("Thread2 about to signal\n");
    pthread_cond_signal(&cond);
    printf("Thread2 about to unlock\n");
    sleep(2);
    pthread_mutex_unlock(&mutex);
    printf("Thread2 unlocked\n");
    sleep(2);

    printf("Thread2 finished \n");
}

int main()
{
    pthread_t t1;
    pthread_t t2;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, Thread1, NULL);
    sleep(2);
    pthread_create(&t2, NULL, Thread2, NULL);

    int* j;

    pthread_join(t1, (void**)&j);
    pthread_join(t2, NULL);

    printf("j: %d \n", *j);

    return 0;
}
