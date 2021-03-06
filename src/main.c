#include "./tests/linkedlist_test.h"
#include "./tests/map_test.h"
#include "./tests/binarysearchtree_test.h"
#include "./tests/stack_test.h"
#include "./tests/queue_test.h"

int main()
{
	test_linked_list();
	test_map();
	test_binary_search_tree();
	test_stack();
	test_queue();
	return 0;
}
