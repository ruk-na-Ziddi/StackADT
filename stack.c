#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack createStack(void){
	LinkedList* list = calloc(sizeof(LinkedList),1);
	Stack stack = {list,&list->tail};
	return stack;
}

int push(Stack stack, void *data){
	Node_ptr node=create_node(data);
	if(node){
		add_to_list(stack.list,node);
		return stack.list->count;
	}
	return -1;
}

void * pop(Stack stack){
	void *poppedData=deleteElementAt(stack.list, stack.list->count-1);
	return poppedData;
}