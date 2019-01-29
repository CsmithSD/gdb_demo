#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H
#include <iostream>
#include <assert.h>

using namespace std;

struct listNode {
	int data;
	listNode* next;

	listNode ( int d = -1, listNode* n = nullptr ) : data ( d ), next ( n ) {}
};

class linkedList {
	listNode* head;

public:
	linkedList ( listNode* head = nullptr );

	void printList();
	listNode* find ( int d );
	void push_front ( int d );
	void push_back ( int d );
	listNode*  pop_front();
	listNode*  pop_back();
};
#endif
