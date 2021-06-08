#include <iostream>
using namespace std;
#include "BST.h"


int main()
{
	BST<int> tree;
	tree.Insert(10);
	tree.Insert(20);
	tree.Insert(12);
	tree.Insert(14);
	tree.Insert(29); 
	tree.Insert(28);
	tree.Insert(23);
	tree.Insert(12);
	tree.Insert(2);

	//can't use search function

	tree.PrintInOrder();
	return 0;
}

