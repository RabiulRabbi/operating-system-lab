#include<stdio.h>

int main()
{
    int bt[20],wt[20],tat[20],at[20],pr[20],ct[20],p[20],i,j,n,temp,next,time,min;
    float wtavg,tatavg;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("Enter the arrival time of process: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&at[i]);
    }
    printf("Enter the burst of process: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
        p[i] = i+1;
    }
    printf("Enter the priority of process: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&pr[i]);
    }
    for(i=0; i<n; i++)              //Bubble sort
    {
        for(j=0; j<n-1; j++)
        {
            if(at[j] > at[j+1] || (at[j]==at[j+1] && pr[j]>pr[j+1]))        //smaller arrival time are in front
            {                                                              //and when arrival time is same, small priority is in front
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;         //swap arrival time

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;         //swap burst time

                temp = pr[j];
                pr[j] = pr[j+1];
                pr[j+1] = temp;        //swap priority

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;          //swap process id
            }
        }
    }

    next=0;                 //next process to allocate
    time = at[0];               //current time
    for(i=0; i<n; i++)
    {
        time += bt[i];              //time increases as burst time is given
        next++;                         //work with next process
        min = pr[next];                        //suppose next process has the minimum burst time
        for(j=next; j<n; j++)
        {
            if(at[j] <= time && pr[j] < min)            //if process arrived in current time and has smaller burst time than minimum
            {                                          //bring that process in the next position
                temp = at[next];
                at[next] = at[j];
                at[j] = temp;               //swap arrival time

                temp = bt[next];
                bt[next] = bt[j];
                bt[j] = temp;               //swap burst time

                temp = pr[next];
                pr[next] = pr[j];
                pr[j] = temp;               //swap priority

                temp = p[next];
                p[next] = p[j];
                p[j] = temp;                //swap process id
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    ct[0] = bt[0];                  //completion time of first process is its burst time
    tatavg = bt[0];
    for(i=1; i<n; i++)
    {
        wt[i] = ct[i-1] - at[i];                //waiting time is completion time of the previous process minus its arrival time
        tat[i] = wt[i] + bt[i];                     //turnaround time is waiting time plus burst time
        ct[i] = ct[i-1] + bt[i];                //completion time is completion time of previous process plus its burst time
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\nProcess \t Priority \t Arrival Time \t Burst Time\t Waiting Time \t Turnaround Time");
    for(i=0; i<n; i++)
    {
        printf("\n%d \t\t %d \t\t %d \t \t %d\t\t %d \t\t %d",p[i],pr[i],at[i],bt[i],wt[i],tat[i],ct[i]);
    }
    printf("\n\nAverage waiting time = %f",wtavg/n);
    printf("\nAverage turnaround time = %f\n",tatavg/n);
}



