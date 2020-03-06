#include <stdio.h>
#include "utils.h"


void selection_sort(int * list, int count, int start_index){
	int minimum_index = start_index;
	for(int i = start_index; i < count; ++i){	
		if(list[i] >= list[minimum_index]){
			continue;
		}
		minimum_index = i;
	}

	if(minimum_index != start_index){
		swap(&(list[minimum_index]), &(list[start_index]));
	}
}


int main(int argc, char const *argv[]){
	int sortlist[] = {44, 3, -22, -7, 4, 9, 37, 12};
	int sortlist_length = sizeof(sortlist) / (int)sizeof(sortlist[0]);

	display_results(sortlist, sortlist_length);
	printf("[+] Sorting...\n");

	for (int i = 0; i < sortlist_length; ++i){
		selection_sort(sortlist, sortlist_length, i);
	}

	display_results(sortlist, sortlist_length);

	return 0;
}
