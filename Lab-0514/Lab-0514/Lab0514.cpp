// Lab0514.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "staticTree.h"

int main()
{
	staticTree<int> tree(100);
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

	staticTree<int> tree2(100);
	tree2.insert(1);
	tree2.insert(2);
	tree2.insert(3);
	tree2.insert(4);

	tree.inOrder(0);

	tree.mergeTree(&tree2);

	system("pause");
	return 0;
}

