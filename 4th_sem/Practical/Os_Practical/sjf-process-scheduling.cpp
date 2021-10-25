#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <limits.h>

// Function to calculate turn around time
int turnaroundtime( int proc[], int n, int burst_time[], int wait_time[], int tat[]) {
   // calculating turnaround time by adding
   // burst_time[i] + wait_time[i]
   int i;
   for ( i = 0; i < n ; i++)
   tat[i] = burst_time[i] + wait_time[i];
   return 0;
}

// Function to calculate waiting time
int waitingtime(int proc[], int n, int burst_time[], int arrival_time[], int wait_time[]) {
	int rt[n];
	for (int i = 0; i < n ; i++ )
	rt[i] = burst_time[i];
	
	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	
	bool check = false;
   
	while (complete != n) {
		for (int j = 0; j < n; j++) {
			if ((arrival_time[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
			    minm = rt[j];
			    shortest = j;
			    check = true;
			}
		}
		if (check == false) {
		 t++;
		 continue;
		}
		// decrementing the remaining time
		rt[shortest]--;
		minm = rt[shortest];
		if (minm == 0){
			minm = INT_MAX;
			// If a process gets completely executed
			if (rt[shortest] == 0) {
				complete++;
				check = false;
				finish_time = t + 1;
				// Calculate waiting time
				wait_time[shortest] = finish_time - burst_time[shortest] - arrival_time[shortest];
				if (wait_time[shortest] < 0){
					wait_time[shortest] = 0;
				} 
			}
			// Increment time
			t++;
		}
	}
	return 0;
}

//Function to calculate average time
int avgtime( int proc[], int n, int burst_time[], int arrival_time[]) {
	
   int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   
   int i;
   //Function to find waiting time of all processes
   waitingtime(proc, n, burst_time, arrival_time, wait_time);
   //Function to find turn around time for all processes
   turnaroundtime(proc, n, burst_time, wait_time, tat);
   
   //Display processes along with all details
   printf("Processes  Burst Time  Arrival Time   Waiting Time   Turnaround Time \n");
   printf("-------------------------------------------------------\n");
   for (i=0; i<n; i++) {
      total_wt = total_wt + wait_time[i];
      total_tat = total_tat + tat[i];
      printf("  %d\t\t%d\t\t%d \t\t%d \t%d\n", proc[i], burst_time[i], arrival_time[i], wait_time[i], tat[i]);
   }
   printf("\n-------------------------------------------------------\n");
   printf("Average waiting time = %.2f\n", (float)total_wt / (float)n);
   printf("Average turn around time = %.2f\n", (float)total_tat / (float)n);
   return 0;
}
// main function
int main() {
	//process id's
	int process[] = { 1, 2, 3, 4};
	// process arrival time
	int arrival_time[] = {1, 2, 3, 4};
	int n = sizeof process / sizeof process[0];
	//Burst time of all processes
	int burst_time[] = {21, 3, 6, 2};
	avgtime(process, n, burst_time, arrival_time);
	return 0;
}

