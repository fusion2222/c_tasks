#include <stdio.h>
#include <string.h>
#include "display_results.h"


int main(int argc, char const *argv[]){
	int sortlist[] = {4, 1, 1, 3, 0, 5, 2, 6, 2, 8, 7, 9, 3, 1};
	int sortlist_length = (int)sizeof(sortlist) / (int)sizeof(sortlist[0]);

	display_results(sortlist, sortlist_length);

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

	// Create output array
	int output_sortlist[sortlist_length];
	memset(output_sortlist, 0, sortlist_length * (int)sizeof(int));

	for(int i = 0; i < sortlist_length; ++i){
		count_array[sortlist[i]]--;
		output_sortlist[
			count_array[sortlist[i]]
		] = sortlist[i];
	}

	display_results(output_sortlist, sortlist_length);
	return 0;
}
