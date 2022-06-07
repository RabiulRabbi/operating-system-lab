#include<bits/stdc++.h>
using namespace std;
void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum){
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++){
		rem_bt[i] = bt[i];
    }
	int t = 0; // Current time
	while (1){
		bool done = true;
		for (int i = 0 ; i < n; i++){
			if (rem_bt[i] > 0)	{
				done = false; // There is a pending process

				if (rem_bt[i] > quantum){
					t += quantum;
					rem_bt[i] -= quantum;
				}
				else{
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
		if (done == true)
		break;
	}
}
void findavgTime(int processes[], int n, int bt[],int quantum){
	int wt[n], total_wt = 0;

	findWaitingTime(processes, n, bt, wt, quantum);

	cout << "Process\t "<< " \tBurst Time " << " Waiting Time\n";

	for (int i=0; i<n; i++){
		total_wt = total_wt + wt[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t\t "
			<< wt[i] <<"\t\t " <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
}
int main(){
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];
	int burst_time[] = {10, 5, 8};
	int quantum = 2;
	findavgTime(processes, n, burst_time, quantum);
	return 0;
}
