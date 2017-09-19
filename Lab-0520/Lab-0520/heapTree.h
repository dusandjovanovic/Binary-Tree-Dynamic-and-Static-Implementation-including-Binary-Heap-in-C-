#pragma once
#include <iostream>
using namespace std;

template <typename type>
class binaryMaxHeap {
protected:
	type* array;
	long length;
	long numberOfElements;
public:
	binaryMaxHeap(long newLength) {
		length = newLength;
		numberOfElements = 0;
		array = new type[length];
	}

	~binaryMaxHeap() {
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
		while (array[i / 2] <= element && i > 1) {
			array[i] = array[i / 2];
			i = i / 2;
		}
		array[i] = element;
	}

	type deleteRoot() {
		if (numberOfElements == 0)
			throw new std::exception();

		type result = array[1];

		type last = array[numberOfElements];
		numberOfElements--;
		int i = 1;
		while (2 * i < numberOfElements + 1) {
			long child = 2 * i;
			if (child + 1 < numberOfElements + 1 && array[child + 1] > array[child])
				child++;
			if (last > array[child])
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

	void traverseHeap(int index) {
		if (index <= numberOfElements) {
			traverseHeap(2 * index);
			cout << array[index] << endl;
			traverseHeap(2 * index + 1);
		}
	}

	void convertHeap() {
		int length = numberOfElements;

		type* samples = new type[length];
		int i = 0;
		while (!isEmpty())
			samples[i++] = deleteRoot();

		binaryMinHeap<type>* newHeap = new binaryMinHeap<type>(length);

		i = 0;
		while (i < length) {
			newHeap->insertInto(samples[i]);
			i++;
		}
		cout << endl << endl;
		newHeap->traverseHeap(1);
	}


};

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
		while (array[i / 2] > element && i > 1) {
			array[i] = array[i / 2];
			i = i / 2;
		}
		array[i] = element;
	}

	type deleteRoot() {
		if (numberOfElements == 0)
			throw new std::exception();

		type result = array[1];

		type last = array[numberOfElements];
		numberOfElements--;
		int i = 1;
		while (2 * i < numberOfElements + 1) {
			long child = 2 * i;
			if (child + 1 < numberOfElements + 1 && array[child + 1] < array[child])
				child++;
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

	void traverseHeap(int index) {
		if (index <= numberOfElements) {
			traverseHeap(2 * index);
			cout << array[index] << endl;
			traverseHeap(2 * index + 1);
		}
	}
};