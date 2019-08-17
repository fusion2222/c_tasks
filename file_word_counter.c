#include <stdio.h>
#include <string.h>
#include <stddef.h>


// global helper
int previous_char_is_whitespace = 0;


int count_words(FILE * text_file_ptr){
	/*
	 * By word we will consider every chunk of non-whitespaced characters.
	 */

	fseek(text_file_ptr, 0, SEEK_SET);
	int output = 0;

	while(!feof(text_file_ptr)){
		int ascii_char = (int)fgetc(text_file_ptr);
		int is_whitespace_char = (int)(ascii_char > 32 && ascii_char <= 254);

		if(is_whitespace_char && !previous_char_is_whitespace){
			output++;
		}

		previous_char_is_whitespace = is_whitespace_char;
	}
	return output;
}


int main(int argc, char *argv[]){
	/*
	 * This program should be able to read a file and then read its content,
	 * and count all the words inside. There is dummy_text_file.txt stored
	 * here, which has totall 719 words.
	 */

	if(argc < 2){
		printf("You must provide file name as parameter when launching this program!\n");
		return 0;
	}

	FILE * text_file_ptr = fopen(argv[1], "r");

	if(text_file_ptr == NULL){
		printf("You are trying to open a non-existing file... exiting.\n");
		return 0;
	}

	/* Seek to the beginning of the file, so we can start reading */	
	int total_words = count_words(text_file_ptr);

	printf("Total words count in `%s` file is: %d\n", argv[1], total_words);

	// Closing the file
	if(fclose(text_file_ptr) == EOF){
		printf("There was a problem closing the file!\n");
	}
	return 0;
}
