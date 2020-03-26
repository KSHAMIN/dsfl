/*
 * LinkedList.cpp
 *
 *  Created on: 24-Mar-2020
 *      Author: kshamin
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
	// TODO Auto-generated constructor stub
	head = NULL;
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

Node* LinkedList::getnode(char c)
{
	Node *p = new Node;
	p->data = c;
	p->next = NULL;
	return p;
}

bool LinkedList::isempty()
{
	if(head == NULL)
		return true;
	return false;
}

void LinkedList::insert(int pos,char c)
{
	Node *p,*tmp;
	p = new Node;
	p = head;
	if(isempty())
	{
		p = getnode(c);
		head = p;
		p = p->next;
	}
	if(!pos)
	{
		tmp = getnode(c);
		tmp->next = head;
		head = tmp;
	}
}

char LinkedList::del(int pos)
{
	Node *tmp;
	char x;
	if(!pos)
	{
		tmp = head;
		x = head->data;
		head = head->next;
		delete tmp;
	}
	return x;
}

void LinkedList::display()
{
	Node *p;
	p = head;
	while(p!=NULL)
	{
		cout << "\t" << p->data;
	}
}
