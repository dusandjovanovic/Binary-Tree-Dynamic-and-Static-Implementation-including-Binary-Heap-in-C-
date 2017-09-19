#pragma once
#include <iostream>
#include <iomanip>
#include "Queues.h"
using namespace std;

template <typename type>
class staticTree {
protected:
	type* array;
	long length;
	long numberOfElements;
public:
	staticTree() {
		array = nullptr;
		numberOfElements = 0;
	}

	staticTree(long newLength) {
		length = newLength;
		array = new type[length];
		for (long i = 0; i < length; i++)
			array[i] = NULL;
		numberOfElements = 0;
	}

	~staticTree() {
		delete[] array;
	}

	bool isEmpty() {
		return numberOfElements == 0;
	}

	long getRight(long index) {
		return 2 * index + 2;
	}

	long getLeft(long index) {
		return 2 * index + 1;
	}

	long returnNumberOfElements() {
		return numberOfElements;
	}

	void insert(type element) {
		if (numberOfElements == length)
			return;
		long tmp = 0;
		long prev = NULL;
		while (tmp <= length && array[tmp] != NULL) {
			prev = tmp;
			if (array[tmp] <= element)
				tmp = getRight(tmp);
			else
				tmp = getLeft(tmp);
		}

		if (array[0] == NULL)
			array[0] = element;
		else if (array[prev] <= element)
			array[getRight(prev)] = element;
		else
			array[getLeft(prev)] = element;
		numberOfElements++;
	}

	long search(type element) {
		long tmp = 0;
		while (array[tmp] != NULL) {
			if (array[tmp] == element)
				return tmp;
			if (array[tmp] < element)
				tmp = getRight(tmp);
			else
				tmp = getLeft(tmp);
		}
		return NULL;
	}

	void preOrder(long index, int indent = 0) {
		if (array[index] != NULL && index <= length) {
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			cout << array[index] << endl;
			preOrder(getLeft(index), indent + 4);
			preOrder(getRight(index), indent + 4);
		}
	}

	void inOrder(long index, int indent = 0) {
		if (array[index] != NULL && index <= length) {
			preOrder(getLeft(index), indent + 4);
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			cout << array[index] << endl;
			preOrder(getRight(index), indent + 4);
		}
	}

	void postOrder(long index, int indent = 0) {
		if (array[index] != NULL) {
			preOrder(getLeft(index), indent + 4);
			preOrder(getRight(index), indent + 4);
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			cout << array[index] << endl;
		}
	}

	void breadthFirst() {
		long i = 0;
		Queue<long> queue(length);

		if (array[i] != NULL) {
			queue.enqueue(i);
			while (!queue.isEmpty()) {
				i = queue.dequeue();
				cout << array[i] << endl;
				if (getLeft(i) <= length && array[getLeft(i)] != NULL)
					queue.enqueue(getLeft(i));
				if (getRight(i) <= length && array[getRight(i)] != NULL)
					queue.enqueue(getRight(i));
			}
		}
	}

	void deleteByCopying(type element) {
		long prev = NULL;
		long tmp = 0;
		long node;

		while (array[tmp] != NULL && array[tmp] != element && tmp <= length) {
			prev = tmp;
			if (array[tmp] < element)
				tmp = getRight(tmp);
			else
				tmp = getLeft(tmp);
		}
		node = tmp;

		if (array[tmp] != NULL && array[tmp] == element) {
			if (array[getRight(tmp)] == NULL) {
				array[tmp] = array[getLeft(tmp)];
				addLinkes(tmp, getLeft(tmp));
			}
			if (array[getLeft(tmp)] == NULL) {
				array[tmp] = array[getRight(tmp)];
				addLinkes(tmp, getRight(tmp));
			}
			else {
				long finder = getLeft(tmp);
				long previous = tmp;
				while (array[getRight(finder)] != NULL) {
					previous = finder;
					finder = getRight(finder);
				}
				array[tmp] = array[finder];
				if (previous == node)
					addLinkes(getLeft(previous), getLeft(finder));
				else
					addLinkes(getRight(previous), getLeft(finder));

				numberOfElements--;
				return;
			}
		}
	}

	void addLinkes(long link, long index) {
		array[link] = array[index];

		if (array[getLeft(index)] != NULL && index <= length)
			addLinkes(getLeft(link), getLeft(index));
		if (array[getRight(index)] != NULL && index <= length)
			addLinkes(getRight(link), getRight(index));

		array[index] = NULL;
	}

	void swapChildren(long first, long second) {
		type tmp = array[second];
		array[second] = array[first];
		array[first] = tmp;

		if (array[getLeft(first)] != NULL || array[getRight(second)] != NULL)
			swapChildren(getLeft(first), getRight(second));
		if (array[getRight(first)] != NULL || array[getLeft(second)] != NULL)
			swapChildren(getRight(first), getLeft(second));
	}

	void mirrorTree(long node) {
		if (array[node] == NULL)
			return;

		mirrorTree(getLeft(node));
		mirrorTree(getRight(node));

		swapChildren(getLeft(node), getRight(node));
	}
};