#ifndef BST_H
#define BST_H

struct Bst_node_t;
struct Bst_t;

typedef struct Bst_Node_t
{
	int value;
	struct Bst_Node_t* left;
	struct Bst_Node_t* right;
} BST_Node;

typedef struct Bst_t
{
	struct Bst_Node_t* head;
} BinarySearchTree;

/*
 * creates a new binary search tree
 */
BinarySearchTree* kd_binary_search_tree_new();

/*
 * creates a new node for the bst with the given value
 */
BST_Node* kd_binary_search_tree_node_new(int value);

/*
 * frees the given binary search tree from memory
 */
void kd_binary_search_tree_free(BinarySearchTree* bst);

/*
 * private function that frees every node in the given bst
 */
BST_Node* _kd_binary_search_tree_node_free_all(BST_Node* node);

/*
 * frees the given node from memory
 */
void kd_binary_search_tree_node_free(BST_Node* node);

/*
 * inserts a given value into a given bst
 */
void kd_binary_search_tree_insert(BinarySearchTree* bst, int value);

/*
 * private function that recursively inserts the given value into
 * the given bst
 */
BST_Node* _kd_binary_search_tree_node_insert(BST_Node* node, int value);

/*
 * checks if the given value is in the given bst. Will return
 * 1 for true and 0 for false
 */
int kd_binary_search_tree_lookup(BinarySearchTree* bst, int value);

/*
 * private function that searches recursively for the given value
 * in the given bst
 */
int _kd_binary_search_tree_node_lookup(BST_Node* node, int value);

/*
 * removes the given value from the given bst
 */
void kd_binary_search_tree_remove(BinarySearchTree* bst, int value);

/*
 * private function that removes recursively the given value
 * from the given bst
 */
BST_Node* _kd_binary_search_tree_node_remove(BST_Node* node, int value);

/*
 * private function that finds the left most node starting from the 
 * given node
 */
BST_Node* _kd_binary_search_tree_node_get_left_most(BST_Node* node);

#endif
