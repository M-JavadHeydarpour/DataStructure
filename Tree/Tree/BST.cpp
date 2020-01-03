#include "BST.h"



Node * BST::Insert(Node * root, int data)
{
	if (root == NULL)
	{
		Node * newNode = new Node(data);
		return newNode;
	}
	if (root->data > data)
	{
		root->prev = Insert(root->prev, data);
	}
	else if (root->data < data)
	{
		root->next = Insert(root->next, data);
	}
	return root;
}

Node * BST::Delete(Node * root, int data)
{
	if (!root)
		return root;
	if (data < root->data)
		root->prev = Delete(root->prev, data);
	else if (data > root->data)
		root->next = Delete(root->next, data);

	else
	{
		if (!root->prev)
		{
			Node * temp = root->prev;
			free(root);
			return temp;
		}
		else if (!root->next)
		{
			Node * temp = root->next;
			free(root);
			return temp;
		}
		Node * temp = MinChild(root->prev);

		root->data = temp->data;

		root->next = Delete(root->next, temp->data);
	}
	return root;
}

Node * BST::MinChild(Node * root)
{
	Node * corrent = root;
	while (corrent && corrent->prev != NULL)
		corrent = corrent->prev;
	return root;
}

void BST::inorder(Node * root)
{
	if (!root)
		return;
	inorder(root->prev);
	cout << root->data << endl;
	inorder(root->next);
}

BST::BST(Node * root)
{
	this->root = root;
}


BST::~BST()
{
}
