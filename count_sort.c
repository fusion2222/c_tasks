#include <stdio.h>
#include <string.h>


void count_sort(int * sortlist, int * output_sortlist, int sortlist_length){

	// Initialize counting array with zeroes
	int count_array_length = sortlist_length + 1;
	int count_array[count_array_length];
	memset(count_array, 0, count_array_length * (int)sizeof(int));

	// Fill count array
	for(int i = 0; i < sortlist_length; ++i){
		count_array[sortlist[i]]++;
	}
	
	// Add previous indexes to next ones, so index projection fits.
	for(int i = 1; i < count_array_length; ++i){
		count_array[i] = count_array[i] + count_array[i - 1];
	}

	for(int i = 0; i < sortlist_length; ++i){
		count_array[sortlist[i]]--;
		output_sortlist[
			count_array[sortlist[i]]
		] = sortlist[i];
	}

}
