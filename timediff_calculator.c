#include <stdio.h>
#include <stdlib.h>
#include <math.h>


const int DAY_MINUTES = 1440;  // How many minutes are in one day.
const int ASCII_NUMBERS_POSITION = 48;


int validate_input_time(int hours, int minutes, char * label){
	if(!(hours >= 0 && hours < 24)){
		printf("ERROR! Entered %s hours must be between 0 to 24\n", label);
		return 1;
	}

	if(!(minutes >= 0 && minutes < 60)){
		printf("ERROR! Entered %s minutes must be between 0 to 60\n", label);
		return 1;
	}

	return 0;
}

int is_char_numeric(char character){
	int int_character = character;
	return int_character >= ASCII_NUMBERS_POSITION && int_character <= 57;
}

int is_input_time_valid(char * label){
	return is_char_numeric(label[0]) && is_char_numeric(label[1]) && is_char_numeric(label[3]) && is_char_numeric(label[4]) && label[2] == ':';
}

int convert_char_to_int(char character){
	int num = character;
	return num - ASCII_NUMBERS_POSITION;
}

int extract_decimal(char * time, int start, int size){
	// Variable `start` indicates start from the end of the string. We will go backwards for `size` number of characters.
	int output = 0;
	int char_pos = start;

	for(int i = 0; i < size; i++){
		output += convert_char_to_int(time[char_pos]) * pow(10, i);
		char_pos--;
	}

	return output;
}

int is_time_correct(int minutes, int hours){
	return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60;
}

char * double_digit_format(int number){
	char first_decimal = number / 10 + ASCII_NUMBERS_POSITION;
	char second_decimal = number % 10 + ASCII_NUMBERS_POSITION;

	// Allocating memory on Heap, because scope of this function
	// will be purged after it ends, resulting to data loss.
	char * output = (char *) malloc(2);

	// TODO: Check for possible Little / Big Endian conflicts.
	output[0] = first_decimal;
	output[1] = second_decimal;
	return output;
}


int main(void){  
	//  Size 6 - because in every string declaration nullbyte is created at the end of each string.
	char starting_time[6];
	char ending_time[6];

	printf("Please type starting time in format HH:MM: ");
	scanf("%s", starting_time);

	if(!is_input_time_valid(starting_time)){
		printf("Starting time has been entered in wrong format.\n");
		return 2;
	}

	printf("Please type ending time in format HH:MM: ");
	scanf("%s", ending_time);

	if(!is_input_time_valid(ending_time)){
		printf("Ending time has been entered in wrong format.\n");
		return 2;
	}

	int starting_time_minutes = extract_decimal(starting_time, 4, 2);
	int starting_time_hours = extract_decimal(starting_time, 1, 2);

	if(!is_time_correct(starting_time_minutes, starting_time_hours)){
		printf("Starting time has been entered in wrong format.\n");
		return 2;
	}

	int ending_time_minutes = extract_decimal(ending_time, 4, 2);
	int ending_time_hours = extract_decimal(ending_time, 1, 2);

	if(!is_time_correct(ending_time_minutes, ending_time_hours)){
		printf("Ending time has been entered in wrong format.\n");
		return 2;
	}

	int starting_time_total_minutes = starting_time_hours * 60 + starting_time_minutes;
	int ending_time_total_minutes = ending_time_hours * 60 + ending_time_minutes;

	int minute_difference = 0;

	if(starting_time_total_minutes < ending_time_total_minutes){
		minute_difference = ending_time_total_minutes - starting_time_total_minutes;
	}else{
		minute_difference = DAY_MINUTES - starting_time_total_minutes + ending_time_total_minutes;
	}

	// TODO: Think if memory should be allocated on the stack of the main function.
	char * output_hour_difference = double_digit_format(minute_difference / 60);
	char * output_minute_difference = double_digit_format(minute_difference % 60);

	printf("The difference between your dates is: %s:%s\n", output_hour_difference, output_minute_difference);

	return 0;
}
