#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <malloc.h>

struct List {
	struct Node {
		struct Node* next;
		struct Node* prev;
		double data;
	};
	struct Node* start;
	struct Node* end;
	int length;
	double sum;
};
typedef struct List List;
typedef struct Node Node;

List* CreateList();
void DestroyList(List*);
int AddNode(List*, double);
void DeleteNode(List*, Node*);
int GetLength(List*);
Node* GetFirst(List*);
Node* GetLast(List*);
Node* GetNext(Node*);
Node* GetPrev(Node*);
double GetData(Node*);
double GetAverage(List*);


#endif