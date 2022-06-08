#include<bits/stdc++.h>

using namespace std;

typedef struct Process
{
    int id;
    int burst_time;
    int waiting_time;
}Process;

void FCFS(int n, Process process[]);

int main()
{
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    Process process[n];
    cout << "Enter the burst time of the process: ";
    for(int i=0; i<n; i++)
    {
        cin >> process[i].burst_time;
        process[i].id = i+1;
    }

    FCFS(n, process);

    return 0;
}

void FCFS(int n, Process process[])
{
    int total_waiting_time = 0;
    process[0].waiting_time = 0;

    for(int i=1; i<n; i++)
    {
        process[i].waiting_time = process[i-1].burst_time + process[i-1].waiting_time;
        total_waiting_time += process[i].waiting_time;
    }

    double average_waiting_time = (double)total_waiting_time / n;

    cout << "\nProcess \t" << "Burst Time \t" << "Waiting Time \n";
    for(int i=0; i<n; i++)
    {
        cout << process[i].id << "\t\t" << process[i].burst_time << "\t\t" << process[i].waiting_time << " \n";
    }
    cout << "\nTotal waiting time: " << total_waiting_time;
    cout << "\nAverage waiting time: " << average_waiting_time << "\n\n";
}
