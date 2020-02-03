


#include "BSTREE.h"
#include <iostream>
#include<queue>
using namespace std;


///////////////////////////////////////////////////////////

template <class T>
BSTREE<T>::BSTREE() {
	ROOT = NULL;
	// TODO Auto-generated constructor stub

}

///////////////////////////////////////////////////////////

template <class T>
BSTREE<T>::~BSTREE() {
	// TODO Auto-generated destructor stub
}

/////////////////////////////////////////////////////////////
template <class T>

TREENODE<T>::TREENODE() {

	LEFT = NULL;
	RIGHT = NULL;
	// TODO Auto-generated constructor stub

}

///////////////////////////////////////////////////////////

template <class T>
TREENODE<T>::~TREENODE() {
	// TODO Auto-generated destructor stub
}

/////////////////////////////////////////////////////////////

template <class T>
void BSTREE<T>::INSERT(TREENODE<T>* ROOT,TREENODE<T>* NODE_LOCATION,TREENODE<T>* PARENT_NODE,T KEY) {

	SEARCH_BSTREE(ROOT,NODE_LOCATION,PARENT_NODE,KEY);

	if(NODE_LOCATION!=NULL)
	{
		cout<<"\nA NODE WITH DATA "<<KEY<<" IS ALREADY PRESENT IN THE BINARY SEARCH TREE !!";
		return;
	}
	else{
		cout<<PARENT_NODE->DATA;
		TREENODE<T> *N = new TREENODE<T>;
		N->DATA=KEY;

		if(ROOT==NULL)
		{	ROOT=N;
			cout<<"\n**** ROOT NODE SUCCESSFULLY CREATED ****\n";
			return;
		}
		/*		else if(N->DATA<(PARENT_NODE->DATA))
		{	PARENT_NODE->LEFT=N;
			cout<<"\n**** NEW NODE SUCCESSFULLY CREATED ****\n";
			return;
		}
		else
		{	PARENT_NODE->RIGHT=N;
			cout<<"\n**** NEW NODE SUCCESSFULLY CREATED ****\n";
			return;
		}*/

	}
}

/////////////////////////////////////////////////////////////

template <class T>
void BSTREE<T>::DELETE_NODE_WITH_1_CHILD_OR_LEAF_NODE(TREENODE<T>* ROOT,TREENODE<T>* NODE_LOCATION,TREENODE<T>* PARENT_NODE,T KEY) {

	TREENODE<T> *CHILD;

	if((NODE_LOCATION->LEFT==NULL) && (NODE_LOCATION->RIGHT==NULL))
		CHILD=NULL;
	else if(NODE_LOCATION->LEFT!=NULL)
		CHILD=NODE_LOCATION->LEFT;
	else
		CHILD=NODE_LOCATION->RIGHT;
	if(PARENT_NODE!=NULL)
	{
		if(NODE_LOCATION==PARENT_NODE->LEFT)
			PARENT_NODE->LEFT=CHILD;
		else
			PARENT_NODE->RIGHT=CHILD;
	}

	else
		ROOT=CHILD;
}
/////////////////////////////////////////////////////////////

template <class T>
void BSTREE<T>::DELETE_NODE_WITH_2_CHILDREN(TREENODE<T>* ROOT,TREENODE<T>* NODE_LOCATION,TREENODE<T>* PARENT_NODE,T KEY) {


	TREENODE<T> *P1,*P2;
	P1=NODE_LOCATION;
	P2=NODE_LOCATION->RIGHT;
	while(P2->LEFT!=NULL)
	{	P1=P2;
		P2=P2->LEFT;
	}
	NODE_LOCATION->DATA=P2->DATA;
	DELETE_NODE_WITH_1_CHILD_OR_LEAF_NODE(ROOT,P2,P1,KEY);
}
/////////////////////////////////////////////////////////////

template <class T>
void BSTREE<T>::SEARCH_BSTREE(TREENODE<T>* ROOT,TREENODE<T>* NODE_LOCATION,TREENODE<T>* PARENT_NODE,T KEY){
	TREENODE<T> *PTR = ROOT;
	if(ROOT==NULL)
	{	cout<<"\nBINARY SEARCH TREE DOES NOT EXIST !!\n";
		NODE_LOCATION=NULL;
		PARENT_NODE=NULL;
		return;
	}

	while(PTR!=NULL)
	{	if(KEY==(PTR->DATA))
		{	NODE_LOCATION=PTR;
			cout<<"\nA NODE WITH DATA "<<KEY<<" IS PRESENT IN THE BINARY SEARCH TREE";
			cout<<" HAVING IT'S PARENT NODE WITH DATA "<<PTR->DATA;
			return;
		}

		else if(KEY<(PTR->DATA))
			{	PARENT_NODE=PTR;
				PTR=PTR->LEFT;
			}

		else
			{	PARENT_NODE=PTR;
				PTR=PTR->RIGHT;
			}
	}

	if(NODE_LOCATION==NULL)
		cout<<"NO SUCH NODE WITH DATA: "<<KEY<<" IS PRESENT IN THE BINARY SEARCH TREE !!";
}


/////////////////////////////////////////////////////////////

template <class T>
int BSTREE<T>::DISPLAY_HEIGHT(TREENODE<T> *P)
{	   if (P == NULL)
	        return 0;
	    else
	    {
	        /* compute the height of each subtree */
	        int LEFT_SUB_TREE_DEPTH = DISPLAY_HEIGHT(P->LEFT);
	        int RIGHT_SUB_TREE_DEPTH = DISPLAY_HEIGHT(P->RIGHT);

	        /* use the larger one */
	        if (LEFT_SUB_TREE_DEPTH > RIGHT_SUB_TREE_DEPTH)
	            return(LEFT_SUB_TREE_DEPTH + 1);
	        else return(RIGHT_SUB_TREE_DEPTH + 1);
	    }
}

/////////////////////////////////////////////////////////////

template <class T>
void BSTREE<T>::DISPLAY_BSTREE(TREENODE<T> *PTR)
{
	if(PTR)
		{
			DISPLAY_BSTREE(PTR->LEFT);
			cout<<" "<<PTR->DATA<<endl;
			DISPLAY_BSTREE(PTR->RIGHT);
		}
}

/////////////////////////////////////////////////////////////

template <class T>
void BSTREE<T>:: DISPLAY_LEVEL_ORDER(TREENODE<T> *R)
{
	if(R==NULL)
		return;
	queue<TREENODE<T>*> Q;
	TREENODE<T> *CURRENT;
	Q.push(R);
	Q.push(NULL);
	while(Q.size()>1)
	{
		CURRENT=Q.front();
		Q.pop();
		if(CURRENT==NULL)
		{	Q.push(NULL);
			cout<<"\n";
		}
		else
		{	if(CURRENT->LEFT)
				Q.push(CURRENT->LEFT);
			if(CURRENT->RIGHT)
				Q.push(CURRENT->RIGHT);
			cout<<" "<<CURRENT->DATA<<endl;
		}
	}
}

/////////////////////////////////////////////////////////////

template <class T>
void BSTREE<T>::MIRROR_BST(TREENODE<T> *R)
{
	if(R==NULL)
		return;
	else
	{
		TREENODE<T> *TEMP;
		MIRROR_BST(R->LEFT);
		MIRROR_BST(R->RIGHT);
		TEMP=R->LEFT;
		R->LEFT=R->RIGHT;
		R->RIGHT=TEMP;
	}
}

/////////////////////////////////////////////////////////////

template <class T>
TREENODE<T>* TREENODE<T>::RETURN_L(TREENODE<T> *P)
{	return  P->LEFT;
	}

/////////////////////////////////////////////////////////////

template <class T>
TREENODE<T>* TREENODE<T>::RETURN_R(TREENODE<T> *P)
{	return  P->RIGHT;
	}
