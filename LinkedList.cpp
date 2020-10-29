#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->Length = 0;
}

LinkedList::~LinkedList()
{
	Node* currentNode = this->head;
	Node* nextNode = nullptr;

	while (currentNode != nullptr)
	{
		nextNode = currentNode->GetNext();
		delete currentNode;
		currentNode = nextNode;
		Length--;
	}
}

Node* LinkedList::Find(Type data) {
	Node* currentNode = this->head;

	for (int i = 0; i < this->Length || currentNode == nullptr; i++)
	{
		if (currentNode->GetData() == data)
		{
			return currentNode;
		}
		else
		{
			currentNode = currentNode->GetNext();
		}
	}

	return nullptr;
}

void LinkedList::InsertAfter(Type itemToInsertAfter, Type newData)
{	// add a new node so that the list looks like this:
	// ... ---> nodeToInsertAfter ---> newNode ---> nodeToInsertAfter.next ---> ...
	Node* nodeToInsertAfter = Find(itemToInsertAfter);

	if (nodeToInsertAfter == nullptr) {
		printf("Couldn't find a node with the given data, and hence a new Node wasn't created.\nPlease try again.");
	}

	Node* newNode = new Node(newData, nodeToInsertAfter->GetNext());
	nodeToInsertAfter->InsertAfter(newNode);
	this->Length++;
}

void LinkedList::AddNewItem(Type data) {
	Node* newNode = new Node(data);
	if (this->IsEmpty() == true) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		this->tail->InsertAfter(newNode);
		this->tail = newNode;
	}
	this->Length++;
}

bool LinkedList::IsEmpty()
{
	return this->Length == 0;
}

Type LinkedList::DeleteHead()
{
	if (this->IsEmpty() == true) {
		printf("List is empty. Cannot delete its head Node.\n");
		return NULL;
	}

	Type data = this->head->GetData();
	Node* newHead = this->head->GetNext();
	delete this->head;
	this->head = newHead;
	this->Length--;
	return data;
}

//Getters
Node* LinkedList::Last() {
	return this->tail;
}

Node* LinkedList::First() {
	return this->head;
}

int LinkedList::GetLength() {
	return this->Length;
}

void LinkedList::printList(int toAdd) {
	Node* currentNode = this->head;
	while (currentNode != nullptr) {
		printf("%d",currentNode->GetData()+toAdd);
		currentNode = currentNode->GetNext();
		if (currentNode != nullptr) {
			printf(", ");
		}
		else {
			printf(". ");
		}
	}
}