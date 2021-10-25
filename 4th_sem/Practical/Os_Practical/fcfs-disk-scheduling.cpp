/*
Example: 
	max range of disk: 199
	Size of request: 8
	The value of Request: 98, 183, 122, 14,122, 124, 65, 67 
*/
// First come first serve disk 
#include<stdio.h>
#include<stdlib.h>

int main(){
	int max, n, head, queue[50], i,j, diff, seek=0;
	printf("Enter the max range of disk:\t");
	scanf("%d", &max);
	printf("\nEnter the Size of request queue:\t");
	scanf("%d", &n);
	printf("\nEnter the value of queue:\t");
	for (i = 1; i<n; i++){
		scanf("%d", &queue[i]);
	}
	printf("Enter the Initial head position:\t");
	scanf("%d", &head);
	queue[0] = head;
	for(j=0;j<=n-1;j++){
		diff = abs(queue[j+1]-queue[j]);
		seek += diff;
		printf("Disk head moves from %d to %d with seek time %d \n", queue[j],queue[j+1],diff);
	}
	printf("\nThe total seek time is %d", seek);
	return 0;
	
}
