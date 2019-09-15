#include <stdio.h>
#include "dynamic_array.h"


int main(){
	char foo = 'a';
	int moo = _dynamic_array_method(&foo);
	printf("Works %d!\n", moo);
	// _do_not_import_me();
	return 0;
}
