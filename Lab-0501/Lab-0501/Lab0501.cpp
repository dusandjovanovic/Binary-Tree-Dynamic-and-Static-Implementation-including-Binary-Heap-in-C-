// Lab0501.cpp : Defines the entry point for the console application.
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
	tree.insert(100);

	tree.inOrder(tree.returnRoot());

	cout << endl << tree.numberOfSame(tree.returnRoot(), 44) << endl;
	cout << endl << tree.differentNodes(tree.returnRoot(), tree.returnNumber()) << endl;

	system("pause");
    return 0;
}

