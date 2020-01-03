#include "BTree.h"

void BTree::Insert(Node * root, int data)
{
	
	if (root == NULL) 
	{
		//root->data = data;
		head = root;
		root->data = data;
	}
	else
	{
		Node * insert = new Node(data);

		//if (root->prev == NULL)
		//{
			if (root->prev == NULL)
			{
				root->prev = insert;
			}
			else if (root->next == NULL)
			{
				root->next = insert;
			}
			else
			{
				Insert(root->prev, data);
			}
		//}
	}
	//btree->Insert(root,NULL,data,0);
}

Node * BTree::Search(Node * root, int data)
{
	//Node * find = NULL;

	if (root->data == data)
		return root;
	else if (root->prev->data == data)
		return root->prev;
	else if (root->next->data == data)
		return root->next;
	else
	{
		if (root->prev != NULL)
			return Search(root->prev, data);
		else if (root->next != NULL)
			return Search(root->next, data);
	}

}

Node * BTree::Delete(Node * data, int amount)
{
	if (data == NULL)
	{
		data = Search(root, amount);
	}
	Node * res = data;
	if (data->prev != NULL)
	{
		data = Delete(data->prev);
	}
	else if (data->next !=NULL)
	{
		data = Delete(data->next);
	}
	else 
	{
		data = NULL;
	}
	return res;
}

void BTree::Inorder(Node * root)
{

	if (root != NULL)
	{
		Inorder(root->prev);
		inorder->Insert(&head, head, root->data, 1);
		Inorder(root->next);
	}
}

void BTree::Preorder(Node * root)
{
	if (root != NULL)
	{
		preorder->Insert(&head, head, root->data, 1);
		Preorder(root->prev);
		Preorder(root->next);
	}
}

void BTree::Postorder(Node * root)
{
	Postorder(root->prev);
	Postorder(root->next);
	postorder->Insert(&head, head, root->data, 1);
}

void BTree::printorder()
{
	//inorder.print()
	//preorder.print(head);
}

BTree::BTree()
{
}


BTree::~BTree()
{
}
