#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <malloc.h>

//LIST OF DOUBLES MODULE

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

/************************************************
*create and initializing list					*
*Rerturn NULL if memory allocation failed		*
*else, return ptr to List (should be free)		*
************************************************/
extern List* createList();

//delete all list objects
extern void destroyList(List*);

/************************************************
*add Node before the Node sent					*
*if Node* ptr is NULL - add Node to the end of	*
list											*
*Rerturn 0 if memory allocation failed			*
*else return 1									*
************************************************/
extern int addListNode(List*, double, Node*);

//delete Node from list
extern void deleteListNode(List*, Node*);

//return list length
extern int getListLength(List*);

//return ptr to list start
extern Node* getListFirst(List*);

//return ptr to list end
extern Node* getListLast(List*);

//return ptr to next object
extern Node* getListNext(Node*);

//return ptr to prev object
extern Node* getListPrev(Node*);

//return Node data
extern double getListData(Node*);

//return list average
extern double getListAverage(List*);
#endif