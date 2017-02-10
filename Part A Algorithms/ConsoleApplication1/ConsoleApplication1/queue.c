/*
* Implementation for Queue using linked-list
* Author: Julian Dermoudy
* Version: May 2015
*
* This file is complete.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue.h"

struct queue_int {
	node first;
};

/*
* 'Constructor' for queue
*/
void init_queue(queue *q)
{
	*q = (queue)malloc(sizeof(struct queue_int));
	(*q)->first = NULL;
}

/*
* Check for emptiness
* Return true if queue is empty, false otherwise
*/
bool isEmptyQ(queue q)
{
	return (q->first == NULL);
}

/*
* Find front item in queue
* Return value at front of queue
*/
void *front(queue q)
{
	if (isEmptyQ(q))
	{
		fprintf(stderr, "queue is empty.");
		exit(1);
	}

	return getDataN(q->first);
}

/*
* Remove first item from queue
*/
void rear(queue q)
{
	if (isEmptyQ(q))
	{
		fprintf(stderr, "queue is empty.");
		exit(1);
	}
	else
	{
		q->first = getNextN(q->first);
	}
}

/*
* Add item to rear of queue
* Param o value to be added to rear of queue
*/
void add(queue q, void *o)
{
	node n, c;

	init_node(&n, o);
	if (isEmptyQ(q))
	{
		q->first = n;
	}
	else
	{
		c = q->first;
		while (getNextN(c) != NULL)
		{
			c = getNextN(c);
		}
		setNextN(c, n);
	}
}

/*
* Find printable form of queue
* Return String form of queue for printing etc.
*/
char *toStringQ(queue q, char *f)
{
	node c;
	char *fmt = (char *)malloc(10 * sizeof(char));
	char *s = (char *)malloc(100 * 10 * sizeof(char));

	if (isEmptyQ(q))
	{
		s = "<>";
	}
	else
	{
		s[0] = '\0';
		sprintf(fmt, "%%s%s", f);
		c = q->first;
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
