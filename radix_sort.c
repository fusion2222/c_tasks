#include <stdio.h>
#include <string.h>
#include <math.h>
#include "utils.h"


int get_radix(n, radix_position){
	int decimal_place_divisor = (int)pow(10, radix_position);
	return (int)(n % (decimal_place_divisor * 10) / decimal_place_divisor);
}


void count_sort(int * sortlist, int * output_sortlist, int sortlist_length, int radix_position){
	// Special countsort, which does take a look upon decimal position.
	// Initialize counting array with zeroes
	int count_array_length = sortlist_length + 1;
	int count_array[count_array_length];
	memset(count_array, 0, count_array_length * (int)sizeof(int));

	int radix = 0;

	// Fill count array
	for(int i = 0; i < sortlist_length; ++i){
		radix = get_radix(sortlist[i], radix_position);
		count_array[radix]++;
	}

	// Add previous indexes to next ones, so index projection fits.
	for(int i = 1; i < count_array_length; ++i){
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	
	for(int i = sortlist_length - 1; i >= 0 ; i--){
		radix = get_radix(sortlist[i], radix_position);

		count_array[radix]--;
		output_sortlist[
			count_array[radix]
		] = sortlist[i];
	}
}


int digits(int n){
	// Returns how much digits integer contains.
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}


int max(int * arr, int length){
	// Finds max value in array and returns its index.
	int max_index = 0;
	for (int i = 1; i < length; ++i){
		if(arr[max_index] < arr[i]){
			max_index = i;
		}
	}
	return max_index;
}


int main(int argc, char const *argv[]){
	int sortlist[] = {433, 101, 14, 3, 297, 117, 332, 449, 632, 255, 116, 144, 22, 105};
	int sortlist_length = (int)sizeof(sortlist) / (int)sizeof(sortlist[0]);
	int output_sortlist[sortlist_length];

	int max_index = max(sortlist, sortlist_length);
	int maximum_digits = digits(sortlist[max_index]);

	display_results(sortlist, sortlist_length);

	for (int radix_position = 0; radix_position < maximum_digits; radix_position++){
		count_sort(sortlist, output_sortlist, sortlist_length, radix_position);
		memcpy(sortlist, output_sortlist, (int)sizeof(sortlist));
	}

	display_results(sortlist, sortlist_length);

	return 0;
}
