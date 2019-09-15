#include <stdio.h>
#include "dynamic_array.h"


const int _PRIVATE_CONSTANT = 132;


typedef struct {
	short int size;
	int *data;
	// void * method;
} DynamicArray;


DynamicArray get_dynamic_array(){
	/*
		This basic dynamic-array implementation.
	*/

	DynamicArray dynamic_array;
	return 
}


int _dynamic_array_method(const void * self){
	return _PRIVATE_CONSTANT;
}


void _do_not_import_me(){
	printf("This is destructive..\n");
}

int fine(){
	DynamicArray a;
	a.prop = 123;
	a.method = &_dynamic_array_method;
	printf("I work! %d \n", a.prop);
	return 0;
}

