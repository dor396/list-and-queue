#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <malloc.h>

//QUEUE OF DOUBLES MODULE
struct Queue {
	struct Node {
		struct Node* next;
		double data;
	};
	struct Node* first;
	struct Node** nextInit;
	//count the queue size
	int length;
};
typedef struct Queue Queue;
typedef struct Node Node;

//create and initializing queue
extern Queue* createQueue();

//delete all queue objects
extern void destroyQueue(Queue*);

//add value to the end of queue
extern int addQueueNode(Queue*, double);

/************************************************
return data of first Node and remove the node.	*
***DONT USE FOR EMPTY QUEUE (length==0)***					*
************************************************/
extern double popQueue(Queue*);

//return list length
extern int getQueueLength(Queue*);

/************************************************
return data of first Node						*
***DONT USE FOR EMPTY QUEUE (length==0)***					*
************************************************/
extern double topQueue(Queue*);

#endif