//============================================================================
// Name        : ass4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Tree.h"
#include "Tree.cpp"
using namespace std;

class exp_to_bst
{
	string s;
public:
	exp_to_bst()
	{
		s = "";
	}
	string take_input();
};

string exp_to_bst::take_input()
{
	cout << "Enter the postfix string:";
	cin >> s;
	return s;
}

int menu()
{
	int r;
	cout << "\n1)Inorder Traversal\n2)Preorder Traversal\n3)Postorder Traversal\n";
	cout << "\nEnter your choice:";
	cin >> r;
	return r;
}

char cap(char ch)
{
	if((ch == 'a') || (ch == 'A'))
		return 'A';
	if((ch == 'b') || (ch == 'B'))
		return 'B';
	return 'C';
}

int main()
{
	Tree<char> t;
	exp_to_bst e;
	string exp;
	exp = e.take_input();
	Node<char>* n = t.expression_tree(exp);
	char ch,c;

	do
	{
		cout << "\n\nA)Recursive Traversal\nB)Non-Recursive Traversal\nC)Exit\n";
		cout << "\nEnter your choice:";
		cin >> ch;
		c = cap(ch);
		switch(c)
		{
		case ('A'):
				switch(menu())
				{
				case 1:
					cout << "Recursive inorder traversal:\n";
					t.inorder_Recur(n);
					break;

				case 2:
					cout << "Recursive preorder trasversal:\n";
					t.preorder_Recur(n);
					break;

				case 3:
					cout << "Recursive postorder traversal:\n";
					t.postorder_Recur(n);
					break;
				}
		break;

		case ('B'):
				switch(menu())
				{
				case 1:
					cout << "Non-recursive inorder traversal:\n";
					t.inorder_NonRecur(n);
					break;

				case 2:
					cout << "Non-recursive preorder traversal:\n";
					t.preorder_NonRecur(n);
					break;

				case 3:
					cout << "Non-recursive postorder traversal:\n";
					t.postorder_NonRecur(n);
					break;
				}
		break;

		case ('C' || 'c'):
				return 0;
		break;
		}
	}while((ch == 'a') || (ch == 'A') || (ch == 'b') || (ch == 'B'));
}

