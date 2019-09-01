#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int CELL_BUFFER_SIZE = 100;


typedef struct {
	/*
		Lets assume, that any first_name, last_name, telephone_number will never be longer
		than `CELL_BUFFER_SIZE` characters. If yes, it will be considered as a validation error.
	*/
	char first_name[CELL_BUFFER_SIZE];
	char last_name[CELL_BUFFER_SIZE];
	char telephone_number[CELL_BUFFER_SIZE];
} TelephoneListRecord; 



void show_records(TelephoneListRecord * list, int record_count){
	for(int i = 0; i < record_count; i++){
		printf(
			"TelephoneListRecord #%d\n"
			"first_name: %s\n"
			"last_name: %s\n"
			"telephone_number: %s\n"
			"=======================\n",
			i,
			list[i].first_name,
			list[i].last_name,
			list[i].telephone_number
		);
	}
}


int main(int argc, char * argv[]){
	/*
		Program should load CSV data, and do some functionality among it.
	*/

	if(argc < 2){
		printf("You must provide file name as parameter when launching this program!\n");
		return 0;
	}

	FILE * telephone_list_file_ptr = fopen(argv[1], "r");

	if(telephone_list_file_ptr == NULL){
		printf("File `dummy_telephone_list.csv` could not be opened!\n");
		return 0;
	}

	fseek(telephone_list_file_ptr, 0, SEEK_SET);

	TelephoneListRecord * list = (TelephoneListRecord *)malloc(sizeof(TelephoneListRecord) * 0);

	int record_count = 0;
	int cell_number = 0;
	int char_position = 0;
	char null_char = '\0';

	char ascii_char;

	while((int)ascii_char != (int)EOF){
		ascii_char = fgetc(telephone_list_file_ptr);

		if(ascii_char == '\r'){
			char_position++;
			continue;
		}

		if(ascii_char == '\n' || record_count == 0){
			list = (TelephoneListRecord *) realloc(list, sizeof(TelephoneListRecord) * record_count);

			if(record_count == 0){
				fseek(telephone_list_file_ptr, 0, SEEK_SET);
			}

			record_count++;

			list[record_count - 1] = (TelephoneListRecord){};
			
			// We dont want to have any random stuff in our newly created structs.
			memcpy(list[record_count - 1].first_name, &null_char, CELL_BUFFER_SIZE);
			memcpy(list[record_count - 1].last_name, &null_char, CELL_BUFFER_SIZE);
			memcpy(list[record_count - 1].telephone_number, &null_char, CELL_BUFFER_SIZE);
			char_position = 0;
			cell_number = 0;
			continue;
		}

		if(ascii_char == ';'){
			cell_number++;
			char_position = 0;
			continue;
		}

		char * prop_ptr;

		if(cell_number == 0){
			prop_ptr = list[record_count - 1].first_name;
		}else if(cell_number == 1){
			prop_ptr = list[record_count - 1].last_name;
		}else if(cell_number == 2){
			prop_ptr = list[record_count - 1].telephone_number;
		}else{
			printf("An error has occured, cell number %d does not exist!\n", cell_number);
			exit(1);
		}
		
		prop_ptr[char_position] = ascii_char;
		char_position++;
	}

	show_records(list, record_count);

	return 0;
}
