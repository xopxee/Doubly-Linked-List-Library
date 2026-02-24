#include <stdio.h>
#include "doubly_linked_list.h"

int main(){
	
	Dll list;
	init_dll(&list);
	
	for(int i = 1; i <= 10; i++){
		push_dll(&list, i*7);
	}
	
	print_dll(list);
	print_dll_backwards(list);
	
	delete_dll(&list);
	
	print_dll(list);
	
	return 0;
}