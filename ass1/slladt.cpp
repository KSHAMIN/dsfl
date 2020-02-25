
#include "slladt.h"
#include<iostream>

using namespace std;

template<class T>
slladt<T>::slladt()   //to initialize head of linked list
{
	head=NULL;
}
template<class T>
slladt<T>::~slladt()
{
	// TODO Auto-generated destructor stub
}
template<class T>             //to create node of linked list
node<T>* slladt<T>::getnode()
{
	node<T> * p;
	p=new node<T>;
	cout<<"Enter the data::";     //scan data and store into node
	cin>>p->data;
	p->next=NULL;

	return p;
}
template<class T>
void slladt<T>::create()    //to create linked list
{
	int n,i;
	node<T>* p;
	cout<<"Enter number of elements you want:";     //scan number of nodes 
	cin>>n;
	for(i=0;i<n;i++)    
	{
		if(head==NULL)          //if list is empty
		{
			head=getnode();      //add node to head
			p=head;
		}
		else
		{
			p->next=getnode();     //connect the nodes
			p=p->next;
		}
	}
}
template<class T>
void slladt<T>::display()     //to display linked list
{
	node<T> *p;
	p=head;
	cout<<"List is::";
	while(p!=NULL)          //to traverse complete linked list
	{
		cout<<p->data<<"--->";
		p=p->next;
	}
}
template<class T>
void slladt<T>::insert_beg(T x)  //to insert a node at beginning of list
{
	node<T>* p;
	p=new node<T>;    //create new node
	p->data=x;

	p->next=head;    //insert node at beginning
	head=p;
}
template<class T>
void slladt<T>::insert_end(T x)   //to insert a node at end of list
{
	node<T> *p,*q;
	q=head;                
	p=new node<T>;     //creation of node
	p->data=x;
	p->next=NULL;

	if(head==NULL)
	{
		head=p;
	}
	else
	{
		while(q->next!=NULL)   //traverse till last node
		{
			q=q->next;   //add new node at last of list
		}
		q->next=p;
	}
}
template<class T>
void slladt<T>::insert_at(T x)  //to insert node at position
{
	int n,i;
	node<T> *p,*q;
	p=new node<T>;     //creation of new node
	p->data=x;
	p->next=NULL;
	cout<<"\nEnter the position :";
	cin>>n;
	if(n==1)
	{
		insert_beg(x);
	}
	else
	{
		q=head;
		for(i=1;i<n-1;i++)   //insert node at given position
			q=q->next;
		p->next=q->next;
		q->next=p;
	}
}
template<class T>
T slladt<T>::delete_beg()    //to delete from begining of list
{
	node<T>*p;
	T x;
	if(head==NULL)
		return -1;
	else
	{
		p=head;           //delete first node
		x=head->data;   
		head=p->next;
		delete p;         //delete node
		return x;

	}

}
template<class T>      //to delete element from end of list
T slladt<T>::delete_end()
{
	node<T> *p,*q;
	p=head;
	T x;
	while(p->next!=NULL)  //traverse till last node
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	x=p->data;
	delete p;     //delete node
	return x;
}
template<class T>
T slladt<T>::delete_pos()    //to delete element from given position
{
	node<T> *p,*q,*r;
	int n,i;
	T x;
	p=head;
	q=p->next;
	cout<<"Enter the position:";
	cin>>n;
	for(i=1;i<n;i++)     //traverse till given position
	{
		r=p;
		p=p->next;
		q=p->next;
	}
	r->next=q;       //link the list and delete node
	x=p->data;
	delete p;
	return x;
}

template<class T>
T slladt<T>::data_head()  // to return the data of head node
{
	if(head==NULL)
		return -1;
	else
	{
		return head->data;
	}
}

template<class T>
bool slladt<T>::head_1()   //to check list is empty or not
{
	if(head==NULL)
		return true;
	else
		return false;

}