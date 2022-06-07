#include<stdio.h>
void FCFS(int n, int burst_time[], int waiting_time[]);
int main()
{
    int n;
    int burst_time[100], waiting_time[100];
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the burst times: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &burst_time[i]);
    }
    FCFS(n, burst_time, waiting_time);
    return 0;
}

void FCFS(int n, int burst_time[], int waiting_time[])
{
    int total_waiting_time = 0;
    waiting_time[0] = 0;
    for(int i=1; i<n; i++)
    {
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
        total_waiting_time += waiting_time[i];
    }
    double average_waiting_time = (double)total_waiting_time / n;
    printf("\n\nProcess \t Burst Time \t Waiting Time \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t\t %d \t\t %d \n", i+1, burst_time[i], waiting_time[i]);
    }
    printf("\nAverage waiting time: %lf\n", average_waiting_time);
}

