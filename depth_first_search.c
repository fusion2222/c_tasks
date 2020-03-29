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
	// Serves for adjacency list purposes.
	Node * node;
	struct neighbour * next;
};
typedef struct neighbour Neighbour;

struct graph{
	int vertice_count;
	Node ** vertices;
	Node ** search_stack;
	int search_stack_front;
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
	g->search_stack = (Node **)malloc(sizeof(Node *) * g->vertice_count);
	g->search_stack_front = -1;

	// Initialize search stack
	for (int i = 0; i < g->vertice_count; ++i){
		g->search_stack[i] = NULL;
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


int depth_first_search(Graph * g, Node * starting_search_node, int key_to_find){

	if(!starting_search_node->visited){
		starting_search_node->visited = true;
	}

	if(starting_search_node->key == key_to_find){
		printf("[+] Found!\n");
		return 1;
	}else{
		printf("[+] Checking node %d\n", starting_search_node->key);
	}

	Neighbour * current_neighbour = starting_search_node->direct_neighbour;
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
			// put into queue?
			if(depth_first_search(g, current_neighbour->node, key_to_find) > -1){
				return 1;
			}
		}


		current_neighbour = current_neighbour->next;
	}

	/*
	
	search_stack_push(g, starting_search_node);
	Node * current_node = NULL;

	while(!search_stack_is_empty(g)){
		current_node = search_stack_pop(g);
		if(current_node->key == key_to_find){
			printf("[+] Found!\n");
			return;
		}else{
			printf("[+] Checking %d node\n", current_node->key);
		}

		for (int i = 0; i < count; ++i){
			// code
		}

		if(){

		}

		depth_first_search()

		// add_neighours_to_search_stack(g, current_node->direct_neighbour);
	}
	*/
	return -1;
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
	int search_value = 4;  // We want to find node with this value in graph.
	printf("[+] Start searching for value %d ...\n", search_value);

	// Let's start search from the 0th vertice.
	depth_first_search(g, g->vertices[0], search_value);

	return 0;
}
