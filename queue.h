#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <malloc.h>

struct Queue {
	struct Node {
		struct Node* next;
		double data;
	};
	struct Node* first;
	struct Node** nextInit;
	int length;
};
typedef struct Queue Queue;
typedef struct Node Node;
Queue* CreateQueue();
void DestroyQueue(Queue*);
int AddNode(Queue*, double);
double pop(Queue*);
int GetLength(Queue*);
double top(Queue*);

#endif