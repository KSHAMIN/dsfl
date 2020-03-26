/*
 * Stack.h
 *
 *  Created on: 24-Mar-2020
 *      Author: kshamin
 */

#ifndef STACK_H_
#define STACK_H_
#include "LinkedList.h"
#include <iostream>
using namespace std;

class Stack {
	LinkedList ll;
public:
	Stack();
	void push(char);
	char pop();
	char peep();
	bool IsEmpty();
	void disp();
	virtual ~Stack();
};

class StackUnderflowExc{};

#endif /* STACK_H_ */
