#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************
 *	GRAPH CODE  *
 ****************/

struct graph{
    int size;  // amount of vertices.
    int * vertices;
    int ** adjacency_matrix;
};
typedef struct graph Graph;


void create_edge(int ** adjacency_matrix, int first_vertice, int second_vertice){
	// Creates edge in both sides because we dont have directed graph.
	adjacency_matrix[first_vertice][second_vertice] = 1;
	adjacency_matrix[second_vertice][first_vertice] = 1; 
}


Graph * initialize_graph(){
	Graph * g = (Graph *)malloc(sizeof(Graph));
	g->size = 10;
	g->vertices = (int *)malloc(sizeof(int) * g->size);
	g->adjacency_matrix = (int **)malloc(sizeof(int *) * g->size);

	for(int i = 0; i < g->size; ++i){
		g->adjacency_matrix[i] = (int *)malloc(sizeof(int) * g->size);
		// Initialize matrix with zeroes.
		for (int x = 0; x < g->size; ++x){
			g->adjacency_matrix[i][x] = 0;
		}
	}

	create_edge(g->adjacency_matrix, 0, 1);
	create_edge(g->adjacency_matrix, 0, 2);
	create_edge(g->adjacency_matrix, 0, 3);
	create_edge(g->adjacency_matrix, 1, 2);
	create_edge(g->adjacency_matrix, 1, 4);
	return g;
}

/******************
 *	PROGRAM CODE  *
 ******************/

int main(int argc, char const *argv[]){
	/*
		Example Graph:

			(0)
		 /   |   \
	   (1)--(2)  (3) 
        |
	   (4)

	*/

	Graph * g = initialize_graph();
	printf("[+] Edge between vertice 0 and 2: %d\n", g->adjacency_matrix[0][2]);
	return 0;
}
