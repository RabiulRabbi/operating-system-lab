#include<bits/stdc++.h>

using namespace std;

typedef struct Process
{
    int id;
    int burst_time;
    int priority;
    int waiting_time;
}Process;

void Priority(int n, Process process[]);

bool compare(Process a, Process b);

int main()
{
    int n;
    cout << "Enter the number of process: ";
    cin >> n;
    Process process[n];

    cout << "Enter the burst time of the process: ";

    int burst_time;
    int priority;
    int waiting_time;
    for(int i=0; i<n; i++)
    {
        cin >> process[i].burst_time;
        process[i].id = i+1;
    }

    cout << "Enter the priority of the process: ";
    for(int i=0; i<n; i++)
    {
        cin >> process[i].priority;
    }

    Priority(n, process);

    return 0;
}

void Priority(int n, Process process[])
{
    sort(process, process+n, compare);

    int total_waiting_time = 0;
    process[0].waiting_time = 0;
    for(int i=1; i<n; i++)
    {
        process[i].waiting_time = process[i-1].burst_time + process[i-1].waiting_time;
        total_waiting_time += process[i].waiting_time;
    }

    double average_waiting_time = (double)total_waiting_time / n;

    cout << "\nProcess \t" << "Burst Time \t" << "Priority \t" << "Waiting Time \n";
    for(int i=0; i<n; i++)
    {
        cout << process[i].id << "\t\t" << process[i].burst_time << "\t\t" << process[i].priority << "\t\t" << process[i].waiting_time << " \n";
    }
    cout << "\nTotal waiting time: " << total_waiting_time;
    cout << "\nAverage waiting time: " << average_waiting_time << "\n\n";
}

bool compare(Process a, Process b)
{
    return a.priority < b.priority;
}
