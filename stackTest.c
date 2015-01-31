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
	assertEqual(*(int *)(stack.list->tail->data),5);
	assertEqual(*((int *)(*stack.top)->data),5);
}

void test_push_pushes_an_char_element_in_the_stack(){
	char data='a';
	Stack stack = createStack();
	assertEqual(push(stack,&data), 1);
	assertEqual(*(char *)(stack.list->tail->data), 'a');
	assertEqual(*((char *)(*stack.top)->data), 'a');
}

void test_push_pushes_two_element_in_the_stack(){
	int first_node_data=5,second_node_data=10;
	Stack stack = createStack();
	assertEqual(push(stack,&first_node_data), 1);
	assertEqual(push(stack,&second_node_data), 2);
	assertEqual(*(int *)(stack.list->tail->data),10);
	assertEqual(*((int *)(*stack.top)->data),10);
}

void test_push_pushes_two_char_element_in_the_stack(){
	char first_node_data='a',second_node_data='b';
	Stack stack = createStack();
	assertEqual(push(stack,&first_node_data), 1);
	assertEqual(push(stack,&second_node_data), 2);
	assertEqual(*(char *)(stack.list->tail->data), 'b');
	assertEqual(*((char *)(*stack.top)->data), 'b');
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

void test_pop_removes_the_current_top_of_stack_and_sets_previous_member_as_top_for_character_data(){
	char first_node_data='a',second_node_data ='b';
	Stack stack = createStack();
	push(stack,&first_node_data);
	push(stack,&second_node_data);
	assertEqual(*((char *)pop(stack)), second_node_data);
	assertEqual(*(char *)(stack.list->tail->data),'a');
	assertEqual(*((char *)(*stack.top)->data),'a');
}