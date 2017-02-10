/*
*	Queue
*	Author: J.R.Dermoudy
*	Version: May 2015
*
*	This file holds the specification of the Queue.
*
*	This file is complete.
*/

#include <stdbool.h>

struct queue_int;
typedef struct queue_int *queue;

void init_queue(queue *q);
bool isEmptyQ(queue q);
void add(queue q, void *i);
void *front(queue q);
void rear(queue q);
char *toStringQ(queue q, char *f);