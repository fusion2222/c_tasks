#include <stdio.h>


void display_results(int * arr, int count){
	printf("[+] Items: ");
	for (int i = 0; i < count; ++i){
		printf("%i ", arr[i]);
	}
	printf("\n");
}
