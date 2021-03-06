#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NITER 1000000

sem_t sem_name;
pthread_mutex_t lock;
int count = 0;

void * ThreadAdd(void * a)
{
    int i, tmp;

    //Just to test gprof
    sleep(3);

    sem_wait(&sem_name);

    int value; 
    sem_getvalue(&sem_name, &value); 
    printf("The value of the semaphors is %d\n", value);

    //pthread_mutex_lock(&lock);
    for(i = 0; i < NITER; i++)
    {
        tmp = count;      /* copy the global count locally */
        tmp = tmp+1;      /* increment the local copy */
        count = tmp;      /* store the local value into the global count */ 
    }
    //pthread_mutex_unlock(&lock);
    sem_post(&sem_name);
}

void createThreads()
{
    pthread_t tid1, tid2;

    //Just to test gprof
    sleep(2);

    sem_init(&sem_name, 0, 1);

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return;
    }

    if(pthread_create(&tid1, NULL, ThreadAdd, NULL))
    {
      printf("\n ERROR creating thread 1");
      exit(1);
    }

    if(pthread_create(&tid2, NULL, ThreadAdd, NULL))
    {
      printf("\n ERROR creating thread 2");
      exit(1);
    }

    if(pthread_join(tid1, NULL))	/* wait for the thread 1 to finish */
    {
      printf("\n ERROR joining thread");
      exit(1);
    }

    if(pthread_join(tid2, NULL))        /* wait for the thread 2 to finish */
    {
      printf("\n ERROR joining thread");
      exit(1);
    }

    if (count < 2 * NITER) 
        printf("\n BOOM! count is [%d], should be %d\n", count, 2*NITER);
    else
        printf("\n OK! count is [%d]\n", count);
  
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);

    return;
}

int main(int argc, char * argv[])
{
    createThreads();
    return 0;
}


