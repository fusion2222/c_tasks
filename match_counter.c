#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int ASCII_NUMBERS_POSITION = 48; 


int is_input_valid(char * input){
	int output = *input >= ASCII_NUMBERS_POSITION && *input < ASCII_NUMBERS_POSITION + 10;
	return output;
}


void display_results(int * arr, int arr_size){

	printf(
		" ==================================== \n"
		"|     Number       |       Count     |\n"
		" ==================================== \n"
	);

	for(int i = 0; i < arr_size; i++){
		printf(
			"         %d         |        %d       \n"
			" ==================================== \n",
			i, arr[i]
		);
	}

}


int main(int argc, char *argv[]){
	int map_size = 10;
	int count_map[map_size];

	// Assign default values, otherwise we will end up with some memory leftovers.
	for(int i = map_size; i >= 0; i--){
		count_map[i] = 0;
	}

	while(1){
		printf("Enter a single digit number:\n");

		char current_input;
		scanf(" %1c", &current_input);

		if(current_input == '\n' || current_input == EOF){
			continue;
		}

		if(current_input == 'k'){
			break;
		}

		if(!is_input_valid(&current_input)){
			printf("You entered invalid character!\n");
			continue;
		}

		int converted_current_input = current_input - ASCII_NUMBERS_POSITION;
		count_map[converted_current_input]++;
	}

	display_results(count_map, map_size);

	return 0;
}
