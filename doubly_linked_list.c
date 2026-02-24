#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void init_dll(Dll* plist){
	
	//Empty list.
	plist->start = NULL;
	plist->end = NULL;
}

void delete_dll(Dll* plist){
	
	//No need to anything.
	if(is_empty(*plist)){
		return;
	}
	
	node* aux;
	
	//Iterates through all nodes 'til it finds the last.
	for(aux = plist->start; aux != NULL; ){
		
		//Stores the address of the current node.
		node* deleted = aux;
		
		//Jumps to the next node before the current gets freed.
		aux = aux->next;
		
		free(deleted);
	}
	//Initializes the list as empty again.
	init_dll(plist);
}

bool is_empty(Dll list){
	return (list.start == NULL)? true : false;
}

void shift_dll(Dll* plist, int data){
	
	//Creates the new node.
	node* new = (node*)malloc(sizeof(node));
	
	if(new == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
	
	//Fills in the data
	new->data = data;
	
	if(is_empty(*plist)){
		
		//There's no previous node nor next.
		new->prev = NULL;
		new->next = NULL;
		
		//new node is the first node and also the last.
		plist->start = new;
		plist->end = new;
		
		return;
	}
	
	new->prev = NULL;			//Since it's the first node, there's no previous.
	new->next = plist->start;	//next now points to the list's head.
	new->next->prev = new;		//The old first node also points to new.
	plist->start = new;			//new is now the head of the list.
}

void push_dll(Dll* plist, int data){
	
	//shift function can handle it identically as push would.
	if(is_empty(*plist)){
		shift_dll(plist, data);
		return;
	}
	
	//Creates the new node.
	node* new = (node*)malloc(sizeof(node));
	
	if(new == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
	
	//Fills in the data.
	new->data = data;
	
	new->next = NULL;			//new is the last node, therefore it has no next
	new->prev = plist->end;		//prev now points to the list's tail.
	new->prev->next = new;		//the old last node also points to new.
	plist->end = new;			//new is now the tail of the list.
}

void print_dll(Dll list){
	
	if(is_empty(list)){
		printf("{ empty }\n");
		return;
	}
	
	//Iterates through all non-null nodes and prints its data.
	printf("{ ");
	for(node* aux = list.start; aux != NULL; aux = aux->next){
		printf("%d ", aux->data);
	}
	printf("}\n");
}

void print_dll_backwards(Dll list){
	
	if(is_empty(list)){
		printf("{ empty }\n");
		return;
	}
	
	//Iterates backwards through all non-null nodes and prints its data.
	printf("{ ");
	for(node* aux = list.end; aux != NULL; aux = aux->prev){
		printf("%d ", aux->data);
	}
	printf("}\n");
}