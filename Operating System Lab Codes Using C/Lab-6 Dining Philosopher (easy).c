#include<stdio.h>
#include<pthread.h>         //header file to use thread
#include<semaphore.h>           //header file to use semaphore
#include<unistd.h>          //header file to use sleep() function

sem_t chopstick[5];         //5 chopstick semaphore
void * philos(void *);          // void pointer type function and void pointer type parameter

int main()
{
    int i, n[5];         //philosopher's id
    pthread_t T[5];

    for(i=0; i<5; i++)                      //semaphore initialization as all chopstick are now free
        sem_init(&chopstick[i], 0, 1);    //chopstick -> semaphore, 0 -> shareable with other semaphore, 1 -> free semaphore

    for(i=0; i<5; i++)          //5 concurrent thread creation as all philosopher may want to eat at the same time
    {
        n[i]=i;             //philosopher's id
        pthread_create(&T[i], NULL, philos, (void *)&n[i]);    //&T[i]->address of thread, NULL->default, philos->function name, n[i]->parameter of function
    }

    for(i=0; i<5; i++)
        pthread_join(T[i], NULL);               //joining the threads with the main function
}

void * philos(void * n)
{
    int ph=*(int *)n;               //type casting void to int

    printf("Philosopher %d wants to eat\n", ph+1);

    printf("Philosopher %d tries to pick left chopstick\n", ph+1);
    sem_wait(&chopstick[ph]);                                   //(left) chopstick[i]--; chopstick[i]=0; someone is using this chopstick
    printf("Philosopher %d picks the left chopstick\n", ph+1);

    printf("Philosopher %d tries to pick the right chopstick\n", ph+1);
    sem_wait(&chopstick[(ph+1)%5]);                             //(right) chopstick[i]--; chopstick[i]=0; someone is using this chopstick
    printf("Philosopher %d picks the right chopstick\n", ph+1);

    printf("Philosopher %d begins to eat\n", ph+1);

    sleep(2);                                           //eats for 2 seconds
    printf("Philosopher %d has finished eating\n", ph+1);

    sem_post(&chopstick[(ph+1)%5]);                     //(right) chopstick[i]++; chopstick[i]=1; chopstick is free to use now
    printf("Philosopher %d leaves the right chopstick\n", ph+1);

    sem_post(&chopstick[ph]);                           //(left) chopstick[i]++; chopstick[i]=1; chopstick is free to use now
    printf("Philosopher %d leaves the left chopstick\n", ph+1);
}

