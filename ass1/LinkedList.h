/*
 * LinkedList.h
 *
 *  Created on: 24-Mar-2020
 *      Author: kshamin
 */
#pragma once
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

class Node
{
	Node* next;
public:
	char data;
	friend class LinkedList;
};

class InvalidPosExc{};

class LinkedList
{
public:
	Node* head;
	LinkedList();
	void insert(int,char);
	Node* getnode(char);
	char del(int);
	bool isempty();
	void display();
	virtual ~LinkedList();
};

#endif /* LINKEDLIST_H_ */
