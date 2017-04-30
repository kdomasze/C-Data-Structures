#include <stdlib.h>
#include "binarysearchtree.h"

BinarySearchTree* kd_binary_search_tree_new()
{
	BinarySearchTree* bst = malloc(sizeof(BinarySearchTree));

	(*bst).head = NULL;

	return bst;	
}

BST_Node* kd_binary_search_tree_node_new(int value)
{
	BST_Node* node = malloc(sizeof(BST_Node));

	(*node).value = value;
	(*node).left = NULL;
	(*node).right = NULL;
	
	return node;
}

void kd_binary_search_tree_free(BinarySearchTree* bst)
{
	(*bst).head = _kd_binary_search_tree_node_free_all((*bst).head);
	
	free(bst);
}

BST_Node* _kd_binary_search_tree_node_free_all(BST_Node* node)
{
	if(node == NULL)
	{
		return node;
	}
	
	if((*node).left != NULL)
	{
		(*node).left = _kd_binary_search_tree_node_free_all((*node).left);
	}

	if((*node).right != NULL)
	{
		(*node).right = _kd_binary_search_tree_node_free_all((*node).right);
	}

	kd_binary_search_tree_node_free(node);

	return NULL;
}

void kd_binary_search_tree_node_free(BST_Node* node)
{
	free(node);
}

void kd_binary_search_tree_insert(BinarySearchTree* bst, int value)
{
	(*bst).head = _kd_binary_search_tree_node_insert((*bst).head, value);
}

BST_Node* _kd_binary_search_tree_node_insert(BST_Node* node, int value)
{
	if(node == NULL)
	{
		return kd_binary_search_tree_node_new(value);
	}
	else
	{
		if(value < (*node).value)
		{
			(*node).left = _kd_binary_search_tree_node_insert((*node).left, value);
		}
		else if(value > (*node).value)
		{
			(*node).right = _kd_binary_search_tree_node_insert((*node).right, value);
		}
	}

	return node;
}

int kd_binary_search_tree_lookup(BinarySearchTree* bst, int value)
{
	return _kd_binary_search_tree_node_lookup((*bst).head, value);
}

int _kd_binary_search_tree_node_lookup(BST_Node* node, int value)
{
	if(node == NULL)
	{
		return 0;
	}

	if((*node).value == value)
	{
		return 1;
	}
	else if(value < (*node).value)
	{
		return _kd_binary_search_tree_node_lookup((*node).left, value);
	}
	else if(value > (*node).value)
	{
		return _kd_binary_search_tree_node_lookup((*node).right, value);
	}

	return 1;
}

void kd_binary_search_tree_remove(BinarySearchTree* bst, int value)
{
	(*bst).head = _kd_binary_search_tree_node_remove((*bst).head, value);	
}

BST_Node* _kd_binary_search_tree_node_remove(BST_Node* node, int value)
{
	if(node == NULL)
	{
		return node;
	}
	
	if(value < (*node).value)
	{
		(*node).left = _kd_binary_search_tree_node_remove((*node).left, value);
	}
	else if(value > (*node).value)
	{
		(*node).right = _kd_binary_search_tree_node_remove((*node).right, value);
	}
	else if((*node).value == value)
	{
		if((*node).left == NULL && (*node).right == NULL)
		{
			kd_binary_search_tree_node_free(node);
			node = NULL;
		}
		else if((*node).left != NULL && (*node).right == NULL)
		{
			BST_Node* tmp_node = (*node).left;

			kd_binary_search_tree_node_free(node);

			node = tmp_node;
		}
		else if((*node).left == NULL && (*node).right != NULL)
		{
			BST_Node* tmp_node = (*node).right;

			kd_binary_search_tree_node_free(node);

			node = tmp_node;
		}
		else
		{
			BST_Node* tmp_left_most = _kd_binary_search_tree_node_get_left_most(node);
			
			(*node).value = (*tmp_left_most).value;

			(*node).left = _kd_binary_search_tree_node_remove((*node).left, (*node).value);
		}
	}

	return node;
}

BST_Node* _kd_binary_search_tree_node_get_left_most(BST_Node* node)
{
	if((*node).left == NULL)
	{
		return node;
	}
	
	return _kd_binary_search_tree_node_get_left_most((*node).left);
}
