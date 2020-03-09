/*
 * GRAPH.cpp
 *
 *  Created on: 14-Feb-2020
 *      Author: dsfle-9
 */

#include "GRAPH.h"
#include <map>
#include<iostream>
#include<queue>
using namespace std;


//////////////////////////////////////////////CLASS DATE
DATE::DATE(){
	D=0;
	MONTH=0;
	YEAR=0;
	// TODO Auto-generated constructor stub
}

DATE::~DATE(){
	// TODO Auto-generated destructor stub
}

void DATE::ADD_DATE(int DD,int MM,int YY)
{	D=DD;
	MONTH=MM;
	YEAR=YY;
}

//////////////////////////////////////////////CLASS ACCOUNT
ACCOUNT::ACCOUNT() {
	NAME="";
	NEXT=NULL;
	ID=-1;
	DLINK=NULL;
	// TODO Auto-generated constructor stub
}


ACCOUNT::~ACCOUNT() {

	// TODO Auto-generated destructor stub
}

//////////////////////////////////////////////CLASS FRIENDS
FRIENDS::FRIENDS() {
	SOURCE=NULL;
	COMMENTS=-1;
	NEW=NULL;
	// TODO Auto-generated constructor stub
}

FRIENDS::~FRIENDS() {
	// TODO Auto-generated destructor stub
}

///////////////////////////////////////////////CLASS GRAPH
GRAPH::GRAPH() {
	ALIST=NULL;
	// TODO Auto-generated constructor stub
}

GRAPH::~GRAPH() {
	//delete []ARR;
	// TODO Auto-generated destructor stub
}

void GRAPH::CREATE_GRAPH(string N,int I,int DDD,int MMM,int YYY){

	if(ALIST==NULL)
	{	ALIST=new ACCOUNT;
		ALIST->NAME=N;
		ALIST->DOB.ADD_DATE(DDD,MMM,YYY);
		ALIST->ID=I;
		ALIST->NEXT=NULL;
		ALIST->DLINK=NULL;

	}

	else{	ACCOUNT *P=ALIST;
			ACCOUNT *Q=ALIST;
			ACCOUNT *TEMP=new ACCOUNT;
			TEMP->NAME=N;
			TEMP->DOB.ADD_DATE(DDD,MMM,YYY);
			TEMP->ID=I;
			TEMP->NEXT=NULL;
			TEMP->DLINK=NULL;
			while(P)
			{	Q=P;
				P=P->DLINK;
			}
			Q->DLINK=TEMP;
	}

}

void GRAPH::INSERT_FRIEND(string SRC,string DES) {
	if(!ALIST)
	{
		cout<<"\nNO ACCOUNTS ARE REGISTERED ON FACEBOOK !!";
		cout<<"\nWE CANNOT ADD A NEW FRIEND!!!";
		cout<<"\nFIRST REGISTER ACCOUNTS ON FACEBOOK BY CHOOSING OPTION - \'1\' FROM FACEBOOK MENU";
	}

	else
	{
		ACCOUNT *P=ALIST;
		ACCOUNT *Q=ALIST;
		if(P->NAME==SRC)
		{
			while(P)
			{	//Q=P;
				P=P->DLINK;
				if(P->NAME==DES)
					break;
			}
			if(P)
			{	FRIENDS *N= new FRIENDS;
				FRIENDS *M= new FRIENDS;
				cout<<"\n***** A NEW FRIEND IS SUCCESSFULLY ADDED TO \""<<Q->NAME<<"\" *****\n";
				cout<<"\nENTER THE NUMBER OF COMMENTS DONE BY "<<P->NAME<<" FOR "<<Q->NAME<<": ";
				cin>>N->COMMENTS;
				if(!Q->NEXT)
				{	Q->NEXT=N;
					N->SOURCE=P;
					N->NEW=NULL;
				}
				else{
						FRIENDS *TEMP=Q->NEXT;
						while(TEMP->NEW)
						{	TEMP=TEMP->NEW;
						}
						TEMP->NEW=N;
						N->SOURCE=P;
						N->NEW=NULL;
					}
				cout<<"\n***** A NEW FRIEND IS SUCCESSFULLY ADDED TO \""<<P->NAME<<"\" *****\n";
				cout<<"\nENTER THE NUMBER OF COMMENTS DONE BY "<<Q->NAME<<" FOR "<<P->NAME<<": ";
				cin>>M->COMMENTS;
				if(!P->NEXT)
				{	P->NEXT=M;
					M->SOURCE=Q;
					M->NEW=NULL;
				}
				else{
						FRIENDS *TEMP=P->NEXT;
						while(TEMP->NEW)
						{	TEMP=TEMP->NEW;
						}
						TEMP->NEW=M;
						M->SOURCE=Q;
						M->NEW=NULL;
					}
			}
		}
		else
		{
			ACCOUNT *P=ALIST;
			ACCOUNT *Q=ALIST;
			while(P)
			{	P=P->DLINK;
				if(P->NAME==SRC)
					break;
			}

			Q=P;
			P=ALIST;
			while(P)
			{	P=P->DLINK;
				if(P->NAME==DES)
					break;
			}

			if(P)
			{	FRIENDS *N= new FRIENDS;
				FRIENDS *M= new FRIENDS;
				cout<<"\n***** A NEW FRIEND IS SUCCESSFULLY ADDED TO \""<<Q->NAME<<"\" *****\n";
				cout<<"\nENTER THE NUMBER OF COMMENTS DONE BY "<<P->NAME<<" FOR "<<Q->NAME<<": ";
				cin>>N->COMMENTS;
				if(!Q->NEXT)
				{	Q->NEXT=N;
					N->SOURCE=P;
					N->NEW=NULL;
				}
				else{
						FRIENDS *TEMP=Q->NEXT;
						while(TEMP->NEW)
						{	TEMP=TEMP->NEW;
						}
						TEMP->NEW=N;
						N->SOURCE=P;
						N->NEW=NULL;
					}
				cout<<"\n***** A NEW FRIEND IS SUCCESSFULLY ADDED TO \""<<P->NAME<<"\" *****\n";
				cout<<"\nENTER THE NUMBER OF COMMENTS DONE BY "<<Q->NAME<<" FOR "<<P->NAME<<": ";
				cin>>M->COMMENTS;
				if(!P->NEXT)
				{	P->NEXT=M;
					M->SOURCE=Q;
					M->NEW=NULL;
				}
				else{
						FRIENDS *TEMP=P->NEXT;
						while(TEMP->NEW)
						{	TEMP=TEMP->NEW;
						}
						TEMP->NEW=M;
						M->SOURCE=Q;
						M->NEW=NULL;
					}
			}
		}
	}
}

void GRAPH::DISPLAY_NAME()
{	ACCOUNT *P=ALIST;
	cout<<"\n**************************";
	cout<<"\n  AVAILABLE CHOICES";
	cout<<"\n**************************\n";
	while(P)
	{	cout<<" 	"<<P->NAME<<endl;
		P=P->DLINK;
	}


}


bool GRAPH::VALIDATE_FRIEND(string S,string D)
{	ACCOUNT *T = ALIST;

	while(T)
	{	if(T->NAME==S)
		break;
		T=T->DLINK;

	}
	FRIENDS *M = T->NEXT;
	while(M)
	{	if((M->SOURCE)->NAME==D)
		break;
		M=M->NEW;
	}
		if(M)
			return true;
		return false;
	}
bool GRAPH::VALIDATE_NAME(string S,string D)
{	ACCOUNT *T = ALIST;
	int F=0;
	while(T)
	{
		if(T->NAME==S)
		{	F=1;
			break;
		}
		if( T->NAME==D)
		{	F=2;
			break;
		}
		T=T->DLINK;
	}

	if(F==1)
	{	T=ALIST;
		while(T)
		{	if( T->NAME==D)
			{	return true;
			}
		T=T->DLINK;
		}
	}
	if(F==2)
		{	T=ALIST;
			while(T)
			{	if( T->NAME==S)
				{	return true;
				}
			T=T->DLINK;
			}
		}
	return false;
}

void GRAPH::BFS(int V)
{
	ACCOUNT *T = ALIST;
	ACCOUNT *P = ALIST;
	ACCOUNT *B = ALIST;
	FRIENDS *M = NULL;
	queue<ACCOUNT*>Q;
	bool *VISITED = new bool[V];
	for(int i=0;i<V;i++)
		VISITED[i]=false;

	VISITED[(P->ID)-1]=true;
	Q.push(P);
	cout<<endl;
	while(!Q.empty())
	{
		T=Q.front();
		cout<<"		(((("<<T->NAME<<"))))	";
		M=T->NEXT;
		while(M)
		{
			B=M->SOURCE;

			if(!VISITED[(B->ID)-1])
			{	VISITED[(B->ID)-1]=true;
				Q.push(B);
			}
			M=M->NEW;
		}
	}

}
