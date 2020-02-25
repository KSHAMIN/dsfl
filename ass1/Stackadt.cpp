
#include "stackAdt.h"
#include"slladt.cpp"
#include<iostream>
using namespace std;

template<class T>
stackAdt<T>::stackAdt()
{
	// TODO Auto-generated constructor stub

}
template<class T>
stackAdt<T>::~stackAdt()
{
	// TODO Auto-generated destructor stub
}

template<class T>  
void stackAdt<T>::push(T x)    //to push element to top of stack
{
	l1.insert_beg(x);      //call insert at begining 
}

template<class T>
T stackAdt<T>::pop()   //to pop elemnt from stack
{
	if(!isempty())    //if stack is not empty
	{
		return l1.delete_beg();    //return data of top of element
	}
}

template<class T>
T stackAdt<T>::peep()   //to return content of top of stack
{
     return l1.data_head();
}

template<class T>
bool stackAdt<T>::isempty()    //to check stack is empty or not
{
	if(l1.head_1())
		return true;          //check list is empty or not
	else
		return false;
}

template<class T>
void stackAdt<T>::display1()   //to display the stack
{
	l1.display();
}