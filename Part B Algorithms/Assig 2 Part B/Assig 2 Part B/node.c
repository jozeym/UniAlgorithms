/*
* Implementation for Node
* Author: Julian Dermoudy
* Version: May 2015
*
* This file is complete.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"


struct node_int {
	void *data;
	node next;
};

/*
* 'Constructor' for node
*/
void init_node(node *n, void *o)
{
	*n = (node)malloc(sizeof(struct node_int));
	(*n)->data = o;
	(*n)->next = NULL;
}

/*
* Getter for data
* Return data field
*/
void *getDataN(node n)
{
	return (n->data);
}

/*
* Getter for next
* Return next field
*/
node getNextN(node n)
{
	return (n->next);
}

/*
* Setter for data
* Param o value to be placed into the node's data field
*/
void setDataN(node n, void *o)
{
	n->data = o;
}

/*
* Setter for next
* Param n value to be placed into the node's next field
*/
void setNextN(node v, node n)
{
	v->next = n;
}

