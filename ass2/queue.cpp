#include "queue.h"
#include"linkedlistadt.cpp"
#include<iostream>
using namespace std;

template<class T>
queue<T>::queue()
{
    front=NULL;       //initializing front and rear pointer of queue
    rear=NULL;

}

template<class T>
void queue<T>::enqueue(char name[],int age,char bgroup[],char phoneno[],int priority)   //to add element to queue
{
	l1.insert(name,age,bgroup,phoneno,priority);         //call insert function of linked list
	front=l1.head1();      //front pointer
	node<T> *q;
	q=l1.head1();
	while(q->next!=NULL)
	q=q->next;
	rear=q;            //to get rear pointer
}


template<class T>
void queue<T>::dequeue()
{
	
	if(!isempty())     //to dequeue element from queue
	{
		l1.delete_beg();
		if(front==rear)    //if last element is dequeued
   	    {
   		front=NULL;
   		rear=NULL;	
	    }
   	    else
   	    front=front->next;	
	}
}

template<class T> 
bool queue<T>::isempty()   //to check queue is empty or queue
{
	if(front==NULL)      //if queue is empty
	   return true;
	else
	   return false;	
}

template<class T>
void queue<T>::q_display()  //to display queue
{
	l1.display();
}

template<class T>
int queue<T>::f_data()   //to get first element of queue
{
	if(!isempty())
	    return front->priority;    //return priority of first patient
	else
	   cout<<"\nQueue is Empty";
}

template<class T>
int queue<T>::r_data()   //to get last element of queue
{
	if(!isempty())
	    return rear->priority;  //return priority of last patient
	else
	   cout<<"\nQueue is Empty";
}




