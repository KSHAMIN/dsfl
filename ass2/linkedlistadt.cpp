#include "linkedlistadt.h"
#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

template<class T>
linkedlistadt<T>::linkedlistadt()   //to initialize head of linked list
{
	head=NULL;
}

template<class T>             //to create node of linked list
node<T>* linkedlistadt<T>::getnode(char name[],int age,char bgroup[],char phoneno[],int priority)
{
	node<T> * q;
	int i;
	q=new node<T>;
	strcpy(q->p.name,name);   //copy data of patient
	q->p.age=age;
	strcpy(q->p.bgroup,bgroup);
	strcpy(q->p.phoneno,phoneno);
	q->priority=priority;
	q->next=NULL;

	return q;
}
template<class T>
void linkedlistadt<T>::display()     //to display linked list
{
	node<T> *p; 
	p=head;
	string s;
	cout<<"\nList of Patient::";
	cout<<setw(17)<<"\nName of Patient"<<"|"<<setw(16)<<"Age of Patient"<<"|"<<setw(13)<<"Blood Group"<<"|"<<setw(15)<<"Mobile Number"<<"|"<<setw(20)<<"Condition of Patient";
	cout<<"\n----------------------------------------------------------------------------------------------";
	while(p!=NULL)          //to traverse complete linked list
	{
		if(p->priority==1)
		s="Serious";
		else if(p->priority==2)
		s="Medium";
		else
		s="General";
		
		cout<<"\n"<<setw(15)<<p->p.name<<"|"<<setw(16)<<p->p.age<<"|"<<setw(13)<<p->p.bgroup<<"|"<<setw(15)<<p->p.phoneno<<"|"<<setw(20)<<s;  //to print data of each list
		p=p->next;
	}
}
template<class T>
void linkedlistadt<T>::insert(char name[],int age,char bgroup[],char phoneno[],int priority)   //to insert a node at to list
{
	node<T> *p,*q;
	p=getnode(name,age,bgroup,phoneno,priority);     //creation of node
	q=head;
	if(head==NULL)      //if list is empty
	{
		head=p;
	}
	else if(q->priority > p->priority)   //if priority of inserting patient is greater than existing patient
	{
		p->next=q;
		head=p;
	}
	else
	{
		q=head;
		while(q->next!=NULL && q->next->priority <= p->priority)   //traverse till  node
		{
			q=q->next;   //add new node
		}
		p->next=q->next;
		q->next=p;
	}
}

template<class T>
void linkedlistadt<T>::delete_beg()    //to delete from begining of list
{
	node<T>*p;
	if(head==NULL)
		return ;
	else
	{
		p=head;           //delete first node
		head=p->next;
		delete p;         //delete node
	}
}

template<class T>
node<T>* linkedlistadt<T>::head1()   //to return the head of list
{
	if(head!=NULL)
		return head;    //returning head
	else
		return NULL;

}

