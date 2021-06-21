/*
sstf disk algorithm

Example: 
	Number of Location: 8
	Position Of Head: 53
	Enter the elements of dis queue: 98, 183, 122, 14,122, 124, 65, 67 
*/
#include<stdio.h>
#include<stdlib.h>

struct di {
	int num;
	int flag;
};

int main(){
	int i, j, min, loc, head, n, x, seek=0;
	struct di d[50];
	int arr[50], a[50];
	
	printf("Enter the number of location: \n");
	scanf("%d", &loc);
	printf("Enter the Position of head: \n");
	scanf("%d", &head);
	printf("Enter the elements of dis queue: \n");
	for(i=0; i<n; i++){
		scanf("%d", &d[i].num);
		d[i].flag=0;
	}
	for(i=0;i<n;i++){
		x = 0;
		min = 0;
		loc = 0;
		for(j=0;j<n;j++){
			if(d[j].flag == 0){
				if(x==0){
					arr[j] = head-d[j].num;
					if(arr[j]<0){
						arr[j] = d[j].num - head;
					}
					min = arr[j];
					loc = j;
					x++;
				} else {
					arr[j] = head - d[j].num;
					if(arr[j]<0){
						arr[j] = d[j].num - head;
					}
				}
				if(min> arr[j]){
					min = arr[j];
					loc = j;
				}
			}
		}
		d[loc].flag = 1;
		a[i] = d[loc].num - head;
		if (a[i]< 0){
			a[i] = head - d[loc].num;
		}
		head = d[loc].num;
		
	}
	// Finding the seek time	
	for(i=0; i<n;i++){
		seek = seek + a[i];	
	}
	printf("\nTotal head movement is %d", seek);
	
	return 0;
	
}
