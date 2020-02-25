#include <stdio.h>


void display_results(int * arr, int count){
	printf("[+] Items: ");
	char * output;
	for (int i = 0; i < count; ++i){
		printf("%i ", arr[i]);
	}
	printf("\n");
}


void bubble_sort(int * sortlist, int count){
	for (int i = 0; i < count - 1; ++i){
		if(sortlist[i] > sortlist[i + 1]){
			int proxy = sortlist[i];
			sortlist[i] = sortlist[i + 1];
			sortlist[i + 1] = proxy;
		}
	}
}


int main(int argc, char const *argv[]){

	int sortlist[] = {44, 12, 55, -7, 4, 9, 37};
	int sortlist_length = sizeof(sortlist) / (int)sizeof(sortlist[0]);

	printf("[+] Sorting following..\n");
	display_results(sortlist, sortlist_length);

	for (int i = 0; i < sortlist_length; ++i){
		/*
		 *  TODO: Add swap check optimization in case of already
		 *	      sorted list, we could get some performance boost. 
		 */
		bubble_sort(sortlist, sortlist_length);
	}

	printf("[+] Sorted!:\n");
	display_results(sortlist, sortlist_length);

	return 0;
}
