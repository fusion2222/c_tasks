#include <stdio.h>
#include <stdlib.h>


// Tree node
struct node{
    int value;
    struct node * parent;
    struct node * left_child;
    struct node * right_child;
};
typedef struct node Node;


Node * create_node(int value, Node * parent){
	// Create new Node instance into pointer n.
	Node * n = (Node *)malloc(sizeof(Node));
	n->value = value;
	n->parent = parent;
	n->left_child = NULL;
	n->right_child = NULL;
	return n;
}


void preorder_traversal(Node * n){
	if(n == NULL){
		return;
	}
	printf("%d ", n->value);
	preorder_traversal(n->left_child);
	preorder_traversal(n->right_child);
}


void inorder_traversal(Node * n){
	if(n == NULL){
		return;
	}
	inorder_traversal(n->left_child);
	printf("%d ", n->value);
	inorder_traversal(n->right_child);
}


void postorder_traversal(Node * n){
	if(n == NULL){
		return;
	}
	postorder_traversal(n->left_child);
	postorder_traversal(n->right_child);
	printf("%d ", n->value);
}


int main(int argc, char const *argv[]){
	/*
	 *  BLUEPRINT:
	 *
	 *	      (6)
	 *       /   \
	 *	  (9)     (2)
	 *   /   \   /   \
	 *  (5) (4) (7) (1)
	 */

	// TREE CONSTRUCTION
	Node * tree = create_node(6, NULL);
	
	tree->left_child = create_node(9, tree);
	tree->right_child = create_node(2, tree);

	tree->left_child->left_child = create_node(5, tree->left_child);
	tree->left_child->right_child = create_node(4, tree->left_child);

	tree->right_child->left_child = create_node(7, tree->right_child);
	tree->right_child->right_child = create_node(1, tree->right_child);

	// TRAVERSAL ALGORITHMS
	printf("[+] Pre-Order should be: 6, 9, 5, 4, 2, 7, 1\n");
	printf("[+] Pre-Order tree traversal output:\n");
	printf("[+] ");
	preorder_traversal(tree);
	printf("\n[+] ================================\n");
	printf("[+] Post-Order should be: 5, 4, 9, 7, 1, 2, 6\n");
	printf("[+] Post-Order tree traversal output:\n");
	printf("[+] ");
	postorder_traversal(tree);
	printf("\n[+] ================================\n");
	printf("[+] In-Order should be: 5, 9, 4, 6, 7, 2, 1\n");
	printf("[+] In-Order tree traversal output:\n");
	printf("[+] ");
	inorder_traversal(tree);
	printf("\n\n");
	return 0;
}
