#include <stdio.h>
#include <string.h>

const short int EAN_CODE_SIZE = 13;
const short int ASCII_NUMBER_POSITION = 48;


void validate_ean_code(char * ean_code){
	short int odd_sum = 0;
	short int even_sum = 0;

	for(short int i = EAN_CODE_SIZE - 2; i >= 0; i--){
		int current_number = ean_code[i] - ASCII_NUMBER_POSITION;

		if(i % 2){
			odd_sum += current_number;
		}else{
			even_sum += current_number;
		}

	}

	int base_sum = odd_sum * 3 + even_sum;
	int rounded_sum = base_sum + 10 - base_sum % 10;

	int validation_digit = ean_code[EAN_CODE_SIZE - 1] - ASCII_NUMBER_POSITION;

	if(rounded_sum - base_sum == validation_digit){
		printf("Provided EAN code is valid!\n");
	}else{
		printf("Provided EAN code is invalid!\n");
	}
}

int contains_only_digits(char * string, int size){
	for(int i = size - 1; i >= 0; i--){
		if(string[i] >= ASCII_NUMBER_POSITION && string[i] <= ASCII_NUMBER_POSITION + 9){
			continue;
		}
		return 0;
	}
	return 1;
}

int main(int argc, char *argv[]){
	// EAN13 code validator.

	if(argc != 2){
		printf("You must enter single EAN13 code as command parameter.");
		return 1;
	}

	if(strlen(argv[1]) != EAN_CODE_SIZE){
		printf("Your EAN13 does not contain %d characters!", EAN_CODE_SIZE);
		return 1;
	}

	if(!contains_only_digits(argv[1], EAN_CODE_SIZE)){
		printf("Your EAN13 must contain only digits!");
		return 1;
	}

	validate_ean_code(argv[1]);
	return 0;
}
