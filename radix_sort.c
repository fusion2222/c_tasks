#include <stdio.h>
#include "utils.h"


int main(int argc, char const *argv[]){
	printf("[+] This is radix sort...'\n");

	int sortlist[] = {4, 1, 1, 3, 0, 5, 2, 6, 2, 8, 7, 9, 3, 1};
	int sortlist_length = (int)sizeof(sortlist) / (int)sizeof(sortlist[0]);

	// display_results(sortlist, sortlist_length);

	int output_sortlist[sortlist_length];
	

	display_results(sortlist, sortlist_length);

	// countsort(sortlist, output_sortlist, sortlist_length);

	// display_results(output_sortlist, sortlist_length);

	return 0;
}
