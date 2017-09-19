// Lab0513.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binaryTree.h"

int main()
{
	binaryTree<int> tree;
	tree.insert(33);
	tree.insert(11);
	tree.insert(55);
	tree.insert(44);
	tree.insert(22);
	tree.insert(26);
	tree.insert(88);
	tree.insert(99);
	tree.insert(12);
	tree.insert(14);
	tree.insert(44);
	tree.insert(22);
	tree.insert(26);
	tree.insert(88);

	tree.inOrder(tree.returnRoot());

	binaryTree<int> tree2;
	tree2.insert(98);
	tree2.insert(564);
	tree2.insert(212);
	tree2.insert(54);
	tree2.insert(21);
	tree2.insert(20);

	tree.mergeTree(&tree2);

	system("pause");
	return 0;
}

