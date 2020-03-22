#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int hash_function(int value){
	// Keeping it simple
	return value / 2;
}


int ** create_direct_address_table(int size){
	int ** output = (int **)malloc(sizeof(int *) * size);
	for (int i = 0; i < size; ++i){
		output[i] = NULL;
	}
	return output;
}


void create_entry(int table_length, int * table[table_length], int key, int value){
	int * entry = (int *) malloc(sizeof(int) * 2);
	int hashed_key = hash_function(key);
	entry[0] = hashed_key;
	entry[1] = value;
	table[hashed_key] = entry;
	printf("[+] Key %d has been created in hash table with value %d\n", key, value);
}


void delete_entry(int ** arr, int key){
	arr[hash_function(key)] = NULL;
	printf("[+] Key %d has been deleted!\n", key);
}


void search_by_key(int ** arr, int key){
	int hashed_key = hash_function(key);

	if(arr[hashed_key] == NULL){
		printf("[+] Key %d does not exist in the hash table\n", key);
		return;
	}
	printf("[+] The hash table key %d has value %d\n", key, arr[hashed_key][1]);
}


int main(int argc, char const *argv[]){
	int direct_table_length = 10;
	int ** direct_table = create_direct_address_table(direct_table_length);

	// For sake of simplicity, there will be no collision problem ahead.
	create_entry(direct_table_length, direct_table, 2, 337);
	create_entry(direct_table_length, direct_table, 4, 94);

	search_by_key(direct_table, 2);
	search_by_key(direct_table, 4);
	search_by_key(direct_table, 7);
	delete_entry(direct_table, 4);
	search_by_key(direct_table, 4);
	return 0;
}
