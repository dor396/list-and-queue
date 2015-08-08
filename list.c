#include "list.h"

/************************************************
*create and initializing list					*
*Rerturn NULL if memory allocation failed		*
*else, return ptr to List (should be free)		*
************************************************/
extern List * createList() {
	List* newList;
	newList = (List*)malloc(sizeof(List));
	if (newList == NULL) {
		return NULL;
	}
	newList->start = NULL;
	newList->end = NULL;
	newList->length = 0;
	newList->sum = 0;
	return newList;
}

//delete all list objects
extern void destroyList(List* list) {
	Node* temp;
	while (list->start != NULL) {
		temp = list->start;
		list->start = list->start->next;
		free(temp);
	}
	free(list);
}

/************************************************
*add Node before the Node sent					*
*if Node* ptr is NULL - add Node to the end of	*
list											*
*Rerturn 0 if memory allocation failed			*
*else return 1									*
************************************************/
extern int addListNode(List* list, double value,Node* beforeNode) {
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		return 0;
	}
	temp->next = beforeNode;
	temp->data = value;
	if (beforeNode == NULL) {
		temp->prev = list->end;
		list->end->next = beforeNode;
		list->end = beforeNode;
	}
	else if (beforeNode->prev==NULL){
		temp->prev = beforeNode->prev;
		beforeNode->prev = temp;
	}
	else {
		temp->prev = beforeNode->prev;
		beforeNode->prev->next = temp;
		beforeNode->prev = temp;
	}
	if (list->start == NULL) {
		list->start = list->end;
	}
	list->length++;
	list->sum += value;
	return 1;
}

//delete Node from list
extern void deleteListNode(List* list, Node* node) {
	if (node->prev != NULL) {
		node->prev->next = node->next;
	}
	else {
		list->start = node->next;
	}
	if (node->next != NULL) {
		node->next->prev = node->prev;
	}
	else {
		list->end = node->prev;
	}
	list->length--;
	list->sum -= node->data;
	free(node);
}

//return list length
extern int getListLength(List* list) {
	return list->length;

}

//return ptr to list start
extern Node* getListFirst(List* list) {
	return list->start;
}

//return ptr to list end
extern Node* getListLast(List* list) {
	return list->end;
}

//return ptr to next object
extern Node* getListNext(Node* node) {
	return node->next;
}

//return ptr to prev object
extern Node* getListPrev(Node* node) {
	return node->prev;
}

//return Node data
extern double getListData(Node* node) {
	return node->data;
}

//return list average
extern double getListAverage(List* list){
	return list->sum / list->length;
}
