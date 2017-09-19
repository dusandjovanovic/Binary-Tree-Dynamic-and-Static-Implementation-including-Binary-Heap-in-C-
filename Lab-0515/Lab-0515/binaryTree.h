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
		if (node == nullptr)
			node = root;
		while (node != nullptr)
			if (node->isEqual(element))
				return tmp;
			else if (node->isLower(element))
				node = node->right;
			else
				node = node->left;
		return node;
	}

	void deleteTree(Node<type>* node) {
		if (node != nullptr) {
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
			node = nullptr;
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

	void deleteByCopying(type element) {
		Node<type>* node;
		Node<type>* tmp = root;	/* pointer to node for deletition */
		Node<type>* prev = nullptr;

		while (tmp != nullptr && !tmp->isEqual(element)) {
			prev = tmp;
			if (tmp->isLower(element))
				tmp = tmp->right;
			else
				tmp = tmp->left;
		}

		node = tmp;
		// tmp - to be deleted
		// node - new node that takes it's place
		if (tmp != nullptr && tmp->isEqual(element)) {
			if (node->right == nullptr)	// no right ancestor
				node = node->left;
			if (node->left == nullptr)	// no left ancesstor
				node = node->right;
			else {
				// has both ancestors
				Node<type>* finder = node->left;
				Node<type>* prevFinder = node;
				while (finder->right != nullptr) {
					prevFinder = finder;
					finder = finder->right;
				}

				node->setKey(finder->getKey());
				if (prevFinder == node)
					prevFinder->left = tmp->left;
				else
					prevFinder->right = tmp->left;

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

			delete finder;
			numberOfElements--;
		}

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

	long findDepth(Node<type>* node) {
		Node<type>* tmp = root;
		long depth = 0;
		while (tmp != node && tmp != nullptr) {
			if (tmp->isLower(node->getKey()))
				tmp = tmp->right;
			else
				tmp = tmp->left;
			depth++;
		}
		return depth;
	}

	void mostNodesLevel() {
		long maxNodes = 0;
		long maxLevel = 0;
		long level = 0;
		Node<type>* node = root;
		Queue<Node<type>*> queue(numberOfElements);

		while (node != nullptr) {
			queue.enqueue(node);
			Node<type>* parent = node;

			while (!queue.isEmpty()) {
				node = queue.dequeue();

				node->showNode();
				if (node->left != nullptr)
					queue.enqueue(node->left);
				if (node->right != nullptr)
					queue.enqueue(node->right);

				if (node == nullptr || queue.getHead() == nullptr)
					continue;

				if (findDepth(node) == (findDepth(queue.getHead()) - 1))
					if (maxNodes < queue.numberOfElements()) {
						maxNodes = queue.numberOfElements();
						maxLevel = findDepth(queue.getHead());
					}
			}
			node = nullptr;
		}

		cout << endl << "Level: " << maxLevel << " with " << maxNodes << " nodes" << endl;
	}

	void mostNodesRecursive(Node<type>* node, long maxLevel = 0, long maxNodes = 0) {
		// ?
	}
};