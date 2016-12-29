
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned int jitter (unsigned int temp_time)
{ 
  unsigned int jittered_time;
  unsigned int rand_val;
  time_t t;

  srand(time(&t));

  unsigned int temp_rand = rand()%RAND_MAX;
  printf ("temp_rand: %d \n", temp_rand);
  printf ("rand: %d \n", rand());

  rand_val = 75 + (unsigned int)(25.0 * temp_rand);

  printf ("rand_val: %d \n", rand_val);

  jittered_time = (temp_time * rand_val / 100);

  return (jittered_time > 1 ? jittered_time : 1);
}


int main(int argc, char *argv[])
{
    unsigned int i = jitter(atoi(argv[1]));

    printf ("Jitter for %s sec is: %d \n", argv[1], i);
    return 0;
}
