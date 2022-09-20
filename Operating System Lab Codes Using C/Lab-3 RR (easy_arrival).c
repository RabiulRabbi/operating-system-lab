#include<stdio.h>

int main()
{
    int bt[20],wt[20],tat[20],at[20],ct[20],rt[20],p[20],tq,time,remain,i,j,done,n,temp;
    float wtavg=0,tatavg=0;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("Enter the arrival time of process: ");
    for(i=0; i<n; i++)
        scanf("%d",&at[i]);
    printf("Enter the burst of process: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
        rt[i] = bt[i];              //initially the entire burst time is remaining
        p[i] = i+1;
    }
    printf("Enter the time quantum: ");
    scanf("%d",&tq);

    for(i=0; i<n; i++)                  //Bubble sort
    {
        for(j=0; j<n-1; j++)
        {
            if(at[j] > at[j+1])                 //smaller arrival time are in front
            {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;             //swap arrival time

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;             //swap burst time

                temp = rt[j];
                rt[j] = rt[j+1];
                rt[j+1] = temp;             //swap remaining burst time

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;              //swap process id
            }
        }
    }

    printf("\nProcess \t Arrival Time \t Burst Time\t Waiting Time \t Turnaround Time");
    i = 0, time = 0, remain = n;                //current time is 0 and all processes are remaining
    while(remain != 0)
    {
        if(rt[i]<=tq && rt[i]>0)                //remaining burst time of process is less than time quantum but not less than zero
        {                                           //this process don't need full time quantum
            time += rt[i];               //only remaining burst time is given and current time increased
            rt[i] = 0;                        //this process has no remaining burst time
            done = 1;                   //this process is done now
        }
        else if(rt[i]>0)                                //remaining burst time is not less than time quantum
        {                                                   //so give full time quantum to this process
            rt[i] -= tq;        //remaining burst time decreased
            time += tq;             //current time increased
        }
        if(rt[i]==0 && done==1)     //process has no remaining burst time and has been done right now
        {
            remain--;                                   //remaining process is decreased, cause this process is finished
            wt[i] = time - bt[i] - at[i];                           //waiting time calculation from finish time
            tat[i] = time - at[i];                                          //turnaround time calculation from finish time
            printf("\n%d \t\t %d \t \t %d\t\t %d \t\t %d",p[i],at[i],bt[i],wt[i],tat[i], time);
            done = 0;                           //done is set to 0, so this process doesn't get here again
            wtavg += wt[i];
            tatavg += tat[i];
        }

        for(j=i; j<n-1; j++)                                //bringing the processes in front which arrived in current time
        {                                                  //and has remaining burst time
            if(at[j+1]<=time && rt[j+1]>0)                //also placing the current process at the end of them
            {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;             //swap arrival time

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;             //swap burst time

                temp = rt[j];
                rt[j] = rt[j+1];
                rt[j+1] = temp;             //swap remaining burst time

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;              //swap process id
            }
        }
    }

    printf("\n\nAverage waiting time = %f",wtavg/n);
    printf("\nAverage turnaround  time = %f\n",tatavg/n);
}


