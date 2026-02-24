#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void init_dll(Dll* plist){
	plist->start = NULL;
	plist->end = NULL;
}

void delete_dll(Dll* plist){
	
	if(is_empty(*plist)){
		return;
	}
	
	node* aux;
	
	for(aux = plist->start; aux != NULL; ){
		
		node* deleted = aux;
		aux = aux->next;
		
		free(deleted);
	}
	init_dll(plist);
}

bool is_empty(Dll list){
	return (list.start == NULL)? true : false;
}

void shift_dll(Dll* plist, int data){
	
	node* new = (node*)malloc(sizeof(node));
	
	if(new == NULL){
		perror("Failed to allocate memory!");
		exit(1);
	}
	
	new->data = data;
	
	if(is_empty(*plist)){
		
		
		new->prev = NULL;
		new->next = NULL;
		
		plist->start = new;
		plist->end = new;
		
		return;
	}
	
	new->prev = NULL;
	new->next = plist->start;
	new->next->prev = new;
	plist->start = new;
}

void print_dll(Dll list){
	
	if(is_empty(list)){
		printf("{ empty }\n");
		return;
	}
	
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
	
	printf("{ ");
	for(node* aux = list.end; aux != NULL; aux = aux->prev){
		printf("%d ", aux->data);
	}
	printf("}\n");
}