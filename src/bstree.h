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

// In-order traversal
void inorder_traversal(struct node *);

// Node with the smallest value
struct node *find_smallest(struct node *tree);

// Node with the largest value
struct node *find_largest(struct node *);

// Delete node
struct node *delete_node(struct node *, struct node *, int, short *);

// Tree height
int tree_height(struct node *);

// Number of nodes
long total_nodes(struct node *subtree);


#endif
