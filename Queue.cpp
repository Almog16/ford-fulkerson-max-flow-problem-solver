#include "Queue.h"

Queue::Queue() : queueList()
{

}

Queue::~Queue()
{
	this->MakeEmpty();
}

Type Queue::Front() {
	return this->queueList.First()->GetData();
}

void Queue::EnQueue(Type newItem) {
	this->queueList.AddNewItem(newItem);
}

Type Queue::DeQueue() {
	if (this->IsEmpty() == true) {
		printf("Queue is empty. Cannot perform DeQueue action\n");
		return NULL;
	}

	return this->queueList.DeleteHead();
}

bool Queue::IsEmpty() {
	return this->queueList.IsEmpty();
}

void Queue::MakeEmpty() {
	if (this->IsEmpty() == true) {
		return;
	}
	else {
		while (this->IsEmpty() == false) {
			this->DeQueue();
		}
	}
}