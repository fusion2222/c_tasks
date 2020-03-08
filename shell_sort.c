#include <stdio.h>
#include "utils.h"


void shell_sort(int * sortlist, int sortlist_length, int gap){	

	for(int i = 0; i + gap < sortlist_length; ++i){
		if(sortlist[i] > sortlist[i + gap]){
			swap(&sortlist[i], &sortlist[i + gap]);
		}
	}

	if(sortlist[0] > sortlist[gap]){
		swap(&sortlist[0], &sortlist[gap]);
	}

	gap--;

	if(gap > 0){
		shell_sort(sortlist, sortlist_length, gap);
	}

}


int main(int argc, char const *argv[]){
	int sortlist[] = {13, 2, 22, 11, 8, 9, -2, 1, -7, 0, 16, 27, 32, 12};
	int sortlist_length = (int)sizeof(sortlist) / (int)sizeof(sortlist[0]);

	display_results(sortlist, sortlist_length);

	// TODO: Make gap steps as array.
	shell_sort(sortlist, sortlist_length, sortlist_length / 2);

	display_results(sortlist, sortlist_length);
	return 0;
}
