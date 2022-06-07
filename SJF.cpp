#include<bits/stdc++.h>
using namespace std;

struct Process{
    int burst;
    char process_name[100];
};
bool p_sort(Process a, Process b)
{
    return a.burst<b.burst;
}

int main()
{
    Process process[100];
    int completion_t[100], waiting_t[100], t_waiting=0;
    int n, i;
    cout<<"Enter number of process: ";
    cin>>n;
    cout<<endl;

    cout<<"Enter process name and burst time"<<endl;

    for(i=0; i<n; i++){
            cout<<"Process Name and Burst Time: ";
            cin>>process[i].process_name;
            cin>>process[i].burst;
    }

    sort(process, process+n, p_sort);


    //Waiting time calculation
    waiting_t[0] = 0;

    for(i=1; i<n; i++)
    {
        waiting_t[i] = waiting_t[i-1]+process[i-1].burst;
    }

    for(i=0; i<n; i++)
    {
        t_waiting = t_waiting+waiting_t[i];
    }

    cout<<endl;
    cout<<"Process and Waiting Time"<<endl;

    for(i=0; i<n; i++)
    {
        cout<<process[i].process_name<<" "<<waiting_t[i]<<endl;
    }

    cout<<endl;
    cout<<"Average waiting time: "<<(double)t_waiting/n<<endl;


    return 0;
}
