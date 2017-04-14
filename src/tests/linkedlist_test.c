#include "../structures/linkedlist.h"

void dummytest()
{
	linkedlist_t* ll = newlinkedlist();

	insert(ll, 7, 55);

	printAll(ll);

	append(ll, 1);
	append(ll, 2);
	append(ll, 3);
	append(ll, 4);	
	append(ll, 5);
	append(ll, 6);

	printAll(ll);

	insert(ll, 3, 10);

	printAll(ll);

	insert(ll, 20, 111);

	printAll(ll);
}