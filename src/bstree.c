#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

struct node *insert_node(struct node *tree, int val, short *op_status) {
	*op_status = 0;
	struct node *ptr, *nodeptr, *parentptr;

	ptr = (struct node *) malloc(sizeof(struct node));
	if (ptr == NULL) {
		puts("Unable to create a new node. Memory allocation error.");
		return tree;
	}

	*op_status = 1;
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;

	if (tree == NULL) {
		tree = ptr;
		return tree;
	}

	parentptr = NULL;
	nodeptr = tree;

	while(nodeptr != NULL) {
		parentptr = nodeptr;
		if (val < nodeptr->data) {
			nodeptr = nodeptr->left;
		} else {
			nodeptr = nodeptr->right;
		}
	}
	if (val < parentptr->data) {
		parentptr->left = ptr;
	} else {
		parentptr->right = ptr;
	}
	return tree;
}

// Pre-order traversal
void preorder_traversal(struct node *tree) {
	struct node *ptr = tree;
	if (ptr != NULL) {
		printf("%d ", ptr->data);
		preorder_traversal(ptr->left);
		preorder_traversal(ptr->right);
	}
}

// Post-order traversal
void postorder_traversal(struct node *tree) {
	struct node *ptr = tree;
	if (ptr != NULL) {
		postorder_traversal(ptr->left);
		postorder_traversal(ptr->right);
		printf("%d ", ptr->data);
	}
}

// In-order traversal
void inorder_traversal(struct node *tree) {
	struct node *ptr = tree;
	if (ptr != NULL) {
		inorder_traversal(ptr->left);
		printf("%d ", ptr->data);
		inorder_traversal(ptr->right);
	}
}

// Node with the largest value
struct node *find_largest(struct node *tree) {
	struct node *ptr = tree;
	if (ptr == NULL | ptr->right == NULL) {
		return ptr;
	} else {
		return find_largest(tree->right);
	}
}







