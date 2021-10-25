/*
first come first serve process scheduling algorithm
Example:
	processes Burst
		1		5
		2		8
		3		12
*/
#include <stdio.h>

// Function to calculate waiting time
int waitingtime(int proc[], int n, int burst_time[], int wait_time[]) {
   // waiting time for first process is 0
   wait_time[0] = 0;
   // calculating waiting time
   for (int i = 1; i < n ; i++ )
   wait_time[i] = burst_time[i-1] + wait_time[i-1] ;
   return 0;
}

// Function to calculate turn around time
int turnaroundtime( int proc[], int n, int burst_time[], int wait_time[], int tat[]) {
   // calculating turnaround time by adding
   // burst_time[i] + wait_time[i]
   int i;
   for ( i = 0; i < n ; i++)
   tat[i] = burst_time[i] + wait_time[i];
   return 0;
}
//Function to calculate average time
int avgtime( int proc[], int n, int burst_time[]) {
	
   int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   int i;
   //Function to find waiting time of all processes
   waitingtime(proc, n, burst_time, wait_time);
   //Function to find turn around time for all processes
   turnaroundtime(proc, n, burst_time, wait_time, tat);
   //Display processes along with all details
   printf("Processes  Burst Time   Waiting Time   Turnaround Time \n");
   printf("-------------------------------------------------------\n");
   for ( i=0; i<n; i++) {
      total_wt = total_wt + wait_time[i];
      total_tat = total_tat + tat[i];
      printf("  %d\t\t%d\t\t%d \t\t%d\n", i+1, burst_time[i], wait_time[i], tat[i]);
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
   int n = sizeof process / sizeof process[0];
   //Burst time of all processes
   int burst_time[] = {21, 3, 6, 2};
   avgtime(process, n, burst_time);
   return 0;
}


