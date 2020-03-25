#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int key;
    struct node * next;
};
typedef struct node Node;


struct graph{
    int size;  // amount of vertices.
    Node ** adjacency_list;
};
typedef struct graph Graph;


Node * create_node(int key){
	Node * n = (Node *)malloc(sizeof(Graph));
	n->key = key;
	return n;
}


Graph * initialize_graph(int size){
	Graph * g = (Graph *)malloc(sizeof(Graph));
	g->size = size;
	g->adjacency_list = (Node **)malloc(sizeof(Node *) * g->size);

	for (int i = 0; i < g->size; ++i){
		g->adjacency_list[i] = create_node(i);
	}

	g->adjacency_list[0]->next = create_node(1);
	g->adjacency_list[0]->next->next = create_node(2);
	g->adjacency_list[0]->next->next->next = create_node(3);
	g->adjacency_list[0]->next->next->next->next = g->adjacency_list[0];

	g->adjacency_list[1]->next = create_node(0);
	g->adjacency_list[1]->next->next = create_node(2);
	g->adjacency_list[1]->next->next->next = create_node(4);
	g->adjacency_list[1]->next->next->next->next = g->adjacency_list[1];
	
	g->adjacency_list[2]->next = create_node(0);
	g->adjacency_list[2]->next->next = create_node(1);
	g->adjacency_list[2]->next->next->next = g->adjacency_list[2];

	g->adjacency_list[3]->next = create_node(0);
	g->adjacency_list[3]->next->next = g->adjacency_list[3];

	g->adjacency_list[4]->next = create_node(1);
	g->adjacency_list[4]->next->next = g->adjacency_list[4];

	return g;
}


void print_linked_list(Node * linked_list, int count){
	Node * l = linked_list;
	
	for (int i = 0; i < count; ++i){
		printf("[+] Node %d\n", l->key);
		l = l->next;
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

	printf("[+] ===== 0th node children =====\n");
	print_linked_list(g->adjacency_list[0], 5);
	printf("[+] ===== 1th node children =====\n");
	print_linked_list(g->adjacency_list[1], 5);
	printf("[+] ===== 2th node children =====\n");
	print_linked_list(g->adjacency_list[2], 5);
	printf("[+] ===== 3th node children =====\n");
	print_linked_list(g->adjacency_list[3], 5);
	printf("[+] ===== 4th node children =====\n");
	print_linked_list(g->adjacency_list[4], 5);
	return 0;
}
