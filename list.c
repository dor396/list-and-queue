#include "list.h"

List * CreateList() {
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

//list value should be NULL
void DestroyList(List* list) {
	Node* temp;
	while (list->start != NULL) {
		temp = list->start;
		list->start = list->start->next;
		free(temp);
	}
	free(list);
	//list = NULL;
}
//option to add after node
int AddNode(List* list, double value) {
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		return 0;
	}
	temp->next = NULL;
	temp->prev = list->end;
	temp->data = value;
	if (list->start == NULL) {
		list->start = list->end = temp;
	}
	else {
		list->end->next = temp;
		list->end = temp;
	
	}
	list->length++;
	list->sum += value;
	return 1;
}

void DeleteNode(List* list, Node* node) {
	if (node->prev != NULL) {
		node->prev->next = node->next;
	}
	if (node->next != NULL) {
		node->next->prev = node->prev;
	}
	list->length--;
	list->sum -= node->data;
	free(node);
}

int GetLength(List* list) {
	return list->length;

}

Node* GetFirst(List* list) {
	return list->start;
}

Node* GetLast(List* list) {
	return list->end;
}

Node* GetNext(Node* node) {
	return node->next;
}

Node* GetPrev(Node* node) {
	return node->prev;
}

double GetData(Node* node) {
	return node->data;
}

double GetAverage(List* list){
	return list->sum / list->length;
}
