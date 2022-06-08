#include<bits/stdc++.h>

using namespace std;

typedef struct Process
{
    int id;
    int burst_time;
    int waiting_time;
    int arrival_time;
} Process;

void SJF_PRE(int n, Process process[]);

bool compare(Process a, Process b);

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

    cout << "Enter the arrival time of the process: ";
    for(int i=0; i<n; i++)
    {
        cin >> process[i].arrival_time;
    }

    SJF_PRE(n, process);

    return 0;
}

void SJF_PRE(int n, Process process[])
{
    sort(process, process+n, compare);

    int remaining_burst_time[n];
    for(int i=0; i<n; i++)
    {
        remaining_burst_time[i] = process[i].burst_time;
    }

    int complete = 0, start_time, finish_time = process[0].arrival_time;
    int shortest_process = 0, minimum_burst_time = INT_MAX;
    bool check = false;

    cout << "\n\nProcess \t" << "Remaining Burst Time \t" << "TIme Slot (Start) \t" << "Time Slot (END) \n";

    while(complete != n)
    {
        start_time = finish_time;
        for(int i=0; i<n; i++)
        {
            if(process[i].arrival_time <= finish_time && remaining_burst_time[i] < minimum_burst_time && remaining_burst_time[i] > 0)
            {
                minimum_burst_time = remaining_burst_time[i];
                shortest_process = i;
                check = true;
            }
        }
        finish_time++;

        if(!check)
        {
            continue;
        }

        remaining_burst_time[shortest_process]--;

        minimum_burst_time = remaining_burst_time[shortest_process];
        if(minimum_burst_time == 0)
            minimum_burst_time = INT_MAX;



        if(remaining_burst_time[shortest_process] == 0)
        {
            complete++;
            check = false;

            process[shortest_process].waiting_time = finish_time - process[shortest_process].burst_time - process[shortest_process].arrival_time;
        }

        cout << process[shortest_process].id << "\t\t" << remaining_burst_time[shortest_process] << "\t\t\t" << start_time << "\t\t\t" << finish_time << "\n";
    }

    int total_waiting_time = 0;
    for(int i=0; i<n; i++)
    {
        total_waiting_time += process[i].waiting_time;
    }

    double average_waiting_time = (double)total_waiting_time / n;

    cout << "\n\nProcess \t " << "Arrival Time \t" << "Burst Time \t" << "Waiting Time" << endl;
    for(int i=0; i<n; i++)
    {
        cout << process[i].id << " \t\t " << process[i].arrival_time << "\t\t" << process[i].burst_time << " \t\t" << process[i].waiting_time << endl;
    }

    cout << "\nAverage waiting time: " << average_waiting_time << endl;

}

bool compare(Process a, Process b)
{
    return a.arrival_time < b.arrival_time;
}
