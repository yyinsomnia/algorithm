#include "y_common.h"
#include "y_stack_array.h"

#define YEmptyTOS (-1) // when empty, top of stack
#define YMinStackSize (5)

struct YStackRecord
{
	int capacity;
	int top;
	YElementType *arData; // imitate zend..
}

int 
y_stack_is_empty(YStack stack)
{
	return stack->top == YEmptyTOS;
}

int 
y_stack_is_full(YStack stack)
{
	return stack->top == stack->capacity - 1;
}

YStack 
y_stack_create(int max_elements)
{
	YStack stack;
	
	if (max_elements < YMinStackSize) {
		y_error("Stack size is too small");
	}
	
	stack = malloc(sizeof(struct YStackRecord));
	if (stack == NULL) {
		y_fatal_error("Out of space!!");
	}
	s->arData = malloc(sizeof(YElementType) * max_elements);
	if (s->arData == NULL) {
		y_fatal_error("Out of space!!");
	}
	s->capacity = max_elements;
	y_stack_make_empty(stack);
	return stack;
}

void 
y_stack_make_empty(YStack stack)
{
	s->top = YEmptyTOS;
}

void 
y_stack_dispose(YStack stack)
{
	if (s != NULL) {
		free(s->arData);
		free(s);
	}
}

void y_stack_push(YElementType data, YStack stack)
{
	if (y_stack_is_full(stack)) {
		y_error("Full stack");
	} else {
		s->arData[++s->top] = data; // be careful
	}
}

YElementType
y_stack_top(YStack stack)
{
	if (y_stack_is_empty(stack)) {
		y_error("Empty stack");
	} else {
		return s->arData[s->top];
	}
}

void 
y_stack_pop(YStack stack)
{
	if (y_stack_is_empty(stack)) {
		y_error("Empty stack");
	} else {
		return s->top--;
	}
}

YElementType 
y_stack_top_pop(YStack stack)
{
	if (y_stack_is_empty(stack)) {
		y_error("Empty stack");
	} else {
		return s->arData[s->top--];;
	}
}