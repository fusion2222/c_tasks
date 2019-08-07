#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int MAX_COMMAND_BUFFER_LENGTH = 20;


void show_total_free_parking_spaces(unsigned int * parking_field, int * total_parking_places){
	// typeof in this case returns 4 on some OS, 8 on mac, which is damn wierd!!!
	int total_parking_field_bits = sizeof(unsigned int) * 8;
	unsigned int mask = 1;
	int total_free_places = 0;

	for (int i = 0; i < *total_parking_places; ++i){
		total_free_places += (*parking_field) >> i & mask;
	}

	printf("There are %d free parking places available.\n\n", total_free_places);
}


void show_parking_field(unsigned int * parking_field, int * total_parking_places){
	// typeof in this case returns 4 on some OS, 8 on mac, which is damn wierd!!!
	int total_parking_field_bits = sizeof(unsigned int) * 8;
	unsigned int mask = 1;

	int output_seg_size = 3;

	char solid_output_line[*total_parking_places * output_seg_size + 1];
	char places_output_line[*total_parking_places * output_seg_size + 1];
	

	for (int i = 0; i < *total_parking_places; ++i){
		solid_output_line[i * output_seg_size + 2] = '=';
		solid_output_line[i * output_seg_size + 1] = '=';
		solid_output_line[i * output_seg_size] = '=';

		places_output_line[i * output_seg_size + 2] = ' ';
		places_output_line[i * output_seg_size + 1] = (char) ((*parking_field) >> i & mask) + 48;
		places_output_line[i * output_seg_size] = ' ';
	}

	
	printf("%s\n", solid_output_line);
	printf("Parking field\n");
	printf("%s\n", solid_output_line);
	printf("%s\n", places_output_line);
	printf("%s\n\n", solid_output_line);
	
}


void is_parking_place_free(unsigned int * parking_field, int parking_place){
	int total_parking_field_bits = sizeof(unsigned int) * 8;
	unsigned int mask = 1;
	printf("Parking place number %d is %s\n\n", parking_place, (*parking_field) >> parking_place & mask ? "occupied" : "free");
}

void capture_parking_place(unsigned int * parking_field, int parking_place){
	int total_parking_field_bits = sizeof(unsigned int) * 8;
	unsigned int mask = 1;
	*parking_field = (mask << parking_place) | *parking_field;
	printf("Parking field number %d has been captured!\n\n", parking_place);
}

void free_parking_place(unsigned int * parking_field, int parking_place){
	int total_parking_field_bits = sizeof(unsigned int) * 8;
	unsigned int mask = 1;
	*parking_field = (mask << parking_place) ^ *parking_field;
	printf("Parking field number %d has been freed!\n\n", parking_place);
}


char * ask_and_execute_user_command(unsigned int * parking_field, int * total_parking_places){
	char command[MAX_COMMAND_BUFFER_LENGTH];
	
	while(1){
		printf(
			"Please enter the command. These are available:\n"
			" - check {parking place number} - Checks if specified parking place is free or not.\n"
			" - capture {parking place number} - Marks specified parking place as captured.\n"
			" - free {parking place number} - Frees parking specified place.\n"
			" - show - Shows graphical parking field representation.\n"
			" - total_free - Shows count total free parking places.\n"
			" - exit - Exits the program.\n"
		);

		memset(command, '\0', sizeof(command));
		fgets(command, MAX_COMMAND_BUFFER_LENGTH, stdin); 

		if(strcmp(command, "exit\n") == 0){
			printf("Exiting program... Bye!\n");
			exit(0);
		}else if(strcmp(command, "show\n") == 0){
			show_parking_field(parking_field, total_parking_places);
			continue;
		}else if(strcmp(command, "total_free\n") == 0){
			show_total_free_parking_spaces(parking_field, total_parking_places);
			continue;
		}

		for (int i = 0; i < MAX_COMMAND_BUFFER_LENGTH; i++){
			if(command[i] != ' '){continue;}

			char * number_param_ptr = command + i + 1;
			int numeric_parameter = atoi(number_param_ptr);
			command[i] = '\0';

			if(numeric_parameter < 0 || numeric_parameter > *total_parking_places){
				printf("Parking available places indexes can are only from 0 to is %d!!!\n\n", *total_parking_places);
				break;
			}

			if(strcmp(command, "check") == 0){
				is_parking_place_free(parking_field, numeric_parameter);
				break;
			}else if(strcmp(command, "capture") == 0){
				capture_parking_place(parking_field, numeric_parameter);
				break;
			}else if(strcmp(command, "free") == 0){
				free_parking_place(parking_field, numeric_parameter);
				break;
			}

			break;
		}
	}
}


int main(int argc, char *argv[]){
	if(argc < 1){
		printf("Enter integer parameter representing your birth month");
		return 1;
	}

	// This represent user's birth of month.
	int total_parking_places = atoi(argv[1]);

	if(total_parking_places < 1 || total_parking_places > 12){
		printf("Enter integer parameter representing your birth month");
		return 1;
	}

	unsigned int parking_field = 1;

	ask_and_execute_user_command(&parking_field, &total_parking_places);

	return 0;
}
