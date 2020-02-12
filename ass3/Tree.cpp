/*
 * Tree.cpp
 *
 *  Created on: 12-Feb-2020
 *      Author: dsflh-10
 */

#include "Tree.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

template <class T>
Tree<T>::Tree() {
	// TODO Auto-generated constructor stub
	root = NULL;
}

template <class T>
Tree<T>::~Tree() {
	// TODO Auto-generated destructor stub
}

template <class T>
Node<T>::Node()
{
	// TODO Auto-generated destructor stub
	lchild = NULL;
	rchild = NULL;
}

template <class T>
Node<T>::~Node()
{
	// TODO Auto-generated destructor stub
}

template <class T>
bool Tree<T>::ISOPERATOR(char ch)
{
	return (ch == '+' || ch == '*' || ch == '-' || ch == '/');
}

template <class T>
Node<T>* Tree<T>::expression_tree(string s)
{
	stack <Node<T>*> st;
	int l = s.length();
	int i;
	for(i = 0;i < l;i++)
	{
		if(ISOPERATOR(s[i]))
		{
			Node<T>* p = new Node<T>;
			p->data = s[i];
			p->rchild = st.top();
			st.pop();
			p->lchild = st.top();
			st.pop();
			st.push(p);
		}
		else
		{
			Node<T>* p = new Node<T>;
			p->data = s[i];
			st.push(p);
		}
	}
	root = st.top();
	st.pop();
	return root;
}


template <class T>
void Tree<T>::inorder_NonRecur(Node<T>* q)
{
	Node<T>* p = q;
	stack<Node<T>*> st;
	while((st.empty == false) || (p != NULL))
	{
		while(p)
		{
			st.push(p);
			p = p->lchild;
		}
		p = st.top();
		st.pop();
		cout << "\t" << p->data;
		p = p->rchild;
	}
}

template <class T>
void Tree<T>::inorder_Recur(Node<T>* q)
{
	if(q)
	{
		inorder_Recur(q->lchild);
		cout << q->data;
		inorder_Recur(q->rchild);
	}
}

template <class T>
void Tree<T>::postorder_NonRecur(Node<T>* q)
{
	stack<Node<T>*> st;
	if(q == NULL)
		return;
	st.push(q);
	Node<T>* p;
	while(!st.empty())
	{

	}
}





