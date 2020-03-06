#include <stdio.h>
#include "utils.h"


void insertion_sort(int * list, int list_length, int key_index){
	int key = list[key_index];

	for (int i = key_index - 1; i >= 0; i--){

		if(list[i] <= key){
			break;
		}

		list[i + 1] = list[i];
		list[i] = key;
	}
}


int main(int argc, char const *argv[]){
	int sortlist[] = {34, 9, 59, -2, 8, 2, 17, 11};
	int sortlist_length = sizeof(sortlist) / (int)sizeof(sortlist[0]);

	display_results(sortlist, sortlist_length);

	// The first element is always considered sorted.
	for (int i = 1; i < sortlist_length; ++i){
		insertion_sort(sortlist, sortlist_length, i);
	}
	
	display_results(sortlist, sortlist_length);
}
