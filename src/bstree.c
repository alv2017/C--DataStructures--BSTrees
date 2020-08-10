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

// Smallest Element
struct node *find_smallest(struct node *tree) {
	struct node *ptr;
	ptr = tree;

	if (ptr == NULL || ptr->left == NULL) {
		return ptr;
	} else {
		return find_smallest(tree->left);
	}
	return ptr;
}

// Node with the largest value
struct node *find_largest(struct node *tree) {
	struct node *ptr = tree;
	if (ptr == NULL || ptr->right == NULL) {
		return ptr;
	} else {
		return find_largest(tree->right);
	}
}

// Deleting a node
struct node *delete_node(struct node *subtree, struct node *parent, int value, short *op_status) {
	if (subtree==NULL) {
		printf("The node with the value %d was not found.\n", value);
		*op_status = 0;
		return subtree;
	}
	struct node *ptr = subtree;
	struct node *tmp = NULL;
	if (ptr->data > value) {
		parent = ptr;
		ptr = delete_node(ptr->left, parent, value, op_status);
	}
	else if (ptr->data < value) {
		parent = ptr;
		ptr = delete_node(ptr->right, parent, value, op_status);
	}
	else if (ptr->left && ptr->right) {
		tmp = find_largest(ptr->left);
		ptr->data = tmp->data;
		parent = ptr;
		ptr = delete_node(ptr->left, parent, tmp->data, op_status);
	}
	else {
		if (ptr->left == NULL && ptr->right == NULL) {
			if (parent == NULL) {
				subtree = NULL;
			}
			else if (parent->data >= ptr->data) {
				parent->left = NULL;
			} else {
				parent->right = NULL;
			}
		}
		else if (ptr->left == NULL) {
			if (parent == NULL) {
				subtree = ptr->right;
			}
			else if (parent->data >= ptr->data){
				parent->left = ptr->right;
			} else {
				parent->right = ptr->right;
			}
		}
		else if (ptr->right == NULL) {
			if (parent==NULL) {
				subtree = ptr->left;
			}
			else if (parent->data >= ptr->data){
				parent->left = ptr->left;
			} else {
				parent->right = ptr->left;
			}
		}
		*op_status = 1;
		free(ptr);
	}
	return subtree;
}

// Tree Height
int tree_height(struct node *subtree) {
	if (subtree == NULL) {
		return 0;
	}
	else {
		int leftHeight = tree_height(subtree->left);
		int rightHeight = tree_height(subtree->right);
		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}
}

// Number of nodes
long total_nodes(struct node *subtree) {
	if (subtree == NULL) {
		return 0;
	}
	else {
		return total_nodes(subtree->left) + total_nodes(subtree->right) + 1;
	}
}

// Number of internal nodes
long internal_nodes(struct node *subtree) {
	if (subtree == NULL) {
		return 0;
	}
	else if (subtree->left == NULL && subtree->right == NULL) {
		return 0;
	}
	else {
		return internal_nodes(subtree->left) + internal_nodes(subtree->right) + 1;
	}
}

// Number of external nodes
long external_nodes(struct node *subtree) {
	if (subtree == NULL) {
		return 0;
	}
	else if (subtree->left == NULL && subtree->right == NULL) {
		return 1;
	}
	else {
		return external_nodes(subtree->left) + external_nodes(subtree->right);
	}
}

// Mirror Tree
struct node *mirror_tree(struct node *subtree) {
	struct node *ptr = subtree;
	struct node *tmp = NULL;

	if (ptr != NULL) {
		tmp = ptr->left;
		ptr->left = ptr->right;
		ptr->right = tmp;
		mirror_tree(ptr->left);
		mirror_tree(ptr->right);
	}
	return subtree;
}

// Delete Tree
struct node *delete_tree(struct node *tree) {
	if (tree != NULL) {
		struct node *ptr = tree;
		delete_tree(tree->left);
		delete_tree(tree->right);
		ptr->right = NULL;
		ptr->left = NULL;
		ptr->data = 0;
		free(ptr);
		return NULL;
	} else
		return NULL;
}

