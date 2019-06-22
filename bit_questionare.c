#include <limits.h>
#include <stdio.h>
#include <string.h>


const ASCII_NUM_CHAR_POSITION = 48;


void print_value_as_bits(unsigned char * output){
	// This function displays every single bit from our value.
	unsigned char bitstring[CHAR_BIT + 1];  // +1 so we can append null at the end for sake of printf.
	unsigned char base_mask = 1;

	// char_position = human readable, left-to-right.
	for(short int char_position = 0; char_position < CHAR_BIT; char_position++){
		bitstring[char_position] = ((*output >> (CHAR_BIT - 1 - char_position)) & base_mask) + ASCII_NUM_CHAR_POSITION;
	}

	bitstring[CHAR_BIT] = '\0';
	printf("Bit-Encoded output is: %s\n", bitstring);
}

int ask_question(char * question_str, char * one_answer, char * zero_answer){
	char user_answer[20];
	printf("%s", question_str);

	while(1){
		scanf("%s", user_answer);
		if(strcmp(user_answer, zero_answer) == 0){
			return 0;
		}else if(strcmp(user_answer, one_answer) == 0){
			return 1;
		}else{
			printf("Your answer is incorrect. Please specify your answer again.\n");
		}
	}
}

int ask_user_for_birth_month(){
	short unsigned int user_answer;
	printf("In which month was person born? 1 - January, 12 - December:\n");

	while(1){
		scanf("%hu", &user_answer);
		if(user_answer <= 12 && user_answer > 0){
			return user_answer;
		}else{
			printf("Hmmm.. Month must be in the range 1 - 12. Please enter the birth month number again:\n");
		}
	}
}

void add_bit_value_at_position(unsigned short int value, int position, unsigned char * output){
	int bit_position = CHAR_BIT - position; // We must reverse position to adjust bit position.
	unsigned char mask = value << bit_position;
	*output |= mask;
}

int main(void){
	/*
	 *	Into variable of type unsigned char code the next information:
	 *	0 Sex - Male (0) / Female (1)
	 *	1 Month of birth
	 *	2 Month of birth
	 *	3 Month of birth
	 *	4 Month of birth
	 *	5 Marital status - Single (0) / Married (1)
	 *	6 Has children - No (0) / Yes (1)
	 *	7 Employed - No (0) / Yes(1)
	 *
	 *	Program will ask user for all the mentioned data. Then it will encode them all
	 *  into single bit based value. Make single procedure for writing of every single
	 *	piece of data. We should be able to read standalone encoded values.
	 */

	// TODO: Figure out how to properly declare multiline strings.
	printf("\n**********************************************\n");
	printf("*                                            *\n");
	printf("*      Fill this The amazing Questionare     *\n");
	printf("*                                            *\n");
	printf("**********************************************\n");
	printf("Bro tip: Enter all your answers lowercase\n\n");

	// First let's gather all the data from user.
	short unsigned int sex = ask_question(
		"Is person male or female? Answer male or female:\n", "male", "female"
	);
	short unsigned int birth_month = ask_user_for_birth_month();
	short unsigned int marital_status = ask_question(
		"What is person's marital status? Single or married? Answer single or married:\n", "single", "married"
	);
	short unsigned int has_children = ask_question(
		"Does a person have children? Answer yes or no:\n", "yes", "no"
	);
	short unsigned int is_employed = ask_question(
		"Is person currently employed? Answer yes or no:\n", "yes", "no"
	);

	// Ok, our data are gathered. Now lets encode our values.
	unsigned char data = 0;  // So we have zeroes. Nulled char is null. 	
	unsigned char * pData = &data;

	add_bit_value_at_position(sex, 1, pData);
	add_bit_value_at_position(birth_month, 5, pData);
	add_bit_value_at_position(marital_status, 6, pData);
	add_bit_value_at_position(has_children, 7, pData);
	add_bit_value_at_position(is_employed, 8, pData);

	print_value_as_bits(pData);
	return 0;
}
