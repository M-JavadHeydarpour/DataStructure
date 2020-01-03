#pragma once
#include "LinkedList.h"
class BST
{
private:
	Node * root ;
public:

	Node * Insert(Node * root, int data);
	Node * Delete(Node * root, int key);
	Node * MinChild(Node *root);
	void inorder(Node * root);

	BST(Node * root);
	~BST();
};

