/*
*	Harness File
*	Author: Josephine Michalek
*	Student ID: 385809
*	Version: 23 May 2016
*
*	This file drives the solution.
*
*/

#include "graph.h"
#include "node.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
	Graph G;

	//take in number of edges
	scanf("%d", &G.V);

	//initialize state array of size G.V
	G.state = (int *)malloc(sizeof(int) * G.V);

	//initialize edge array of size G.V
	G.edges = malloc(sizeof(struct edgeNode) * G.V);
	for (int i = 0; i < G.V; i++) {
		G.edges[i] = NULL;
	}

	stack s;
	init_stack(&s); //initialize stack s

	//initialize indegree array
	int *indegree;
	indegree = (int *)malloc(sizeof(int)*G.V);
	for (int j = 0; j < G.V; j++) {
		indegree[j] = 0;
	}

	//loop through each vertex 
	for (int i = 0; i < G.V; i++) {

		int state;
		scanf("%d", &state);
		G.state[i] = state;

		int numberOfEdges;
		scanf("%d", &numberOfEdges);

		//loop through each edge
		for (int j = 0; j < numberOfEdges; j++) {

			int toVertex;
			int weight;
			//create new edge node
			EdgeList n = (EdgeList)malloc(sizeof(struct edgeNode));
			scanf("%d,%d", &toVertex, &weight);

			n->edge.toVertex = toVertex;
			n->edge.weight = weight;
			indegree[toVertex]++;

			//the above two lines work
			//printf("%d", n->edge.toVertex);
			//printf("%d", n->edge.weight);

			//insert new node at front of current list
			n->next = G.edges[i];
			G.edges[i] = n;
		}
	}

	//initialize array to keep track of inputs
	int *inputs;
	inputs = (int *)malloc(sizeof(int)*G.V);
	for (int j = 0; j < G.V; j++) {
		inputs[j] = indegree[j];
	}

	//top sort
	int *topsort; //topsort is an array
	topsort = (int *)malloc(sizeof(int)*G.V); //initialize it

	int count = G.V;
	for (int k = 0; k < G.V; k++) { //for each vertex
		if (indegree[k] == 0) { //if the current indegree is 0
			push(s, ((void *)k)); //add it to the top of the stack
		}
	}

	for (int k = 0; k < G.V; k++) { //for each vertex
		int vertex = ((int)top(s)); //get the first value from the stack
		pop(s); //take that value off the top of the stack
		topsort[k] = vertex; //store the value in the topsort list

		//printf("%d ", vertex);

		EdgeList current = G.edges[vertex];

		while (current != NULL) { //while the edge list isnt empty
			indegree[current->edge.toVertex]--; //decrement the indegree
			if (indegree[current->edge.toVertex] == 0) { //if the indgree is now zero
				push(s, ((void *)current->edge.toVertex)); //add the value to the top of the stack
			}
			current = current->next;
		}
		//printf("%d\n", topsort[k]);
	}


	//calculate inputs
	for (int i = 0; i < G.V; i++) { //for each vertex
		int current_vertex = topsort[i]; //set the current vertex from the topological sort
		int input = 0; //make the input 0

		for (int j = 0; j < G.V; j++) { //for each vertex
			int potential_input_vertex = j;
			EdgeList current = G.edges[potential_input_vertex];
			while (current != NULL) { //while the edge list isnt empty
				if (current->edge.toVertex == current_vertex) { //if the to vertex of an edge is the same as the current edge
					input += current->edge.weight * G.state[potential_input_vertex]; //calculate the input for that current vertex
				}
				current = current->next;
			}
		}

		if (inputs[current_vertex] != 0) {
			if (input > 0) {
				G.state[current_vertex] = 1;
			}
			else {
				G.state[current_vertex] = 0;
			}

		}
	}
	for (int i = 0; i < G.V; i++) { // i thought this loop wouldnt be needed but it decided to not work inside the other int i loop so i put it outside
		printf("%d ", G.state[i]);
	}
}


