#include "LinkedList.h"
#include<iostream>
using namespace std;
int main()
{
	Node *head = NULL;

	LinkedList li;
	li.Insert(&head, NULL, 6,0);
	li.Insert(&head,head, 10,1);
	li.Insert(&head,head, 9,1);
	li.Insert(&head,head, -7,1);
	li.Delete(&head,-7);
	li.print(head);
	cin.get();
	return 0;
}