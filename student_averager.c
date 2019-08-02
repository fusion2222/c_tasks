#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int TOTAL_STUDENTS_LIMIT = 50;
const int NAME_CHAR_LIMIT = 50;


typedef struct {
    char first_name[NAME_CHAR_LIMIT];
    char last_name[NAME_CHAR_LIMIT];
    char birth_date[11];
    short int average_grade;
} STUDENT;


void gather_user_data_for_student(STUDENT * list, int index){
	// Add single to array

	char first_name[NAME_CHAR_LIMIT];
	printf("Enter student's first name: ");
	scanf(" %s", first_name);

	char last_name[NAME_CHAR_LIMIT];
	printf("Enter student's last name: ");
	scanf(" %s", last_name);

	char birth_date[11];  // 11 because of nullbyte
	printf("Enter student's birthday in format YYYY-MM-DD: ");
	scanf(" %s", birth_date);

	short int average_grade;
	printf("Enter student's average grade (numeric - 1 is the best and 5 is the worst): ");
	scanf(" %hd", &average_grade);

	// Create struct
	list[index].average_grade = average_grade;
	strcpy(list[index].first_name , first_name);
	strcpy(list[index].last_name , last_name);
	strcpy(list[index].birth_date , birth_date);
}


/*
 *	SORTING FUNCTIONS
 *  In these functions we cannot directly declare STUDENT
 *  type parameters - a compiler would be bitching.
 */ 
int sort_by_grade(const void * a, const void * b){
	const STUDENT * struct_a = a;
	const STUDENT * struct_b = b;	
	return (*struct_a).average_grade - (*struct_b).average_grade;
}


int sort_by_first_name(const void * a, const void * b){
	const STUDENT * struct_a = a;
	const STUDENT * struct_b = b;
	return strcmp((*struct_a).first_name, (*struct_b).first_name);
}


int sort_by_last_name(const void * a, const void * b){
	const STUDENT * struct_a = a;
	const STUDENT * struct_b = b;
	return strcmp((*struct_a).last_name, (*struct_b).last_name);
}


int sort_by_birth_date(const void * a, const void * b){
	const STUDENT * struct_a = a;
	const STUDENT * struct_b = b;
	return strcmp((*struct_a).birth_date, (*struct_b).birth_date);
}


void show_results(STUDENT * student_list, int total_students_added){
	printf(
		"==============================================================================\n"
		"|   First name    |    Last name    |     Birth Date    |    Average grade   |\n"
		"==============================================================================\n"
	);
	for(int i = 0; i < total_students_added; ++i){
		printf(
			"|   %s    |    %s    |     %s    |    %d   |\n",
			student_list[i].first_name,
			student_list[i].last_name,
			student_list[i].birth_date,
			student_list[i].average_grade
		);
	}
}


int main(){
	STUDENT students[TOTAL_STUDENTS_LIMIT];
	printf("Add students please:\n");

	int total_students_added;

	for (int i = 0; i < TOTAL_STUDENTS_LIMIT; ++i){
		gather_user_data_for_student(students, i);
		total_students_added = i;

		char user_answer[4];

		printf(			
			"\nStudent has been added!"
			"\n\nDo you want to add another student? [yes / no]\n"
		);
		scanf(" %s", user_answer);

		if(strcmp(user_answer, "no") == 0){
			break;
		}

	}

	// First we sort our array based on user's specified parameter with.
	char sort_type[20];
	memset(sort_type, 0, sizeof(char));

	while(1){
		printf("How do you want to sort students? [ first_name / last_name / birth_date / average_grade ]\n");
		scanf(" %20s", sort_type);

		if(strcmp(sort_type, "first_name") == 0){
			qsort(students, total_students_added, sizeof(STUDENT), sort_by_first_name);
			break;
		}else if(strcmp(sort_type, "last_name") == 0){
			qsort(students, total_students_added, sizeof(STUDENT), sort_by_last_name);
			break;
		}else if(strcmp(sort_type, "birth_date") == 0){
			qsort(students, total_students_added, sizeof(STUDENT), sort_by_birth_date);
			break;			
		}else if(strcmp(sort_type, "average_grade") == 0){
			qsort(students, total_students_added, sizeof(STUDENT), sort_by_grade);
			break;
		}
		printf("Unknown answer... Please specify your entry again.");
	}	

	show_results(students, total_students_added);

	return 0;
}
