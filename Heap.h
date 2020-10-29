#include "heapItem.h"
/*
This is an implementation of max heap
HeapItem: (key, data). In this project, data  is the vertex and key is d[vertex]
*/
#define NOT_IN_HEAP -1
class Heap {
private:
	HeapItem* data;									//points to data array
	int* indexArr;									//maps indexArr[HeapItem.data] = its index in the Heap arr
	int maxSize;									//max size of heap
	int heapSize;									//current size of heap
	int allocated;									// 1 if heap allocated memory
	int Left(int node);
	int Right(int node);
	int Parent(int node);
	void FixHeap(int node);

public:
	Heap(int max);									//allocate memory
	Heap(HeapItem A[], int n);						//turn A[] into heap
	~Heap();
	void Build(HeapItem A[], int n);				//turn A[] into heap
	bool IsEmpty();									//checks if heap is empty
	HeapItem DeleteMax();							//deletes the maximal node in Heap and returns its value
	void IncreaseKey(int place, Type Key);			//update heap[place] to newKey
	int getIndex(int u);							//returns the actual heap index of the node in which data = u
};