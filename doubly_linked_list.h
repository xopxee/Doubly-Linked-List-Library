#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>

//dl as in double linked
typedef struct dl_node dl_node;

struct dl_node{
	dl_node* prev;
	dl_node* next;
	int data;
};

typedef struct{
	dl_node* start;
	dl_node* end;
	
}Dll;

//Initializes the list as empty.
void init_dll(Dll* plist);

//Deallocates all of the memory used to store the dl_nodes.
void delete_dll(Dll* plist);

//Checks if the list is empty.
bool is_empty_dll(Dll list);

//Inserts a new dl_node at the start of the list, 
//shifting all the other dl_nodes right.
void shift_dll(Dll* plist, int data);

//Inserts a new dl_node at the end of the list.
void push_dll(Dll* plist, int data);

//Prints all data stored within the dl_nodes.
void print_dll(Dll list);

//Prints data from the last dl_node to the first.
void print_dll_backwards(Dll list);
	
#endif