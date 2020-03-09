#include <stdio.h>
#include "utils.h"


// Constants
#define MAX 10


// Definitions
struct stack{
    int items[MAX];
    int top;
};
typedef struct stack Stack;


// Functions
void initialize_stack(Stack * s){
	s->top = -1;
}

int is_empty(Stack * s){
	return s->top < 0;
}


int is_full(Stack * s){
	return s->top >= MAX - 1;
}


void push(Stack * s, int item){
	if(is_full(s)){
		printf("[+] Cannot push further elements. The stack is full.\n");
		return;
	}
	s->top++;
	s->items[s->top] = item;
	printf("[+] Element added.. %d\n", item);
}


void pop(Stack * s){
	if(is_empty(s)){
		printf("[+] Cannot pop elements. The stack is empty.\n");
		return;
	}
	printf("[+] Element popped.. %d\n", s->items[s->top]);
	s->items[s->top] = 0;
	s->top--;
}


int peek(Stack * s){

	if(is_empty(s)){
		printf("[+] The Stack is empty. Nothing to peek on!\ns");
		return 0;
	}

	int output = s->items[s->top];
	printf("[+] PEEK! Top value is %d\n", output);
	return output;
}


int main(int argc, char const *argv[]){
	Stack s;
	initialize_stack(&s);
	
	for (int i = 0; i < MAX + 1; i++){
		push(&s, (i + 2) * 10);
	}	

	for (int i = MAX; i >= 0; i--){
		pop(&s);
	}	

	push(&s, 777);
	peek(&s);
	pop(&s);
	pop(&s);
	peek(&s);

	return 0;
}
