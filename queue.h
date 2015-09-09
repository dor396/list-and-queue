#ifndef QUEUE_H
#define QUEUE_H

//QUEUE OF DOUBLES MODULE

//Queue object
typedef struct Queue Queue;
//Node of queue
typedef struct Node Node;


/************************************************
*create and initializing queue					*
*add function: enter p1+p2 into p1				*
*sub function: enter p1-p2 into p1				*
*div function: return pointer to p1/p2			*
************************************************/
extern Queue* createQueue(void (*add)(void*, void*),
							void (*sub)(void*, void*),
							void* (*div)(void*, void*));

//delete all queue objects
extern void destroyQueue(Queue*);

//add value to the end of queue
extern int addQueueNode(Queue*, void*);

/************************************************
return data of first Node and remove the node.	*
***DONT USE FOR EMPTY QUEUE (length==0)***					*
************************************************/
extern void* popQueue(Queue*);

//return list length
extern int getQueueLength(Queue*);

/************************************************
return data of first Node						*
***DONT USE FOR EMPTY QUEUE (length==0)***					*
************************************************/
extern void* topQueue(Queue*);

#endif