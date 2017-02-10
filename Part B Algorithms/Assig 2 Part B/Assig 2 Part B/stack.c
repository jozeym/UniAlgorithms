/*
* Implementation for Stack using linked-list
* Author: Julian Dermoudy
* Version: May 2015
*
* This file is complete.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"

struct stack_int {
	node tos;
};

/*
* 'Constructor' for stack
*/
void init_stack(stack *s)
{
	*s = (stack)malloc(sizeof(node));
	(*s)->tos = NULL;
}

/*
* Check for emptiness
* Return true if stack is empty, false otherwise
*/
bool isEmptyS(stack s)
{
	return (s->tos == NULL);
}

/*
* Find top item in stack
* Return value at top of stack
*/
void *top(stack s)
{
	if (isEmptyS(s))
	{
		fprintf(stderr, "Stack is empty.");
		exit(1);
	}

	return getDataN(s->tos);
}

/*
* Remove top item from stack
*/
void pop(stack s)
{
	if (isEmptyS(s))
	{
		fprintf(stderr, "Stack is empty.");
		exit(1);
	}
	else {
		s->tos = getNextN(s->tos);
	}
}

/*
* Add item to top of stack
* Param o value to be added to top of stack
*/
void push(stack s, void *o)
{
	node n;

	init_node(&n, o);
	setNextN(n, s->tos);
	s->tos = n;
}

/*
* Find printable form of stack
* Return String form of stack for printing etc.
*/
char *toStringS(stack k, char *f)
{
	node c;
	char *fmt = (char *)malloc(10 * sizeof(char));
	char *s = (char *)malloc(100 * 10 * sizeof(char));

	if (isEmptyS(k))
	{
		s = "<>";
	}
	else
	{
		s[0] = '\0';
		sprintf(fmt, "%%s%s", f);
		c = k->tos;
		while (c != NULL)
		{
			sprintf(s, fmt, s, *(int *)(getDataN(c)));
			if (getNextN(c) != NULL)
			{
				sprintf(s, "%s, ", s);
			}
			c = getNextN(c);
		}
	}
	return s;
}