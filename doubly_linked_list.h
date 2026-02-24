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

//Initializes the list as empty.
void init_dll(Dll* plist);

//Deallocates all of the memory used to store the nodes.
void delete_dll(Dll* plist);

//Checks if the list is empty.
bool is_empty(Dll list);

//Inserts a new node at the start of the list, 
//shifting all the other nodes right.
void shift_dll(Dll* plist, int data);

//Inserts a new node at the end of the list.
void push_dll(Dll* plist, int data);

//Prints all data stored within the nodes.
void print_dll(Dll list);

//Prints data from the last node to the first.
void print_dll_backwards(Dll list);
	
#endif