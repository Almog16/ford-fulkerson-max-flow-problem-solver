#include "Node.h"

Node::Node(Type data, Node* nextPtr)
{
	this->data = data;
	next = nextPtr;
}

Node::~Node() {
	
}

void Node::InsertAfter(Node* newNode)	//insert a Node so that it becomes this->next
{
	newNode->next = this->next;
	next = newNode;
}

//Getters:
Type Node::GetData() 
{
	return this->data;
}

Node* Node::GetNext()
{
	return this->next;
}