/*
	FIFO page replacement program
*/
#include<stdio.h>

int main () {
	int i, j, pages, refrence_string[50], frames;
	int no, k, avail, page_faults = 0;
	printf("Enter the total number of pages: ");
	scanf("%d", &pages);
	printf("Enter the Values of Refrence String: \n");
	for (i = 0; i < pages; i++){
		printf("Value No. [%d]: ", i);
		scanf("%d: ", &refrence_string[i]);
	}
	printf("Enter the total number of frames: ");
	scanf("%d", &frames);
	int temp[frames];
	for (i = 0; i < frames; i++){
		temp[i] = -1;
	}

	for (i = 1; i < pages; i++) {
		avail = 0;
		for (j = 0; j < frames; j++){
			if(refrence_string[i] == temp[j]) {
				avail++;
				page_faults--;
			}
		}
		page_faults++;
        if((page_faults <= frames) && (avail == 0))
        {
              temp[i] = refrence_string[i];
        }   
        else if(avail == 0)
        {
              temp[(page_faults - 1) % frames] = refrence_string[i];
        }

	}
	printf("--------------------------------\n");
	printf("Page fault is : %d", page_faults);
	return 0;
}
