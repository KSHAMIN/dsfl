//============================================================================
// Name        : ass1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Stack.h"
#include <bits/stdc++.h>
using namespace std;

class Exp
{
public:
	string InfixToPost(string,bool);
	string InfixToPre(string,bool);
	int post_eval(string);
	int pre_eval(string);
};

int prec(char c)
{
	if((c == '+') || (c == '-'))
		return 1;
	if((c == '*') || (c == '/') || (c == '%'))
		return 2;
	if(c == '^')
		return 3;
	return 0;
}


string Exp::InfixToPost(string infix,bool dec)
{
	Stack st;
	int j=0;
	char postfix[infix.length()];
	int l = infix.length();
	for(int i=0;i<l;i++)
	{
		if(((infix[i] >= 'a') && (infix[i] <= 'z')) || ((infix[i] >= 'A') && (infix[i] <= 'Z')) || ((infix[i] >= '0') && (infix[i] <= '9')))
			postfix[j++] = infix[i];
		else if(infix[i] == ')')
		{
			try
			{
				while(st.peep() != '(')
					postfix[j++] = st.pop();
				st.pop();
			}catch(...)
			{
				cout << "\n*****You have entered invalid expression!*****\n";
			}
		}
		else
		{
			if(!st.IsEmpty() && (prec(infix[i]) < prec(st.peep()) || (prec(infix[i]) == prec(st.peep()) && dec)) && st.peep() != '(' && infix[i] != '(')
				postfix[j++] = st.pop();
			st.push(infix[i]);
		}
	}
	while(!st.IsEmpty())
	{
		if(st.peep() != '(')
			postfix[j++] = st.pop();
		else
			st.pop();
	}
	//j--;
	postfix[j] = '\0';
	return postfix;
}

string Exp::InfixToPre(string infix,bool dec)
{
	Stack st;
		int j=0;
		char prefix[infix.length()];
		reverse(infix.begin(),infix.end());
		int l = infix.length();
		for(int i=0;i<l;i++)
		{
			if(((infix[i] >= 'a') && (infix[i] <= 'z')) || ((infix[i] >= 'A') && (infix[i] <= 'Z')) || ((infix[i] >= '0') && (infix[i] <= '9')))
				prefix[j++] = infix[i];
			else if(infix[i] == '(')
			{
				try
				{
					while(st.peep() != ')')
						prefix[j++] = st.pop();
					st.pop();
				}catch(...)
				{
					cout << "\n*****You have entered invalid expression!*****\n";
				}
			}
			else
			{
				if(!st.IsEmpty() && (prec(infix[i]) < prec(st.peep()) || (prec(infix[i]) == prec(st.peep()) && dec)) && st.peep() != ')' && infix[i] != ')')
					prefix[j++] = st.pop();
				st.push(infix[i]);
			}
		}
		while(!st.IsEmpty())
		{
			if(st.peep() != ')')
				prefix[j++] = st.pop();
			else
				st.pop();
		}
		//j--;
		prefix[j] = '\0';
		return prefix;
}

int res(int x,int y,char op)
{
	switch(op)
	{
	case '+':
		return (x + y);
	case '-':
		return (x - y);
	case '*':
		return (x * y);
	case '/':
		return (x / y);
	case '^':
		return (x ^ y);
	}
}

int Exp::pre_eval(string pre)
{
	Stack st;
	int i = 0;
	char a,b;
	for(i = 0;i < pre.length();i++)
	{
		if((pre[i] >= '0') && (pre[i] <= '9'))
			st.push(pre[i] - '0');
		else
		{
			a = st.pop();
			b = st.pop();
			st.push(res(b,a,pre[i]));
		}
	}
	return st.pop();
}

int Exp::post_eval(string post)
{
	Stack st;
	int i = 0;
	for(i = 0;i < post.length();i++)
	{
		if((post[i] >= '0') && (post[i] <= '9'))
			st.push(post[i] - '0');
		else
			st.push(res(st.pop(),st.pop(),post[i]));
	}
	return st.pop();
}

int menu()
{
	int r;
	cout << "\n*****MENU*****\n";
	cout << "\n1)Enter string\n2)Convert string to postfix expression\n3)Convert string to prefix expression\n4)Evaluate postfix expression\n5)Evaluate prefix expression\n6)Exit\n";
	cout << "\n\nEnter your choice:";
	cin >> r;
	return r;
}

int main()
{
	Exp e;
	string in,post,pre;
	int t=1;
	while(t)
	{
		switch(menu())
		{
		case 1:
			cout << "\nEnter the infix expression: ";
			cin >> in;
			break;
		case 2:
			post = e.InfixToPost(in,true);
			cout << "\nPostfix expression is: " << post << endl;
			break;
		case 3:
			pre = e.InfixToPre(in,false);
			reverse(pre.begin(),pre.end());
			cout << "\nPrefix expression is: " << pre << endl;
			break;
		case 4:
			cout << "\nEvaluation is: " << e.post_eval(post) << endl;
			break;
		case 5:
			reverse(pre.begin(),pre.end());
			cout << "\nEvaluation is: " << e.pre_eval(pre) << endl;
			break;
		case 6:
			return 0;
			break;
		default: cout << "\n*****WRONG CHOICE ENTERED*****\n";
		}
	}
}
