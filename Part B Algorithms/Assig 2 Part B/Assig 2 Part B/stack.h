/*
*	Stack
*	Author: J.R.Dermoudy
*	Version: May 2015
*
*	This file holds the specification of the Stack.
*
*	This file is complete.
*/

#include <stdbool.h>

struct stack_int;
typedef struct stack_int *stack;

void init_stack(stack *s);
bool isEmptyS(stack s);
void push(stack s, void *i);
void *top(stack s);
void pop(stack s);
