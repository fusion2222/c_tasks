#include <stdio.h>
#include <stdlib.h>


typedef struct LinkedListNodes {
	int node_id;
	void * next;
} LinkedListNode;


int main(){
	/*
		This program solves Josephus problem using circular list.
		Malloc is salled just once for all nodes, as it is costly operation.

		There can be potentially more memory-efficient variant, where malloc would be called per-node.
		This can be in production-level cases very ineffective overhaul.

		TODO: Make initial constant parametrizable by user.
	*/

	const int TOTAL_NODES = 4;
	const int KILLING_STEPS = 2;  // Specifises how many nodes will he skipped in order to remove one. 
	const int STARTING_POSITION = 0;

	LinkedListNode * data = (LinkedListNode *)malloc(sizeof(LinkedListNode) * TOTAL_NODES);

	int max_index = TOTAL_NODES - 1;

	for (int i = 0; i < max_index; i++){
		/* Initialize our linked list */
		data[i].node_id = i;
		data[i].next = &data[i + 1];
	}

	data[max_index].node_id = max_index;
	data[max_index].next = &data[0];

	LinkedListNode * current_node = &data[STARTING_POSITION];
	LinkedListNode * previous_node = current_node;

	while(current_node != (*current_node).next){

		for(int i = 0; i < KILLING_STEPS; i++){

			current_node = (*current_node).next;

			if(i == KILLING_STEPS - 2){
				previous_node = current_node;
			}else if(i == KILLING_STEPS - 1){
				current_node = current_node;
			}

		}

		// Slaughter that node!
		(*previous_node).next = (*current_node).next;
	}

	printf("The last surviving node is #%d\n", (*current_node).node_id);

	return 0;

}
