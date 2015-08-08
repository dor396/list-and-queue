#include "queue.h"

/************************************************
*create and initializing queue					*
*Rerturn NULL if memory allocation failed		*
*else, return ptr to Queue (should be free)		*
************************************************/
extern Queue* createQueue() {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	if (newQueue == NULL) {
		return NULL;
	}
	newQueue->first = NULL;
	newQueue->nextInit = &newQueue->first;
	newQueue->length = 0;
	return newQueue;
}

//delete all queue objects
extern void destroyQueue(Queue* queue) {
	Node* temp;
	while (queue->first != NULL) {
		temp = queue->first;
		queue->first = queue->first->next;
		free(temp);
	}
}

/************************************************
*add value to the end of queue					*
*Rerturn 0 if memory allocation failed			*
*else, return 1									*
************************************************/
extern int addNode(Queue* queue, double value) {
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		return 0;
	}
	temp->data = value;
	temp->next = NULL;
	*queue->nextInit = temp;
	queue->nextInit = &temp->next;
	return 1;
}

/************************************************
return data of first Node and remove the node.	*
***DONT USE FOR EMPTY QUEUE***					*
************************************************/
extern double pop(Queue* queue) {
	Node* temp;
	double value;
	temp = queue->first;
	queue->first = temp->next;
	if (queue->first == NULL) {
		queue->nextInit = &queue->first;
	}
	value = temp->data;
	free(temp);
	return value;
}

//return list length
extern int getLength(Queue* queue) {
	return queue->length;
}

/************************************************
return data of first Node						*
***DONT USE FOR EMPTY QUEUE***					*
************************************************/
extern double top(Queue* queue) {
	return queue->first->data;
}