Fifo: int l, s[50], frame[10], n, avail, count = 0, i, j, pos=0;
    printf("Enter the length of the string: ");
    scanf("%d",&l);
    printf("Enter the string: ");
    for(i=0; i<l; i++)
        scanf("%d",&s[i]);
    printf("Enter the number of frames: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        frame[i]= -1;  
    printf("\nString\t\t Page Frames\n");
    for(i=0; i<l; i++) {
        printf("%d\t\t",s[i]);
        avail = 0;     
        for(j=0; j<n; j++)  {
            if(frame[j] == s[i])   {
                avail = 1;        
                break;
            }
        }
        if(avail == 0)   {
            frame[pos] = s[i];      
            pos = (pos+1) % n;
            count++;           
            for(j=0; j<n; j++){
                if(frame[j] != -1)
                    printf("%d\t",frame[j]);
            }
        }
        printf("\n");
    }
    printf("\nPage Fault is = %d\n", count);
    return 0;
}
Opt: if(avail == 0) {
            if(full < n) {
                frame[pos] = s[i];      
                pos++;                     
                full++;                 
            }else{
           pos = optimal(s, frame, l, n, i+1);     
                frame[pos] = s[i];                                  
               }
            count++;              
            for(j=0; j<n; j++){
                if(frame[j] != -1)    
                    printf("%d\t",frame[j]);
            }
        }
int optimal(int s[], int frame[], int l, int n, int idx){
    int ans = 0, farthest = idx, i, j; 
    for(i=0; i<n; i++){
        for(j=idx; j<l; j++){
            if(frame[i] == s[j]) {
                if(j > farthest){
                    farthest = j;           
                    ans = i;            
                }
               break;            
            }
        }
        if(j == l)                     
            return i;                    
    }
    return ans;          
}
Lru: int LRU(int s[], int frame[], int l, int n, int idx){
    int ans = 0, oldest = idx, i, j;  
    for(i=0; i<n; i++){
        for(j=idx; j>=0; j--){
            if(frame[i] == s[j]) {
                if(j < oldest) {
                    oldest = j;      
                    ans = i;     
                }
               break;    
            }
        }
    }
    return ans; 
}
First-fit:  int b_no,b_size[10],p_no,
p_size[10],i,j,alloc[10],flags[10];
    printf("Enter the number of blocks: ");
    scanf("%d",&b_no);
    printf("Enter the blocks sizes: \n");
    for(i=0; i<b_no; i++){
        scanf("%d",&b_size[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d",&p_no);
    printf("Enter the processes sizes: \n");
    for(i=0; i<p_no; i++){
        scanf("%d",&p_size[i]);
    }
    for(i=0; i<b_no; i++){
        flags[i] = 0;
        alloc[i] = -1;
    }
    for(i = 0; i<p_no; i++){
        for(j = 0; j < b_no; j++){
 if(flags[j] == 0 && b_size[j] >= p_size[i]){
                alloc[j] = i;
                flags[j] = 1;
                break;
            }
        }
    }
    printf("\nBlock no\tBlock size\tProcess no\tProc-_size\tUnused");
    for(i = 0; i<b_no; i++){
    printf("\n%d\t\t%d\t\t",i+1, b_size[i]);
        if(flags[i] == 1){
    printf("%d\t\t%d\t\t%d",alloc[i]+1, p_size[alloc[i]], b_size[i] - p_size[alloc[i]]);
        }else{
            printf("---\t\t---\t\t%d",b_size[i]);
        }
    }
    printf("\n");
}
Worst-fit:     for(i = 0; i < p_no; i++){
        for(j = 0; j < b_no; j++){
            if(flags[j] == 0){
                temp = b_size[j] - p_size[i];
                if(temp >=0 && temp > higher){
                    higher = temp;
                    id = j;
                }
            }
        }
        alloc[id] = i;
        flags[id] = 1;
        higher = -9999;
        id = 9;
    }
Best-fit:     for(i = 0; i < p_no; i++){
        for(j = 0; j < b_no; j++){
            if(flags[j] == 0){
                temp = b_size[j] - p_size[i];
                if(temp >=0 && temp<lowest){
                    lowest = temp;
                    id = j;
                }
            }
        }
        alloc[id] = i;
        flags[id] = 1;
        lowest = 9999;
        id = 9;
    }
Fcfs:  int n, i;
 int burst_time[100], waiting_time[100];
    printf("Number of process: ");
    scanf("%d", &n);
    printf("Enter burst time: ");
    for(i = 0; i < n; i++){
        scanf("%d", &burst_time[i]);
    }
    FCFS(n,burst_time,waiting_time);
    return 0;
}
void FCFS(int n, int burst_time[], int waiting_time[]){
    waiting_time[0] = 0;
    int total_waiting_time = 0;
    for(int i = 1; i < n; i++){
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
  total_waiting_time += waiting_time[i];
    }
   double avg_waiting_time = (double)total_waiting_time/n;
printf("\nProcess\t\tBurst Time\tWaiting Time\n");
    for(int i = 0; i<n; i++){
        printf("\n%d\t\t%d\t\t%d",i+1,burst_time[i],waiting_time[i]);
    }
    printf("\n\nAverage waiting Time: %1f\n",avg_waiting_time);
}
Sjf: #include<bits/stdc++.h>
using namespace std;
typedef struct Process{
    int process_no;
    int burst_time;
    int waiting_time;
} Process;
void SJF(int n, Process process[]);
bool compare(Process a, Process b);
int main(){
    int n;
    Process process[100];
cout << "Enter the number of process: ";
    cin >> n;
    cout << "Enter the burst time: ";
    for(int i=0; i<n; i++){
        cin >> process[i].burst_time;
        process[i].process_no = i+1;  }
    SJF(n, process);
}
void SJF(int n, Process process[]){
    sort(process, process+n, compare);
    int total_waiting_time = 0;
    process[0].waiting_time = 0;
    for(int i=1; i<n; i++){
process[i].waiting_time = process[i-1].burst_time + process[i-1].waiting_time;
        total_waiting_time += process[i].waiting_time;   }
    double average_waiting_time = (double)total_waiting_time / n;
    cout << "\n\nProcess \t " << "Burst Time \t" << "Waiting Time" << endl;
    for(int i=0; i<n; i++){
        cout << process[i].process_no << " \t\t " << process[i].burst_time << " \t\t\t" << process[i].waiting_time << endl;
    }
    cout << "\nAverage waiting time: " << average_waiting_time << endl;
}
bool compare(Process a, Process b){
    return a.burst_time < b.burst_time;
}
Priority: #include<bits/stdc++.h>
using namespace std;
struct Process{
    char process_name[100];
    int burst_time;
    int priority;};
bool p_sort(Process a, Process b){
   return a.priority < b.priority;}
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
    cin>>process[i].priority;}
sort(process,process+n, p_sort);
waiting_t[0] = 0;
for(i=1; i<n; i++){
    waiting_t[i] = waiting_t[i-1]+process[i-1].burst_time;}
for(i=0; i<n;i++){
    t_waiting = t_waiting+waiting_t[i];}
cout<<endl;
cout<<"Process_Name   Waiting_Time"<<endl;
for(i=0; i<n;i++){
    cout<<process[i].process_name<<"                  "<<waiting_t[i]<<endl;}
cout<<endl;
cout<<"Average waiting time: "<<(double)t_waiting/n<<endl;
return 0; }
RR: typedef struct Process{
    int process_no;
    int burst_time;
    int waiting_time;
} Process;
void RR(int n, Process process[], int quantum_time);
int main(){
    int n;
cout << "Enter the number of process: ";
    cin >> n;
    Process process[n+1];
    cout << "Enter the burst burst time of the process: ";
    for(int i=0; i<n; i++){
        cin >> process[i].burst_time;
        process[i].process_no = i+1;  }
    int quantum_time;
    cout << "Enter the time quantum: ";
    cin >> quantum_time;
    RR(n, process, quantum_time);
    return 0;}
void RR(int n, Process process[], int quantum_time){
    int remaining_burst_time[n];
    for(int i=0; i<n; i++){
        remaining_burst_time[i] = process[i].burst_time;    }
    int start_time, finish_time = 0;
    bool done = false;
    while(!done){
        done = true;
        for(int i=0; i<n; i++){
            start_time = finish_time;
            if(remaining_burst_time[i] > 0){
                done = false;
if(remaining_burst_time[i] > quantum_time){
        finish_time += quantum_time;
                    remaining_burst_time[i] -= quantum_time;
                }else{
 finish_time += remaining_burst_time[i];
                    process[i].waiting_time = finish_time - process[i].burst_time;
                    remaining_burst_time[i] = 0;
                } }}}
    int total_waiting_time = 0;
    for(int i=0; i<n; i++){
        total_waiting_time += process[i].waiting_time;  }
    double average_waiting_time = (double)total_waiting_time / n;
    cout << "\n\nProcess \t " << "Burst Time \t" << "Waiting Time" << endl;
    for(int i=0; i<n; i++){
        cout << process[i].process_no << " \t\t " << process[i].burst_time << " \t\t" << process[i].waiting_time << endl;    }
    cout << "\nAverage waiting time: " << average_waiting_time << endl; }
Bankers:  int n,m,i,j,k,alloc[20][20],
max[20][20],avail[20],process[20], safe[20],count,ok,store[20];
    printf("Enter the process number: ");
    scanf("%d",&n);
    printf("Enter the resource number: ");
    scanf("%d",&m);
    printf("Enter the allocations matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&alloc[i][j]);
        } }
    printf("Enter the max matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &max[i][j]); } }
    int need[n][m];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }}
    printf("Need matrix is: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", need[i][j]); }
        printf("\n");}
   printf("Enter the available matrix: \n");
    for(i = 0; i < m; i++){
        scanf("%d",&avail[i]); }
    for(i = 0; i < n; i++){
            process[i] = i+1;
            safe[i] = 0; }
    count = 0;
    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
           if(safe[i] == 0){
                 ok = 1;
                 for(j = 0; j < m; j++){
                    if(need[i][j] > avail[j]){
                        ok = 0;
                        break;
                    }  }
                 if(ok == 1){
                    store[count] = process[i];
                    safe[i] = 1;
                    count++;
                    for(j = 0; j < m; j ++){
                        avail[j] += alloc[i][j];
                    }   }}    }    }
    if(count == n){
        printf("Safe sequence is: ");
        for(i = 0; i < n; i++){
            printf("%d ",store[i]);
        }
    }else{
        printf("Unsafe sequence!!!!");
    }}
