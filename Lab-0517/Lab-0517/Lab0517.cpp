// Lab0517.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "heapTree.h"

int main()
{
	binaryMaxHeap<int> heap(10);
	binaryMaxHeap<int> heap2(10);

	heap.insertInto(11);
	heap.insertInto(3);
	heap.insertInto(9);
	heap.insertInto(22);
	heap.insertInto(33);
	heap.insertInto(13);
	heap.insertInto(80);
	heap.insertInto(12);
	heap.traverseHeap(1);

	heap2.insertInto(1);
	heap2.insertInto(44);
	heap2.insertInto(19);
	heap2.insertInto(81);
	heap2.insertInto(88);

	heap.mergeHeap(&heap2);
	

	system("pause");
    return 0;
}

