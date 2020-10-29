/*
This class is an implementation of the LinkedList
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
typedef int Type;

class LinkedList
{
private:
	Node *head, *tail;
	int Length;

public:
	LinkedList();
	~LinkedList();
	void AddNewItem(Type data);									//add a new element to the end of the list
	void InsertAfter(Type itemToInsertAfter, Type newData);		//add a new item after an existing item
	Type DeleteHead();											//delete this->head
	Node* Find(Type data);										//find (data) in the list
	bool IsEmpty();												//check if the list is empty
	Node* Last();												//return the linked list's tail
	Node* First();												//return the linked list's head
	int GetLength();											//get the list's length
	void printList(int toAdd = 0);
};

#endif // !LINKEDLIST_H
