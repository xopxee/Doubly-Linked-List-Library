#include <stdio.h>
#include "doubly_linked_list.h"

int main(){
	
	Dll list;
	init_dll(&list, CHAR);
	
	for(char c = 'a'; c <= 'z'; c++){
		push_dll(&list, &c);
	}
	
	print_dll(list);
	print_dll_backwards(list);
	
	delete_dll(&list);
	
	print_dll(list);
	
	return 0;
}