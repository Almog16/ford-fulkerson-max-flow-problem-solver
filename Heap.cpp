#include "Heap.h"
#include <iostream>

void Swap(HeapItem& item1, HeapItem& item2) {
	HeapItem temp = item1;
	item1 = item2;
	item2 = temp;
}

Heap::Heap(int max) {
	data = new HeapItem[max];
	indexArr = new int[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
	for (int i = 0; i < max; i++) {		// initialize indexArr
		indexArr[i] = NOT_IN_HEAP;
	}
}

Heap::Heap(HeapItem A[], int n) {
	this->Build(A, n);
}

Heap::~Heap() {
	if (this->allocated == 1) {
		delete[] data;
	}
	data = nullptr;
	delete[] indexArr;
	indexArr = nullptr;
}

int Heap::Parent(int nodeIndex) { //the Heap index of the parent of node
	return (nodeIndex - 1) / 2;
}

int Heap::Left(int nodeIndex) {
	return (2 * nodeIndex + 1);
}

int Heap::Right(int nodeIndex) {
	return (2 * nodeIndex + 2);
}

void Heap::FixHeap(int nodeIndex) {
	int max;
	int leftIndex = Left(nodeIndex);			//actual Heap index of left & right
	int rightIndex = Right(nodeIndex);

	//find the (Heap) index of the maximal node, among node, left and right
	if ((leftIndex < heapSize) && (data[leftIndex].key > data[nodeIndex].key)) {
		max = leftIndex;
	}
	else {
		max = nodeIndex;
	}

	if ((rightIndex < heapSize) && (data[rightIndex].key > data[max].key)) {
		max = rightIndex;
	}
	
	// swap values if necessary, and continue fixing the heap towards the leaves
	if (max != nodeIndex) {
		Swap(data[nodeIndex], data[max]);		//swapping the data[] values
		
		//swapping the indexArr[] values:
		int tempIndex = indexArr[data[nodeIndex].data];
		indexArr[data[nodeIndex].data] = indexArr[data[max].data];
		indexArr[data[max].data] = tempIndex;

		FixHeap(max);
	}
}

HeapItem Heap::DeleteMax() {
	if (heapSize < 1) {
		printf("Error: EMPTY HEAP\n");
		exit(1);
	}
	HeapItem max = data[0];
	indexArr[max.data] = NOT_IN_HEAP;
	heapSize--;
	data[0] = data[heapSize];
	indexArr[data[0].data] = 0;
	FixHeap(0);
	return max;
}

void Heap::Build(HeapItem A[], int n) {
	heapSize = maxSize = n;
	data = A;
	allocated = 0;
	indexArr = new int[n];

	for (int i = 0; i < heapSize; i++) {
		indexArr[data[i].data] = i;
	}

	for (int i = n / 2 - 1; i >= 0; i--) {
		FixHeap(i);
	}
}

bool Heap::IsEmpty() {
	return this->heapSize == 0;
}

void Heap::IncreaseKey(int place, Type newKey) {
	data[place].key = newKey;
	int index = place, tempIndex;
	while(index > 0 && data[index].key > data[Parent(index)].key) {
		Swap(data[index], data[Parent(index)]); //swap the data[] values
		
		//swap the indexArr[] values
		tempIndex = indexArr[data[index].data];
		indexArr[data[index].data] = indexArr[data[Parent(index)].data];
		indexArr[data[Parent(index)].data] = tempIndex;

		index = Parent(index);
	}
}

int Heap::getIndex(int u) {
	return indexArr[u];
}
