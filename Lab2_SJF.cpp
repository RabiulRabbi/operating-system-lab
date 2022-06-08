#include<bits/stdc++.h>

using namespace std;

typedef struct Process
{
    int process_no;
    int burst_time;
    int waiting_time;
}Process;

void SJF(int n, Process process[]);

bool compare(Process a, Process b);

int main()
{
    int n;
    Process process[100];

    cout << "Enter the number of process: ";
    cin >> n;

    cout << "Enter the burst time: ";
    for(int i=0; i<n; i++)
    {
        cin >> process[i].burst_time;
        process[i].process_no = i+1;
    }

    SJF(n, process);

}

void SJF(int n, Process process[])
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

    cout << "\n\nProcess \t " << "Burst Time \t" << "Waiting Time" << endl;
    for(int i=0; i<n; i++)
    {
        cout << process[i].process_no << " \t\t " << process[i].burst_time << " \t\t" << process[i].waiting_time << endl;
    }

    cout << "\nAverage waiting time: " << average_waiting_time << endl;

}

bool compare(Process a, Process b)
{
    return a.burst_time < b.burst_time;
}

