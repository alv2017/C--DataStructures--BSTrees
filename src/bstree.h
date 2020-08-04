#ifndef BSTREES_H
#define BSTREES_H

struct node {
	int data;
	struct node *left;
	struct node *right;
};

// Operation Status
short op_status;

// Insert New Node
struct node *insert_node(struct node *, int, short *);

// Pre-order traversal
void preorder_traversal(struct node *);

// Post-order traversal
void postorder_traversal(struct node *);

#endif
