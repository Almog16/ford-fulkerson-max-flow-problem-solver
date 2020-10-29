/*
This class is an implementation of the Queue ADT(FIFO), based on a linked list.
*/

#ifndef  QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <iostream>

class Queue
{
private:
	LinkedList queueList;

public:
	Queue();
	~Queue();
	void MakeEmpty();				//create an empty Queue
	bool IsEmpty();					//check if the Queue is empty
	void EnQueue(Type newItem);		//add an item to the end of the Queue
	Type DeQueue();					//remove an item from the head of the Queue
	Type Front();					//return the oldest item in the queue
};

#endif //QUEUE_H