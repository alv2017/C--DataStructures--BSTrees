#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"
#include "src/bstree.h"

#define clear() printf("\033[H\033[J")

const char *menu[] = {
		" 1. Insert new element.",
		" 2. Pre-order traversal.",
		" 3. Post-order traversal.",
		" 4. In-order traversal.",
		" 5. Find the smallest element.",
		" 6. Find the largest element.",
		" 7. Delete tree node.",
		" 8. Count nodes.",
		" 9. Count internal nodes.",
		"10. Count external nodes.",
		"11. Determine height.",
		"12. Print tree root node.",
		"13. Find the mirror image.",
		"14. Delete tree.",
		"15. Exit.",
		NULL
};

int main(void) {
	op_status = 0;
	// Tree
	struct node *tree = NULL;

	// Menu
	short opt;
	const short MINOPT = 1;
	const short MAXOPT = get_menu_length(menu);
	clear();
	display_menu(menu);

	opt = select_option(MINOPT, MAXOPT);

	while (1) {
		printf("You have selected: %d\n", opt);
		switch (opt) {
			case 1:
				clear();
				printf("Inserting a new element.\n");
				int new_node_value = enter_value();
				tree = insert_node(tree, new_node_value, &op_status);
				if (op_status == 1) {
					puts("New node has been inserted successfully!");
				}
				break;

			case 2:
				clear();
				puts("Pre-order traversal:");
				if (tree==NULL) {
					puts("The tree is empty.");
				}
				else {
					preorder_traversal(tree);
				}
				break;

			case 3:
				clear();
				puts("Post-order traversal.");
				if (tree == NULL) {
					puts("The tree is empty.");
				}
				else {
				    postorder_traversal(tree);
				}
				break;

			case 4:
				clear();
				puts("In-order traversal.");
				if (tree == NULL) {
					puts("The tree is empty.");
				}
				else {
				    inorder_traversal(tree);
				}
				break;

			case 5:
				clear();
				printf("Find the smallest element.\n");
				struct node *smallest = find_smallest(tree);
				if (smallest != NULL) {
					printf("Smallest node value: %d.\n", smallest->data);
				} else {
					puts("The tree is empty.\n");
				}
				break;

			case 6:
				clear();
				printf("Find the largest element.\n");
				struct node *largest = find_largest(tree);
				if (largest != NULL) {
					printf("The largest element value: %d.\n", largest->data);
				} else {
					puts("The tree is empty.");
				}
				break;

			case 7:
				clear();
				puts("Deleting a node.");
				puts("First you need to enter the value of the node you want to delete");
				int delete_value = enter_value();
				tree = delete_node(tree, NULL, delete_value, &op_status);
				if ( op_status == 1) {
					printf("Node with the value %d has been deleted.\n", delete_value);
				}
				break;

			case 8:
				clear();
				printf("Count tree nodes.\n");
				break;

			case 9:
				clear();
				printf("Count tree internal nodes.\n");
				break;

			case 10:
				clear();
				printf("Count tree external nodes.\n");
				break;


			case 11:
				clear();
				puts("Determining the tree height.");
				int bst_height = tree_height(tree);
				printf("Tree height: %d.\n", bst_height);
				break;

			case 12:
				clear();
				printf("Print tree root node.\n");
				if (tree == NULL) {
					puts("The tree is empty.");
				} else {
					printf("Root node: %d.\n", tree->data);
				}
				break;

			case 13:
				clear();
				printf("Find the mirror image.\n");
				break;

			case 14:
				clear();
				printf("Delete tree.\n");
				break;

			case 15:
				clear();
				printf("Exit.\n");
				return 0;
		}
		// Asking user for further actions;
		display_menu(menu);
		opt = select_option(MINOPT, MAXOPT);
	}
	return 0;
}
