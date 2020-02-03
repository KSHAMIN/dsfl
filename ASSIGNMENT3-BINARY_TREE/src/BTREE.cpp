

#include "BTREE.h"
#include <iostream>
#include<queue>
using namespace std;


///////////////////////////////////////////////////////////
template <class T>
BTREE<T>::BTREE() {
	ROOT = NULL;
	// TODO Auto-generated constructor stub

}

template <class T>
BTREE<T>::~BTREE() {
	// TODO Auto-generated destructor stub
}
/////////////////////////////////////////////////////////////
template <class T>
TREENODE<T>::TREENODE(T D) {
	DATA=D;
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
TREENODE<T>* BTREE<T>::INSERT()
{	TREENODE<T> OBJ('\0');
	int CH=0;
	char c;
	T D;
	int F=0;
	TREENODE<T> *PTR=ROOT;
	if(ISEMPTY())
	{	cout<<"\nBINARY TREE IS EMPTY !!!\n";
		cout<<"\nENTER THE DATA OF THE NEW NODE: \n";
		cin>>D;
		cout<<"\n**** NEW \"ROOT NODE\" IS CREATED ****\n";
		TREENODE<T> *N = new TREENODE<T>(D);
		ROOT=N;
		return ROOT;
	}
	else
	{	cout<<"\nENTER THE DATA OF THE NEW NODE: \n";
		cin>>D;
		TREENODE<T> *N = new TREENODE<T>(D);
			do{
				cout<<"\nINSERT AT LEFT OF CURRENT NODE - \'1\'";
				cout<<"\nINSERT AT RIGHT OF CURRENT NODE - \'2\'";
				cout<<"\nCHOOSE WHERE DO YOU WANT TO INSERT THE NEW NODE [1,2]: ";
				cin>>CH;
				switch(CH)
				{
					case 1:	if(PTR->LEFT==NULL)
							{	PTR->LEFT=N;
								cout<<"\n**** \"NEW NODE\" IS SUCCESSFULLY INSERTED ****\n";
								F = 1;
							}
							else
							{	cout<<"\nA \"LEFT SUB-TREE\" IS ALREADY PRESENT !!";
								cout<<"\n*** MOVING TO THE NEXT NODE ***\n";
								PTR=PTR->LEFT;
							}
							break;
					case 2: if(PTR->RIGHT==NULL)
							{	PTR->RIGHT=N;
								cout<<"\n**** \"NEW NODE\" IS SUCCESSFULLY INSERTED ****\n";
								F = 1;
							}
							else
							{	cout<<"\nA \"RIGHT SUB-TREE\" IS ALREADY PRESENT !!";
								cout<<"\n*** MOVING TO THE NEXT NODE ***\n";
								PTR=PTR->RIGHT;
							}
							break;
			  	   default: cout<<"\nWRONG CHOICE !!!";
							break;
				}
				if((CH!=1) && (CH!=2))
				{	cout<<"\n\nDO YOU WANT TO CHOOSE ANY OTHER POSITION FROM INSERTION MENU ";
					cout<<"[PRESS \'Y\' FOR YES AND \'N\' FOR NO]: ";
					cin>>c;
				}
			}while(c=='Y'||c=='y'|| F==0);
	}
	return ROOT;
}

/////////////////////////////////////////////////////////////
template <class T>
bool BTREE<T>::ISEMPTY()
{
	return (ROOT==NULL);
}

/////////////////////////////////////////////////////////////

template <class T>
void BTREE<T>::DISPLAY_BTREE()
{	TREENODE<T> *PTR=ROOT;
	queue<TREENODE<T>*>Q;
	Q.push(PTR);
	while(!Q.empty()){
		PTR=Q.front();
		cout<<" "<<PTR->RETURN_DATA();
		Q.pop();
		if(PTR->LEFT!=NULL)
		Q.push(PTR->LEFT);
		if(PTR->RIGHT!=NULL)
		Q.push(PTR->RIGHT);
	}
}

/////////////////////////////////////////////////////////////

template <class T>
T TREENODE<T>::RETURN_DATA()
{
	return DATA;
}

/////////////////////////////////////////////////////////////

template <class T>
int BTREE<T>::DISPLAY_DEPTH(TREENODE<T> *P)
{	   if (P == NULL)
	        return 0;
	    else
	    {
	        /* compute the depth of each subtree */
	        int LEFT_SUB_TREE_DEPTH = DISPLAY_DEPTH(P->LEFT);
	        int RIGHT_SUB_TREE_DEPTH = DISPLAY_DEPTH(P->RIGHT);

	        /* use the larger one */
	        if (LEFT_SUB_TREE_DEPTH > RIGHT_SUB_TREE_DEPTH)
	            return(LEFT_SUB_TREE_DEPTH + 1);
	        else return(RIGHT_SUB_TREE_DEPTH + 1);
	    }
}

/////////////////////////////////////////////////////////////
template <class T>
void BTREE<T>::DISPLAY_LEAF_NODE(TREENODE<T> *P)
{
	if (P==NULL) {
	      return;
	    }

	if((P->RIGHT==NULL) && (P->LEFT==NULL))
		cout<<" "<<P->RETURN_DATA();

	DISPLAY_LEAF_NODE(P->LEFT);
	DISPLAY_LEAF_NODE(P->RIGHT);
}

/////////////////////////////////////////////////////////////

template <class T>
TREENODE<T>* BTREE<T>::COPY_TREE(TREENODE<T>* R)
{
	if(R==NULL)
	return NULL;

	TREENODE<T> *H= new TREENODE<T>(R->DATA);

	if(R->LEFT!=NULL)
	{
		H->LEFT=COPY_TREE(R->LEFT);
	}
	if(R->RIGHT!=NULL)
	{
		H->RIGHT=COPY_TREE(R->RIGHT);
	}

	return H;
}

/////////////////////////////////////////////////////////////


template <class T>
void BTREE<T>::ASSIGN_ROOT_NODE(TREENODE<T>* R)
{
	ROOT = R;
}

