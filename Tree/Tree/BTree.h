#pragma once
#include "LinkedList.h"
class BTree
{
private:
	Node * head;
	Node * root;
	LinkedList * btree;
	LinkedList * inorder = new LinkedList;
	LinkedList * preorder = new LinkedList;
	LinkedList * postorder = new LinkedList;

public:
	void Insert(Node * root, int data);
	Node * Search(Node * root, int data);
	Node * Delete(Node * data, int amount = NULL);
	void Inorder(Node * root);
	void Preorder(Node * root);
	LinkedList * Postorder(Node * root);

	BTree();
	~BTree();
};

