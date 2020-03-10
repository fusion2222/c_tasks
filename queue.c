#include <stdio.h>
#include "utils.h"


// Constants
#define MAX 6


// Definitions
struct queue{
    int items[MAX];
    int front;
    int rear;
};
typedef struct queue Queue;

/*
	SPERCIFICATION:
    Enqueue: Add element to end of queue
    Dequeue: Remove element from front of queue
    IsEmpty: Check if queue is empty
    IsFull: Check if queue is full
    Peek: Get the value of the front of queue without removing it
*/


// Functions
void reset_queue(Queue * q){
    q->front = -1;
    q->rear = -1;
}


int is_empty(Queue * q){
	return (int)(q->front > q->rear || (q->front == -1 && q->rear == -1));
}


int is_full(Queue * q){
	return q->rear >= MAX - 1;
}


void enqueue(Queue * q, int item){
	if(is_full(q)){
		printf("[+] Cannot enqueue any more elements. Queue is full.\n");
		return;
	}

	printf("[+] Added new element %d\n", item);

	if(q->front == -1){
		q->front++;
	}

	q->rear++;
	q->items[q->rear] = item;
}


void dequeue(Queue * q){
	if(is_empty(q)){
		printf("[+] Cannot dequeue any more elements. Queue is empty.\n");
		return;
	}

	printf("[+] Dequeued element %d\n", q->items[q->front]);

	q->items[q->front] = 0; // seemingly deleting item;
	q->front++;

	if(q->front >= MAX){
		reset_queue(q);
	}
}


int peek(Queue * q){
	return q->items[q->front];
}


int main(int argc, char const *argv[]){
	Queue q;
	reset_queue(&q);
	
	for (int i = 0; i < MAX + 1; i++){
		enqueue(&q, (i + 2) * 10);
	}	
	
	for (int i = MAX; i >= 0; i--){
		dequeue(&q);
	}

	printf("[+] Rear: %d | Front %d\n", q.rear, q.front);
	return 0;
}
