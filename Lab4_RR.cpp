#include<bits/stdc++.h>

using namespace std;

typedef struct Process
{
    int process_no;
    int burst_time;
    int waiting_time
    ;
} Process;

void RR(int n, Process process[], int quantum_time);

int main()
{

    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    Process process[n+1];
    cout << "Enter the burst burst time of the process: ";
    for(int i=0; i<n; i++)
    {
        cin >> process[i].burst_time;
        process[i].process_no = i+1;
    }

    int quantum_time;
    cout << "Enter the time quantum: ";
    cin >> quantum_time;
    RR(n, process, quantum_time);

    return 0;
}

void RR(int n, Process process[], int quantum_time)
{
    int remaining_burst_time[n];
    for(int i=0; i<n; i++)
    {
        remaining_burst_time[i] = process[i].burst_time;
    }

    int start_time, finish_time = 0;
    bool done = false;
    cout << "\n\nProcess \t" << "Remaining Burst Time \t" << "TIme Slot (Start) \t" << "Time Slot (END) \n";

    while(!done)
    {
        done = true;

        for(int i=0; i<n; i++)
        {
            start_time = finish_time;

            if(remaining_burst_time[i] > 0)
            {
                done = false;
                if(remaining_burst_time[i] > quantum_time)
                {
                    finish_time += quantum_time;
                    remaining_burst_time[i] -= quantum_time;
                }
                else
                {
                    finish_time += remaining_burst_time[i];
                    process[i].waiting_time = finish_time - process[i].burst_time;
                    remaining_burst_time[i] = 0;
                }
                cout << process[i].process_no << "\t\t" << remaining_burst_time[i] << "\t\t\t" << start_time << "\t\t\t" << finish_time << "\n";

            }
        }
    }

    int total_waiting_time = 0;
    for(int i=0; i<n; i++)
    {
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
