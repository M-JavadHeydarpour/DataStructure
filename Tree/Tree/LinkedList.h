#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
class LinkedList
{
public:

	void Insert(Node ** head, Node * prev, int data, int status);
	void Delete(Node ** head, int data = NULL);
	void print(Node * node);

	LinkedList();
	~LinkedList();
};

