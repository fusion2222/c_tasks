#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * This implementation will contain Graph, consisting of Nodes. Graph vertices will be
 * mapped using adjacency list. Those have multiple Child elements. Child element is
 * basically pointing to Node. This is done because we want only single place "Node",
 * where is marked, if node already has been visited.
 */


/******************
 ** DECLARATIONS **
 ******************/

struct node{
	// Represent vertices
	int key;
	bool visited;
	struct neighbour * direct_neighbour;
};
typedef struct node Node;

struct neighbour{
	// Serves for adjacency list.
	Node * node;
	struct neighbour * next;
};
typedef struct neighbour Neighbour;

struct graph{
	int vertice_count;
	Node ** vertices;
	Node ** search_queue;
	int search_queue_rear;
	int search_queue_front;
};
typedef struct graph Graph;


/***********
 ** GRAPH **
 ***********/

Node * create_node(int key){
	Node * n = (Node *)malloc(sizeof(Node));
	n->key = key;
	n->visited = false;
	return n;
}


Neighbour * create_neighbour(Node * node_pointer){
	Neighbour * n = (Neighbour *)malloc(sizeof(Neighbour));
	n->node = node_pointer;
	return n;
}


Graph * initialize_graph(int size){
	Graph * g = (Graph *)malloc(sizeof(Graph));
	g->vertice_count = size;
	g->vertices = (Node **)malloc(sizeof(Node *) * g->vertice_count);
	g->search_queue = (Node **)malloc(sizeof(Node *) * g->vertice_count);
	g->search_queue_rear = -1;
	g->search_queue_front = -1;

	// Initialize search queue
	for (int i = 0; i < g->vertice_count; ++i){
		g->search_queue[i] = NULL;
	}

	for (int i = 0; i < g->vertice_count; ++i){
		g->vertices[i] = create_node(i);
	}

	/* Set Neighbours */
	g->vertices[0]->direct_neighbour = create_neighbour(g->vertices[1]);
	g->vertices[0]->direct_neighbour->next = create_neighbour(g->vertices[2]);
	g->vertices[0]->direct_neighbour->next->next = create_neighbour(g->vertices[3]);
	g->vertices[0]->direct_neighbour->next->next->next = g->vertices[0]->direct_neighbour;

	g->vertices[1]->direct_neighbour = create_neighbour(g->vertices[0]);
	g->vertices[1]->direct_neighbour->next = create_neighbour(g->vertices[2]);
	g->vertices[1]->direct_neighbour->next->next = create_neighbour(g->vertices[4]);
	g->vertices[1]->direct_neighbour->next->next->next = g->vertices[1]->direct_neighbour;

	g->vertices[2]->direct_neighbour = create_neighbour(g->vertices[1]);
	g->vertices[2]->direct_neighbour->next = create_neighbour(g->vertices[0]);
	g->vertices[2]->direct_neighbour->next->next = g->vertices[2]->direct_neighbour;
	
	g->vertices[3]->direct_neighbour = create_neighbour(g->vertices[0]);
	g->vertices[3]->direct_neighbour->next = g->vertices[3]->direct_neighbour;

	g->vertices[4]->direct_neighbour = create_neighbour(g->vertices[1]);
	g->vertices[4]->direct_neighbour->next = g->vertices[4]->direct_neighbour;

	return g;
}


/*******************
 ** SEARCH QUEUES **
 *******************/

Node * search_queue_peek(Graph * g){
	return g->search_queue[g->search_queue_front];
}


bool search_queue_is_full(Graph * g){
	return g->search_queue_rear >= g->vertice_count;
}


bool search_queue_is_empty(Graph * g){
	return g->search_queue_front > g->search_queue_rear || (g->search_queue_front == -1 && g->search_queue_rear == -1);
}


void search_queue_enqueue(Graph * g, Node * n){
	// Add element to Graph's search queue

	printf("[+] Node %d put into a queue\n", n->key);

	if(search_queue_is_full(g)){
		printf("[+] The search queue is full!\n");
		return;
	}

	if(g->search_queue_front == -1 && g->search_queue_rear == -1){
		g->search_queue_front = 0;
		g->search_queue_rear = 0;
	}

	g->search_queue[g->search_queue_rear] = n;
	g->search_queue_rear++;
	n->visited = true;
}


Node * search_queue_dequeue(Graph * g){
	// Remove element from Graph's search queue
	if(search_queue_is_empty(g)){
		printf("[+] The serch queue is empty!\n");
		return NULL;
	}
	Node * output_node = g->search_queue[g->search_queue_front];
	g->search_queue[g->search_queue_front] = NULL;
	g->search_queue_front++;
	return output_node;
}


void enqueue_neighours(Graph * g, Neighbour * direct_neighbour){
	/* 
		Iterates over neighbours and pushes them into a search queue
		if they were not yet visited. Let's suppose Graph's node keys
		are unique and not negative!
	*/
	Neighbour * current_neighbour = direct_neighbour;
	int first_neighbour_key = current_neighbour->node->key;
	int cycles = 0;  // Indicates how many times we iterated linked list.
	
	while(cycles < 2){
		if(current_neighbour->node->key == first_neighbour_key){
			cycles++;
			if(cycles == 2){
				break;
			}
		}
		
		if(!current_neighbour->node->visited){
			search_queue_enqueue(g, current_neighbour->node);
			current_neighbour->node->visited = true;	
		}


		current_neighbour = current_neighbour->next;
	}
}


void breadth_first_search(Graph * g, Node * starting_search_node, int key_to_find){
	search_queue_enqueue(g, starting_search_node);
	Node * current_node = NULL;

	while(!search_queue_is_empty(g)){
		current_node = search_queue_dequeue(g);
		if(current_node->key == key_to_find){
			printf("[+] Found!\n");
			return;
		}

		enqueue_neighours(g, current_node->direct_neighbour);
	}
	
}


int main(int argc, char const *argv[]){
	/*
		Example Graph:
			
			(0)
		 /   |   \
	   (1)--(2)  (3) 
		|
	   (4)
	*/
	
	Graph * g = initialize_graph(5);
	int search_value = 1;  // We want to find node with this value in graph.
	printf("[+] Start searching for value %d ...\n", search_value);

	// Let's start search from the 0th vertice.
	breadth_first_search(g, g->vertices[0], search_value);
	return 0;
}
