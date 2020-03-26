/*
 * Stack.cpp
 *
 *  Created on: 24-Mar-2020
 *      Author: kshamin
 */

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
	// TODO Auto-generated constructor stub
}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

bool Stack::IsEmpty()
{
	return ll.isempty();
}

void Stack::push(char c)
{
	ll.insert(0,c);
}

char Stack::peep()
{
	if(IsEmpty())
		throw StackUnderflowExc();
	return ll.head->data;
}

char Stack::pop()
{
	if(!IsEmpty())
		return ll.del(0);
	throw StackUnderflowExc();
}


void Stack::disp()
{
	if(!IsEmpty())
		ll.display();
	else
		cout << "\n*****Stack is empty!!*****\n";
}
