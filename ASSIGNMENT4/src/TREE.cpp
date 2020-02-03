

#include "TREE.h"
#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctype.h>
#include<stack>
using namespace std;
///////////////////////////////////////////////////////////
template <class T>
TREE<T>::TREE() {
	ROOT = NULL;
	// TODO Auto-generated constructor stub

}

template <class T>
TREE<T>::~TREE() {
	// TODO Auto-generated destructor stub
}
/////////////////////////////////////////////////////////////
template <class T>
TREENODE<T>::TREENODE() {
	LEFT = NULL;
	RIGHT = NULL;
	// TODO Auto-generated constructor stub

}

template <class T>
TREENODE<T>::~TREENODE() {
	// TODO Auto-generated destructor stub
}
/////////////////////////////////////////////////////////////
template <class T>

bool ISOPERAND(char C)
{
	return ((C>='a' && C<='z') || (C>='A' && C<='Z'));
}

/////////////////////////////////////////////////////////////
//ISOPERATOR() FUNCTION DEFINITION
template <class T>
bool TREE<T>::ISOPERATOR(char c)
{	return (c=='+' || c=='*' || c=='-' || c=='/');
}


/////////////////////////////////////////////////////////////
template <class T>
TREENODE<T>* TREE<T>::EXPRESSION_TREE(string POSTFIX)
{	stack<TREENODE<T>*> S;
	int LEN=POSTFIX.length();
	int i;
	for(i=0;i<LEN;i++)
	{
		if(ISOPERATOR(POSTFIX[i]))
		{
			TREENODE<T> *N =  new TREENODE<T>;
			N->DATA=POSTFIX[i];
			N->RIGHT=S.top();
			S.pop();
			N->LEFT=S.top();
			S.pop();
			S.push(N);
		}

		else
		{
			TREENODE<T> *N =  new TREENODE<T>;
			N->DATA=POSTFIX[i];
			S.push(N);
		}

	}

	ROOT = S.top();
	S.pop();

	return ROOT;

}

/////////////////////////////////////////////////////////////
template <class T>
void TREE<T>::INORDER_TRAVERSAL_RECURSIVE(TREENODE<T> *PTR)
{
	if(PTR)
	{
		INORDER_TRAVERSAL_RECURSIVE(PTR->LEFT);
			cout<<" "<<PTR->DATA<<endl;
		INORDER_TRAVERSAL_RECURSIVE(PTR->RIGHT);
	}
}

/////////////////////////////////////////////////////////////
template <class T>
void TREE<T>::POSTORDER_TRAVERSAL_RECURSIVE(TREENODE<T> *PTR)
{
	if(PTR)
	{
		PREORDER_TRAVERSAL_RECURSIVE(PTR->LEFT);
		PREORDER_TRAVERSAL_RECURSIVE(PTR->RIGHT);
		cout<<" "<<PTR->DATA<<endl;
		
	}
}

/////////////////////////////////////////////////////////////
template <class T>
void TREE<T>::PREORDER_TRAVERSAL_RECURSIVE(TREENODE<T> *PTR)
{	if(PTR)
	{
		cout<<" "<<PTR->DATA<<endl;
		POSTORDER_TRAVERSAL_RECURSIVE(PTR->LEFT);
		POSTORDER_TRAVERSAL_RECURSIVE(PTR->RIGHT);
	}
}
/////////////////////////////////////////////////////////////
template <class T>
void TREE<T>::PREORDER_TRAVERSAL_NON_RECURSIVE(TREENODE<T> *R)
{	stack<TREENODE<T>*> S;
	S.push(R);
	while(!S.empty())
	{	TREENODE<T>* temp=S.top();
		S.pop();
		cout<<" "<<temp->DATA<<endl;
		if(temp->RIGHT)
		S.push(temp->RIGHT);
		if(temp->LEFT)
		S.push(temp->LEFT);
	}
}

/////////////////////////////////////////////////////////////
template <class T>
void TREE<T>::POSTORDER_TRAVERSAL_NON_RECURSIVE(TREENODE<T> *R)
{
	stack<TREENODE<T>*> S1,S2;
	if(R==NULL)
		return;
	S1.push(R);
	TREENODE<T> *O;
	while(!S1.empty())
	{
		O = S1.top();
		S1.pop();
		S2.push(O);
		if(O->LEFT)
			S1.push(O->LEFT);
		if(O->RIGHT)
			S1.push(O->RIGHT);
	}

	while(!S2.empty())
	{
		O=S2.top();
		S2.pop();
		cout<<" "<<O->DATA<<endl;
	}

} 

/////////////////////////////////////////////////////////////
template <class T>
void TREE<T>::INORDER_TRAVERSAL_NON_RECURSIVE(TREENODE<T> *R)
{
	TREENODE<T> *temp=R;
	stack<TREENODE<T>*> S;
	while((temp!=NULL)||(S.empty()==false))
	{
		while(temp)
		{
			S.push(temp);
			temp=temp->LEFT;
		}
		temp = S.top();
		S.pop();
		cout<<" "<<temp->DATA<<endl;
			temp=temp->RIGHT;
   }
}
	
