#include "expr_assert.h"
#include "stack.h"
#include <stdio.h>

void test_creatStack_cretes_a_stack_and_sets_its_top_to_NULL(){
	Stack stack = createStack();
	assertEqual(*(int *)stack.top,0);
}

void test_push_pushes_an_element_in_the_stack(){
	int data=5;
	Stack stack = createStack();
	assertEqual(push(stack,&data), 1);
	assertEqual(*(int*)(stack.list->tail->data),5);
	assertEqual(*((int *)(*stack.top)->data),5);
}

void test_pop_removes_the_current_top_of_stack_and_sets_previous_member_as_top(){
	int first_node_data=5,second_node_data =10;
	Stack stack = createStack();
	push(stack,&first_node_data);
	push(stack,&second_node_data);
	assertEqual(*((int *)pop(stack)), second_node_data);
	assertEqual(*(int*)(stack.list->tail->data),5);
	assertEqual(*((int *)(*stack.top)->data),5);
}