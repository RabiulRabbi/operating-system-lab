#include<stdio.h>

int mutex = 1, full = 0, empty = 3, in = 0, out = 0;        //mutex = 1 -> unlocked, full = 0 -> nothing full, empty = 3 -> everything empty
void producer();
void consumer();
int wait(int s);
int signal(int s);

int main()
{
    int n;
    printf("1. Producer. \n2. Consumer \n3. Exit \n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        if(n == 1)
        {
            if(mutex == 1 && empty != 0)            //mutex unlocked and buffer not full
                producer();
            else
                printf("Buffer is full...!!!\n");
        }
        else if(n == 2)
        {
            if(mutex == 1 && full != 0)             // mutex unlocked and buffer is empty
                consumer();
            else
                printf("Buffer is empty...!!!\n");
        }
        else if(n == 3)
            break;
        else
            printf("Please give valid input...!!!\n");
    }
    return 0;
}

int wait(int s)
{
    return --s;
}
int signal(int s)
{
    return ++s;
}
void producer()
{
    mutex = wait(mutex);         //mutex--; mutex = 0; mutex = locked
    full = signal(full);            //full++; full cell increased
    empty = wait(empty);        //empty--; empty cell decreased
    printf("Producer produces item -> %d\n", in+1);
    in = (in+1) % 3;           //next input position (circular)
    mutex = signal(mutex);          //mutex++; mutex = 1; mutex = unlocked
}
void consumer()
{
    mutex = wait(mutex);           //mutex--; mutex = 0; mutex = locked
    empty = signal(empty);              //empty++; empty cell increased
    full = wait(full);              //full--; full cell decreased
    printf("Consumer consumes item -> %d\n", out+1);
    out = (out+1) % 3;            //next ouput position (circular)
    mutex = signal(mutex);          //mutex++; mutex = 1; mutex = unlocked
}
