#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>
	
typedef struct node node;

struct node{
	node* prev;
	node* next;
	int data;
};

typedef struct{
	node* start;
	node* end;
	
}Dll;

void init_dll(Dll* plist);

void delete_dll(Dll* plist);

bool is_empty(Dll list);

void shift_dll(Dll* plist, int data);

void print_dll(Dll list);

void print_dll_backwards(Dll list);
	
#endif