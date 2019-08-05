#include <regex.h>
#include <stdio.h>
#include <stdlib.h>


void show_parking_field(unsigned int * parking_field, int * total_parking_places){
	// typeof in this case returns 4 on some OS, 8 on mac, which is damn wierd!!!
	int total_parking_field_bits = sizeof(unsigned int) * 8;
	unsigned int mask = 1;

	printf("==============\n");
	printf("Parking places\n");

	for (int i = 0; i < *total_parking_places; ++i){
		printf("==============\n");
		printf("%d\n", (*parking_field) >> i & mask);
	}

}


char * get_user_command(){
	printf(
		"Please enter the command. These are available:\n"
		" - check {parking place number} - Checks if specified parking place is free or not.\n"
		" - capture {parking place number} - Marks specified parking place as captured.\n"
		" - free {parking place number} - Frees parking specified place.\n"
		" - show - Shows graphical parking field representation.\n"
		" - total_free - Shows count total free parking places.\n"
	);

	int char_command_length = 20;
	char * command[char_command_length];

	while(i){
		scanf(" %s", command);

		if(strcmp(command, "total_free") || strcmp(command, "show")){
			// No further param commands.
			break;
		}

		for (int i = 0; i < char_command_length; ++i){
			if(command[i] == ' '){
				// i
			}
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

	unsigned int parking_field = 0;

	show_parking_field(&parking_field, &total_parking_places);

	return 0;
}
