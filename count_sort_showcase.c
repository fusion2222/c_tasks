#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "count_sort.h"


int main(int argc, char const *argv[]){
	int sortlist[] = {4, 1, 1, 3, 0, 5, 2, 6, 2, 8, 7, 9, 3, 1};
	int sortlist_length = (int)sizeof(sortlist) / (int)sizeof(sortlist[0]);

	display_results(sortlist, sortlist_length);

	// Create output array
	int output_sortlist[sortlist_length];
	memset(output_sortlist, 0, sortlist_length * (int)sizeof(sortlist[0]));

	// Perform countsort
	count_sort(sortlist, output_sortlist, sortlist_length);
	display_results(output_sortlist, sortlist_length);

	return 0;
}
