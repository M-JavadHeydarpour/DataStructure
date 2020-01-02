#include "LinkedList.h"


void LinkedList::insert(Node ** head, Node * prev, int data,int status)
{
	//allocate new node for insert it to linkedlist
	Node *newNode = new Node(data);

	if (status == 0) 
	{
		//Make next of new node as head and prev as null
		newNode->next = (*head);
		newNode->prev = NULL;

		//change head.prev to new node 
		if ((*head) != NULL)
		{
			(*head)->prev = newNode;
		}

		//pointed head to newnode
		(*head) = newNode;
	}
	else if (status == 1)
	{
		Node *last = (*head);

		if ((*head) == NULL)
		{
			newNode->prev = NULL;
			(*head) = newNode;
			return;

		}

		while(last->next != NULL)
		{
			last = last->next;
		}

		last->next = newNode;
		newNode->prev = last;
	}
	else
	{
		//new.next = prev.next
		newNode->next = prev->next;

		//prev.next = new
		prev->next = newNode;

		//new.prev = prev
		newNode->prev = prev;

		//new.next.prev = new
		if (newNode->next != NULL)
		{
			newNode->next->prev = newNode;
		}
	}
}

void LinkedList::print(Node * node)
{
	while (node != NULL)
	{
		cout << node->data << "\t";
		node = node->next;
	}
}

LinkedList::LinkedList()
{
}


LinkedList::~LinkedList()
{
}
