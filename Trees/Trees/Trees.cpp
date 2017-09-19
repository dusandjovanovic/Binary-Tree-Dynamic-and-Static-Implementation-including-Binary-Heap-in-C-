// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binaryTree.h"
#include "staticTree.h"
#include "heapTree.h"

int main()
{
	staticTree<double> binTree(100);
	binTree.insert(33);
	binTree.insert(11);
	binTree.insert(40);
	binTree.insert(66);
	binTree.insert(8);
	binTree.insert(1);
	binTree.insert(22);
	binTree.insert(18);
	binTree.insert(100);
	binTree.insert(72);

	binTree.preOrder(0);
	binTree.deleteByCopying(33);
	binTree.preOrder(0);

	system("pause");
    return 0;
}