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
		" 7. Delete element.",
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
				printf("Pre-order traversal:\n");
				preorder_traversal(tree);
				break;

			case 3:
				clear();
				printf("Post-order traversal.\n");
				break;

			case 4:
				clear();
				printf("In-order traversal.\n");
				break;

			case 5:
				clear();
				printf("Find the smallest element.\n");
				break;

			case 6:
				clear();
				printf("Find the largest element.\n");
				break;

			case 7:
				clear();
				printf("Delete an element.\n");
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
				printf("Determine tree height.\n");
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