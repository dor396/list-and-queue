#include "queue.h"
#include "list.h"
//Queue By list
struct Queue {
	List* queue;
};
/************************************************
*create and initializing queue					*
*Rerturn NULL if memory allocation failed		*
*else, return ptr to Queue (should be free)		*
************************************************/
extern Queue* createQueue() {
	//Create new queue 
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	if (newQueue == NULL) {
		return NULL;
	}
	//init internal list
	newQueue->queue = createList();
	if (newQueue->queue == NULL) {
		//if init failed - free allocated memory and return NULL
		free(newQueue);
		return NULL;
	}
	return newQueue;
}

//delete internal list and then the queue object
extern void destroyQueue(Queue* queue) {
	destroyList(queue->queue);
	free(queue);
}

/************************************************
*add value to the end of list					*
*Rerturn 0 if memory allocation failed			*
*else, return 1									*
************************************************/
extern int addQueueNode(Queue* queue, double value) {
	//Add Queue Node to the end of internal list
	return addListNode(queue->queue, value, NULL);
}

/************************************************
return data of first Node and remove the node.	*
***CHECK FOR LENGTH!=0 BEFORE USING***					*
************************************************/
extern double popQueue(Queue* queue) {
	Node* tempN = getListFirst(queue->queue);
	double tempV = getNodeData(tempN);
	deleteListNode(queue->queue, tempN);
	return tempV;
}

//return list length
extern int getQueueLength(Queue* queue) {
	return getListLength(queue->queue);
}

/************************************************
return data of first Node						*
***DONT USE FOR EMPTY QUEUE***					*
************************************************/
extern double topQueue(Queue* queue) {
	return getNodeData(getListFirst(queue->queue));
}