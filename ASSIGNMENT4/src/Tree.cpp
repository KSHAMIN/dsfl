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
	while((st.empty() == false) || (p != NULL))
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
		cout << "\t" << q->data;
		inorder_Recur(q->rchild);
	}
}

template <class T>
void Tree<T>::postorder_NonRecur(Node<T>* q)
{
	stack<Node<T>*> st1,st2;
	if(q == NULL)
		return;
	st1.push(q);
	Node<T>* p;
	while(!st1.empty())
	{
		p = st1.top();
		st1.pop();
		st2.push(p);
		if(p->lchild)
			st1.push(p->lchild);
		if(p->rchild)
			st1.push(p->rchild);
	}

	while(!st2.empty())
	{
		p = st2.top();
		st2.pop();
		cout << "\t" << p->data;
	}
}

template <class T>
void Tree<T>::postorder_Recur(Node<T>* q)
{
	if(q)
	{
		postorder_Recur(q->lchild);
		postorder_Recur(q->rchild);
		cout << "\t" << q->data;
	}
}

template <class T>
void Tree<T>::preorder_NonRecur(Node<T>* q)
{
	stack<Node<T>*> st;
	st.push(q);
	while(!st.empty())
	{
		Node<T>* p;
		p = st.top();
		st.pop();
		cout << "\t" << p->data;
		if(p->rchild)
			st.push(p->rchild);
		if(p->lchild)
			st.push(p->lchild);
	}
}

template <class T>
void Tree<T>::preorder_Recur(Node<T>* q)
{
	if(q)
	{
		cout << "\t" << q->data;
		preorder_Recur(q->lchild);
		preorder_Recur(q->rchild);
	}
}
