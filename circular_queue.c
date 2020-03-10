#include <stdio.h>
#include "utils.h"


// Constants
#define MAX 6


// Definitions
struct circular_queue{
    int items[MAX];
    int front;
    int rear;
};
typedef struct circular_queue CircularQueue;


// Functions
void reset_queue(CircularQueue * q){
    q->front = -1;
    q->rear = -1;
}


int get_queue_index(int index){
	return index % MAX;
}


int is_empty(CircularQueue * q){
	return q->front > q->rear;
}


int is_full(CircularQueue * q){
	return  q->rear - q->front >= MAX - 1;
}


void enqueue(CircularQueue * q, int item){
	if(is_full(q)){
		printf("[+] Cannot enqueue any more elements. CircularQueue is full.\n");
		return;
	}

	printf("[+] Added new element %d\n", item);

	if(q->front == -1){
		q->front++;
	}

	q->rear++;
	q->items[get_queue_index(q->rear)] = item;
}


void dequeue(CircularQueue * q){
	if(is_empty(q)){
		printf("[+] Cannot dequeue any more elements. CircularQueue is empty.\n");
		return;
	}

	printf("[+] Dequeued element %d\n", q->items[q->front]);

	// Seemingly Deleting Item
	q->items[get_queue_index(q->front)] = 0;
	q->front++;

	// Minor Optimization.
	if(q->front > q->rear){
		reset_queue(q);
	}

}


int peek(CircularQueue * q){
	return q->items[get_queue_index(q->front)];
}

void show_indexes(CircularQueue * q){
	printf("[+] Rear: %d | Front %d\n", q->rear, q->front);
}


int main(int argc, char const *argv[]){
	CircularQueue q;

	// TODO: Make better REAR and FRONT index optimization in order to prevent integer overflow.
	reset_queue(&q);
	
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	enqueue(&q, 60);
	dequeue(&q);
	dequeue(&q);
	enqueue(&q, 70);
	enqueue(&q, 80);
	enqueue(&q, 90);

	display_results(q.items, MAX);

	printf("[+] Peeking: %d\n", peek(&q));

	show_indexes(&q);
	return 0;
}
