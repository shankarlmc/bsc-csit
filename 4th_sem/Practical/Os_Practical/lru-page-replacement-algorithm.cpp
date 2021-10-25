/*
	Least Recently Used Page Replacement Algorithm
*/
#include <stdio.h>

int main(){
	int frames[30], temp[30], pages[30];
	int total_pages, m, n, position, k, l, total_frames;
	int a = 0;
	int b = 0;
	int page_fault = 0;
	printf("Enter the total number of Frames: ");
	scanf("%d", &total_frames);
	for(m = 0; m < total_frames; m++) {
		frames[m] = -1;
	}
	printf("Enter the total number of Pages: ");
	scanf("%d", &total_pages);
	printf("Enter the value of refrence string:\n");
	for(m = 0; m < total_pages; m++) {
		printf("Value No [%d]:\t", m+1);
		scanf("%d", &pages[m]);
	}
	for(n = 0; n < total_pages; n++) {
		a = 0, b = 0;
		for(m = 0; m < total_frames; m++) {
			if(frames[m] == pages[n]) {
				a = 1;
				b = 1;
				break;
			}
		}
		if(a == 0) {
			for(m = 0; m < total_frames; m++) {
				if(frames[m] == -1) {
					frames[m] = pages[n];
					b = 1;
					break;
				}
			}
		}
		if(b == 0) {
			for(m = 0; m < total_frames; m++) {
				temp[m] = 0;
			}
			for(k = n - 1, l = 1; l < total_frames - 1; l++, k--) {
				for(m = 0; m < total_frames; m++) {
					if(frames[m] == pages[k]) {
						temp[m] = 1;
					}
				}
			}
			for(m = 0; m < total_frames; m++) {
				if(temp[m] == 0) {
					position = m;
				}
			}
			frames[position] = pages[n];
			page_fault++;
		}
	}
	printf("---------------------------------\n");
	printf("Page faults: %d", page_fault);
	return 0;
}
