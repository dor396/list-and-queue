#include "queue.h"

Queue* CreateQueue() {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	if (newQueue == NULL) {
		return NULL;
	}
	newQueue->first = NULL;
	newQueue->nextInit = &newQueue->first;
	newQueue->length = 0;
}

void DestroyQueue(Queue* queue) {
	Node* temp;
	while (queue->first != NULL) {
		temp = queue->first;
		queue->first = queue->first->next;
		free(temp);
	}
	free(queue);
	//queue = NULL;
}

int AddNode(Queue* queue, double value) {
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

double pop(Queue* queue) {
	Node* temp;
	double value;
	if (queue->first == NULL) {
		return NULL;
	}
	temp = queue->first;
	queue->first = temp->next;
	if (queue->first == NULL) {
		queue->nextInit = &queue->first;
	}
	value = temp->data;
	free(temp);
	return value;
}

int GetLength(Queue* queue) {
	return queue->length;
}
double top(Queue* queue) {
	if (queue->first == NULL) {
		return NULL;
	}
	return queue->first->data;
}