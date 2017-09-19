#pragma once
#include <iostream>
#include <iomanip>
#include "Queues.h"
using namespace std;

template <typename type>
class Node {
public:
	type key;
	Node<type>* left;
	Node<type>* right;
public:
	Node() {
		left = right = nullptr;
	}

	Node(type element) {
		key = element;
		left = right = nullptr;
	}

	Node(type element, Node<type>* newLeft, Node<type>* newRight) {
		key = element;
		left = newLeft;
		right = newRight;
	}

	~Node() {
		// ... virtually
	}

	bool isLower(type element) {
		return key <= element;
	}

	bool isGreater(type element) {
		return key > element;
	}

	bool isEqual(type element) {
		return key == element;
	}

	void setKey(type newKey) {
		key = newKey;
	}

	type getKey() {
		return key;
	}

	void showNode() {
		cout << key << "\n ";
	}
};


template <typename type>
class binaryTree {
protected:
	Node<type>* root;
	long numberOfElements;
public:
	binaryTree() {
		root = nullptr;
		numberOfElements = 0;
	}

	~binaryTree() {
		deleteTree(root);
	}

	Node<type>* returnRoot() {
		return root;
	}

	bool isEmpty() {
		return root == nullptr;
	}

	bool isInTree(type element) {
		return search(element) != nullptr;
	}

	Node<type>* search(type element) {
		return search(root, element);
	}

	long returnNumber() {
		return numberOfElements;
	}

	void insert(type element) {
		Node<type>* tmp = root;
		Node<type>* previous = nullptr;

		while (tmp != nullptr) {
			previous = tmp;
			if (tmp->isLower(element))
				tmp = tmp->right;
			else
				tmp = tmp->left;
		}

		if (previous == nullptr)
			root = new Node<type>(element);
		else if (previous->isLower(element))
			previous->right = new Node<type>(element);
		else
			previous->left = new Node<type>(element);
		numberOfElements++;
	}

	Node<type>* search(Node<type>* node, type element) {
		while (node != nullptr)
			if (node->isEqual(element))
				return tmp;
			else if (node->isLower(element))
				node = node->right;
			else
				node = node->left;
		return node;
	}

	long numberOfSame(Node<type>* node, type element) {
		long numberOf = 0;
		while (node != nullptr) {
			if (node->isEqual(element))
				numberOf++;

			if (node->isLower(element))
				node = node->right;
			else
				node = node->left;
		}
		return numberOf;
	}

	void deleteTree(Node<type>* node) {
		if (node != nullptr) {
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
		}
	}

	void preOrder(Node<type>* node, int indent = 0) {
		if (node != nullptr) {
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			node->showNode();
			preOrder(node->left, indent + 4);
			preOrder(node->right, indent + 4);
		}
	}

	void inOrder(Node<type>* node, int indent = 0) {
		if (node != nullptr) {
			inOrder(node->left, indent + 4);
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			node->showNode();
			inOrder(node->right, indent + 4);
		}
	}

	void postOrder(Node<type>* node, int indent = 0) {
		if (node != nullptr) {
			postOrder(node->left, indent + 4);
			postOrder(node->right, indent + 4);
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			node->showNode();
		}
	}

	void breadthFirst() {
		Node<type>* node = root;
		Queue<Node<type>*> queue(numberOfElements);

		if (node != nullptr) {
			queue.enqueue(node);
			while (!queue.isEmpty()) {
				node = queue.dequeue();
				node->showNode();
				if (node->left != nullptr)
					queue.enqueue(node->left);
				if (node->right != nullptr)
					queue.enqueue(node->right);
			}
		}
	}

	void itterativePreorder() {
		Node<type>* node = root;
		Stack<Node<type>*> stack(numberOfElements);
		if (node != nullptr) {
			stack.push(node);
			while (!stack.isEmpty()) {
				node = stack.pop();
				node->showNode();
				if (node->right != nullptr)	/* right pushed to stack first */
					stack.push(node->right);
				if (node->left != nullptr)
					stack.push(node->left);
			}
		}
	}

	void itterativeInorder() {
		Node<type>* node = root;
		Stack<Node<type>*> stack(numberOfElements);
		while (node != nullptr) {
			while (node != nullptr) {
				if (node->right != nullptr)
					stack.push(node->right);
				stack.push(node);
				node = node->left;
			}
			node = stack.pop();
			while (!stack.isEmpty() && node->right == nullptr) {
				node->showNode();
				node = stack.pop();
			}
			node->showNode();
			if (!stack.isEmpty())
				node = stack.pop();
			else node = nullptr;
		}
	}

	void itterativePostorder() {
		Node<type>* node = root;
		Node<type>* q = root;
		Stack<Node<type>*> stack(numberOfElements);
		while (node != nullptr) {
			while (node->left != nullptr) {
				stack.push(node);
				node = node->left;
			}
			while (node != nullptr && (node->right == nullptr || node->right == q)) {
				node->showNode();
				q = node;
				if (stack.isEmpty())
					return;
				node = stack.pop();
			}
			stack.push(node);
			node = node->right;
		}
	}

	void deleteByCopying(type element) {
		Node<type>* tmp = root;
		Node<type>* prev = nullptr;
		Node<type>* node;

		while (tmp != nullptr && !tmp->isEqual(element)) {
			prev = tmp;
			if (tmp->isLower(element))
				tmp = tmp->right;
			else
				tmp = tmp->left;
		}

		node = tmp;
		if (tmp != nullptr && tmp->isEqual(element)) {
			if (node->right == nullptr)
				node = node->left;
			if (node->left == nullptr)
				node = node->right;

			Node<type>* finder = tmp->left;
			Node<type>* finderPrev = tmp;
			while (finder->right != nullptr) {
				finderPrev = finder;
				finder = finder->right;
			}

			tmp->setKey(finder->getKey());

			if (finderPrev == tmp)
				tmp->left = finder->left;
			else
				finderPrev->right = finder->left;
			delete finder;
			numberOfElements--;
			return;
		}
		if (tmp == root)
			root = node;
		else if (prev->right == tmp)
			prev->right = node;
		else
			prev->left = node;
		delete tmp;
		numberOfElements--;

		if (root != nullptr)
			throw new std::exception("Not found in tree..");
		else
			throw new std::exception("Empty tree..");
	}

	void deleteByMerging(type element) {
		Node<type>* node;
		Node<type>* tmp = root;
		Node<type>* prev = nullptr;

		while (tmp != nullptr && !tmp->isEqual(element)) {
			prev = tmp;
			if (tmp->isLower(element))
				tmp = tmp->right;
			else
				tmp = tmp->left;
		}

		node = tmp;
		if (p != nullptr && p->isEqual(element)) {
			/* no right ancesstor */
			if (node->right == nullptr)
				node = node->left;
			/* no left ancesstor */
			if (node->left == nullptr)
				node = node->right;
			/* has both ancesstors */
			else {
				Node<type>* finder = tmp->left;
				while (finder->right != nullptr)
					finder = finder->right;
				/* tmp is the most-right node in left subtree */

				finder->right = node->right;
				node = node->left;
			}
			if (tmp == root)
				root = node;
			else if (prev->left == tmp)
				prev->left = node;
			else
				prev->right = node;
			delete tmp;
			numberOfElements--;
		}
		if (root != nullptr)
			throw new std::exception("Not found in tree..");
		else
			throw new std::exception("Empty tree..");
	}

	void balanceTree(int data[], int first, int last) {
		if (first <= last) {
			int middle = (first + last) / 2;
			insert(data[middle]);
			balanceTree(data, first, middle - 1);
			balanceTree(data, middle + 1, last);
		}
	}

	long differentNodes(Node<type>* node, long different) {
		if (node == nullptr)
			return different;
		
		long current = numberOfSame(node, node->getKey());
		if (current != 1)
			different -= (current - 1);

		different = differentNodes(node->right, different);
		different = differentNodes(node->left, different);

		return different;
	}
};