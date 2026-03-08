#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_dll(Dll* plist, Type type){
	
	//Empty list.
	plist->start = NULL;
	plist->end = NULL;
	
	plist->type = type;
	
	//Initializes the list according to the data type.
	switch(type){
		case INTEGER:
			plist->element_size = sizeof(int);
			break;
		
		case FLOAT:
			plist->element_size = sizeof(float);
			break;
			
		case DOUBLE:
			plist->element_size = sizeof(double);
			break;
			
		case CHAR:
			plist->element_size = sizeof(char);
			break;

		case STRING:
			plist->element_size = sizeof(char*);
			break;	
	}
}

void delete_dll(Dll* plist){
	
	//No need to do anything.
	if(is_empty_dll(*plist)){
		return;
	}
	
	dl_node* aux;
	
	//Iterates through all dl_nodes 'til it finds the last.
	for(aux = plist->start; aux != NULL; ){
		
		//Stores the address of the current dl_node.
		dl_node* deleted = aux;
		
		//Jumps to the next dl_node before the current gets freed.
		aux = aux->next;
		
		//Frees the data before freeing the node.
		free(deleted->data);
		free(deleted);
	}
	//Initializes the list as empty again.
	plist->start = NULL;
	plist->end = NULL;
}

bool is_empty_dll(Dll list){
	return (list.start == NULL)? true : false;
}

void shift_dll(Dll* plist, void* data){
	
	//Creates the new dl_node.
	dl_node* new = (dl_node*)malloc(sizeof(dl_node));
	
	if(new == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
	
	//Allocates space in order to store the data.
	new->data = malloc(plist->element_size);
	
	if(new->data == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
	
	//Fills in the data.
	memcpy(new->data, data, plist->element_size);
	
	if(is_empty_dll(*plist)){
		
		//There's no previous dl_node nor next.
		new->prev = NULL;
		new->next = NULL;
		
		//new dl_node is the first dl_node and also the last.
		plist->start = new;
		plist->end = new;
		
		return;
	}
	
	new->prev = NULL;			//Since it's the first dl_node, there's no previous.
	new->next = plist->start;	//next now points to the list's head.
	new->next->prev = new;		//The old first dl_node also points to new.
	plist->start = new;			//new is now the head of the list.
}

void push_dll(Dll* plist, void* data){
	
	//shift function can handle it identically as push would.
	if(is_empty_dll(*plist)){
		shift_dll(plist, data);
		return;
	}
	
	//Creates the new dl_node.
	dl_node* new = (dl_node*)malloc(sizeof(dl_node));
	
	if(new == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
	
	//Allocates space in order to store the data.
	new->data = malloc(plist->element_size);
	
	if(new->data == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
	
	//Fills in the data.
	memcpy(new->data, data, plist->element_size);
	
	new->next = NULL;			//new is the last dl_node, therefore it has no next
	new->prev = plist->end;		//prev now points to the list's tail.
	new->prev->next = new;		//the old last dl_node also points to new.
	
	plist->end = new;			//new is now the tail of the list.
}

void print_dll(Dll list){
	
	if(is_empty_dll(list)){
		printf("{ empty }\n");
		return;
	}
	
	//Iterates through all non-null dl_nodes and prints its data.
	printf("{ ");
	switch(list.type){
		case INTEGER:
			for(dl_node* aux = list.start; aux != NULL; aux = aux->next){
				printf("%d ", *((int*)aux->data));
			}
			break;
		
		case FLOAT:
			for(dl_node* aux = list.start; aux != NULL; aux = aux->next){
				printf("%.3f ", *((float*)aux->data));
			}
			break;
			
		case DOUBLE:
			for(dl_node* aux = list.start; aux != NULL; aux = aux->next){
				printf("%.3lf ", *((double*)aux->data));
			}
			break;
			
		case CHAR:
			for(dl_node* aux = list.start; aux != NULL; aux = aux->next){
				printf("%c ", *((char*)aux->data));
			}
			break;

		case STRING:
			for(dl_node* aux = list.start; aux != NULL; aux = aux->next){
				printf("%s ", (char*)aux->data);
			}
			break;	
	}
	printf("}\n");
}

void print_dll_backwards(Dll list){
	
	if(is_empty_dll(list)){
		printf("{ empty }\n");
		return;
	}
	
	//Iterates backwards through all non-null dl_nodes and prints its data.
	printf("{ ");
	switch(list.type){
		case INTEGER:
			for(dl_node* aux = list.end; aux != NULL; aux = aux->prev){
				printf("%d ", *((int*)aux->data));
			}
			break;
		
		case FLOAT:
			for(dl_node* aux = list.end; aux != NULL; aux = aux->prev){
				printf("%.3f ", *((float*)aux->data));
			}
			break;
			
		case DOUBLE:
			for(dl_node* aux = list.end; aux != NULL; aux = aux->prev){
				printf("%.3lf ", *((double*)aux->data));
			}
			break;
			
		case CHAR:
			for(dl_node* aux = list.end; aux != NULL; aux = aux->prev){
				printf("%c ", *((char*)aux->data));
			}
			break;

		case STRING:
			for(dl_node* aux = list.end; aux != NULL; aux = aux->prev){
				printf("%s ", (char*)aux->data);
			}
			break;	
	}
	printf("}\n");
}