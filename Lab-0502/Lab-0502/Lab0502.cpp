// Lab0503.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "staticTree.h"

int main()
{
	staticTree<int> tree(1000);
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
	tree.insert(33);
	tree.insert(88);

	tree.inOrder(0);

	cout << endl << tree.nodesTotal(0) << " " << tree.differentNodes(0, tree.returnNumberOfElements()) << endl;

	system("pause");
	return 0;
}

