#pragma once
#include <iostream>
using namespace std;

template <typename type>
class binaryMinHeap {
protected:
	type* array;
	long length;
	long numberOfElements;
public:
	binaryMinHeap(long newLength) {
		length = newLength;
		numberOfElements = 0;
		array = new type[length];
	}

	~binaryMinHeap() {
		delete[] array;
	}

	bool isEmpty() {
		return numberOfElements == 0;
	}

	void insertInto(type element) {
		if (numberOfElements == length - 1)
			return;
		numberOfElements++;
		int i = numberOfElements;
		while (i > 1 && array[i / 2] > element) {
			array[i] = array[i / 2];
			i = i / 2;
		}
		array[i] = element;
	}

	type deleteRoot(type element) {
		if (numberOfElements == 0)
			throw new std::exception();

		type result = array[1];
		type last = array[numberOfElements];
		numberOfElements--;
		long i = 1;

		while (i * 2 <= numberOfElements) {
			long child = 2 * i;
			if (child + 1 <= numberOfElements && array[child + 1] < array[child])
				child = child + 1;
			if (last <= array[child])
				break;
			array[i] = array[child];
			i = child;
		}

		array[i] = last;
		return result;
	}

	void heapSort(type* data, long length) {
		binaryMinHeap<type> heap(length + 1);

		for (int i = 0; i < length; i++)
			heap.insertInto(data[i]);

		int i = 0;
		while (!heap.isEmpty())
			a[i++] = heap.deleteRoot();
	}
};