#include<bits/stdc++.h>
using namespace std;

struct Process{
    char process_name[100];
    int burst_time;
    int priority;
};

bool p_sort(Process a, Process b){
   return a.priority < b.priority;
}

int main(){
Process process[100];
int waiting_t[100];
int t_waiting = 0;
int n,i;
cout<<"Enter the number of process: ";
cin>>n;
cout<<"Enter the process name,burst time and priority: "<<endl;

for(i=0;i<n;i++){
    cin>>process[i].process_name;
    cin>>process[i].burst_time;
    cin>>process[i].priority;
}
sort(process,process+n, p_sort);

waiting_t[0] = 0;
for(i=1; i<n; i++){
    waiting_t[i] = waiting_t[i-1]+process[i-1].burst_time;
}
for(i=0; i<n;i++){
    t_waiting = t_waiting+waiting_t[i];
}
cout<<endl;
//cout<<"Process and waiting time: "<<endl;
cout<<"Process_Name   Waiting_Time"<<endl;
for(i=0; i<n;i++){

    cout<<process[i].process_name<<"                  "<<waiting_t[i]<<endl;
}
cout<<endl;
cout<<"Average waiting time: "<<(double)t_waiting/n<<endl;
return 0;

}
