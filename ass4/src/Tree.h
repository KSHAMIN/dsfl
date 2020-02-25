/*
 * Tree.h
 *
 *  Created on: 12-Feb-2020
 *      Author: dsflh-10
 */

#ifndef TREE_H_
#define TREE_H_
#include <iostream>
using namespace std;

template <class T>
class Node
{
	T data;
	Node* lchild;
	Node* rchild;
public:
	Node();
	virtual ~Node();
	template <class U> friend class Tree;
};

template <class T>
class Tree {
	Node<T>* root;
public:
	Tree();
	virtual ~Tree();
	bool ISOPERATOR(char);
	Node<T>* expression_tree(string);
	void inorder_Recur(Node<T>*);
	void inorder_NonRecur(Node<T>*);
	void preorder_Recur(Node<T>*);
	void preorder_NonRecur(Node<T>*);
	void postorder_Recur(Node<T>*);
	void postorder_NonRecur(Node<T>*);
};

#endif /* TREE_H_ */
