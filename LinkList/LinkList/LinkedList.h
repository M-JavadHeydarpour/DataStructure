#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
class LinkedList
{
public:

	void insert(Node ** head, Node * prev, int data, int status);
	void print(Node * node);

	LinkedList();
	~LinkedList();
};

