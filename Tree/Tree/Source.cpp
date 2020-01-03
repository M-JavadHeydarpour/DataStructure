#include <iostream>
#include "BTree.h"
#include "BST.h"
using namespace std;

void main()
{
	Node * root = NULL;
	BST b(root);
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);
	b.Delete(root,70);
	b.inorder(root);

}