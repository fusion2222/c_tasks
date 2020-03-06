#include <stdio.h>
#include "utils.h"


int parition(int low_index, int high_index, int * sortlist){
	// Pivot index will be always the last element of array.
	int pivot_index = high_index;
	high_index--;

	int low_swap_flag = 0;
	int high_swap_flag = 0;

	while(1){
		while(low_index <= high_index){
			if(sortlist[low_index] > sortlist[pivot_index]){
				high_swap_flag = 1;
				break;
			}
			low_index++;
		}

		while(high_index > 0){
			if(sortlist[high_index] < sortlist[pivot_index]){
				low_swap_flag = 1;
				break;
			}
			high_index--;
		}

		if(high_index <= low_index){
			swap(&sortlist[low_index], &sortlist[pivot_index]);
			return low_index;
		}

		if(high_swap_flag && low_swap_flag){
			swap(&sortlist[low_index], &sortlist[high_index]);
			high_swap_flag = 0;
			low_swap_flag = 0;
		}

	}

}


void quicksort(int low_index, int high_index, int * sortlist){
	int sorted_index = parition(low_index, high_index, sortlist);

	if(low_index < sorted_index - 1){
		quicksort(low_index, sorted_index - 1, sortlist);
	}

	if(sorted_index + 1 < high_index){
		quicksort(sorted_index + 1, high_index, sortlist);
	}
}


int main(int argc, char const *argv[]){
	int sortlist[] = {33, 2, 6, 41, -23, -9, 0, 10};
	int sortlist_length = sizeof(sortlist) / (int)sizeof(sortlist[0]);

	display_results(sortlist, sortlist_length);

	/* 
		IMPORTANT FACT:

		Lets start with the last element as pivot element!

		In order to determine, which index (high or low) should be exchanged for pivot,
		we must take consideration, which position we decided to mark as pivot!

		In case of first position in sortlist, we are switching for pivot using high pointer.
		In case of last position in sortlist, we are switching for pivot using low pointer.  				
	*/

	quicksort(0, sortlist_length - 1, sortlist);
	printf("[+] Sorted!\n");
	display_results(sortlist, sortlist_length);
}
