//============================================================================
// Name        : LINKEDLIST.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class NODE{
	NODE *NEXT;
	int DATA;
public:
	NODE()
{	NEXT=NULL;
	DATA=-999;
		}
friend class LIST;
};

class LIST{
	NODE *HEAD;
public:
	LIST()
{	HEAD=NULL;
}


void CREATENODE(int);
void DISPLAY();
void DELETE(int);
};





void LIST::CREATENODE(int P)
{	int a=1;
	NODE *TEMP;

	if(HEAD==NULL)
	{	HEAD=new NODE;
		cout<<"\nLIST IS EMPTY!!";
		cout<<"\nENTER THE DATA YOU WANT TO INSERT AT \"HEAD NODE\": ";
		cin>>HEAD->DATA;
	}

	else if(P==1)
	{	TEMP=new NODE;
			cout<<"\nENTER THE DATA YOU WANT TO INSERT AT \"1st NODE\": ";
			cin>>TEMP->DATA;
			TEMP->NEXT=HEAD;
			HEAD=TEMP;
	}
	else{


		TEMP=HEAD;
		NODE* N = new NODE;
		cout<<"\nENTER THE DATA YOU WANT TO INSERT AT \"NODE - "<<P<<"\": ";
		cin>>N->DATA;


		while((TEMP!=NULL) &&(a<P-1))
		{
			TEMP=TEMP->NEXT;
			a++;
		}
		N->NEXT=TEMP->NEXT;
		TEMP->NEXT=N;
	}
}

void LIST::DISPLAY()
{
	if(HEAD==NULL)
	{
		cout<<"\nLIST IS EMPTY!!";
	}
	else
	{
		NODE *TEMP=HEAD;
		while(TEMP!=NULL)
		{
			cout<<"|__"<<TEMP->DATA<<"__|";
			TEMP=TEMP->NEXT;
			cout<<"--->";
		}
		cout<<"NULL\n";

	}
}

void LIST::DELETE(int P)
{	int a=1;
	if(HEAD==NULL)
		cout<<"\nLIST IS EMPTY!!";
	else if(P==1)
	{
		cout<<"\nTHE DATA: "<<(HEAD->DATA)<<" IS DELETED FROM THE LINKED LIST";

			HEAD=(HEAD->NEXT);
			delete (HEAD);


	}
	else
	{	NODE *TEMP=HEAD;

	while((TEMP!=NULL) &&(a<P-1))
			{
				TEMP=TEMP->NEXT;
				a++;
			}
	cout<<"\nTHE DATA: "<<(TEMP->NEXT)->DATA<<" IS DELETED FROM THE LINKED LIST";

	TEMP->NEXT=(TEMP->NEXT)->NEXT;
	delete (TEMP->NEXT);
	}





}





int main() {
	int CH,pos,count=0;
	char c;
	LIST L;
	do{
			cout<<"\n************************** PROGRAM MENU **************************\n";
			cout<<"1.INSERT A NODE\n2.DISPLAY LINKED LIST\n3.DELETE A NODE\n4.EXIT";
			cout<<"\nENTER YOUR CHOICE [1,2,3,4]: ";
			cin>>CH;
			switch(CH)
			{
				case 1: cout<<"\n*********** INSERT A NODE ***********\n";
						count++;
						cout<<"ENTER THE POSITION WHERE YOU WANT TO INSERT THE NODE[1,2,...]: ";
						cin>>pos;
						while(pos>count+1)
						{
							cout<<"\nTHE LINKED LIST ONLY CONTAINS ONLY "<<count<<" NODES!!";
							cout<<"\nENTER APPROPRIATE POSITION !!";
							cout<<"ENTER THE POSITION WHERE YOU WANT TO INSERT THE NODE[1,2,...count+1]: ";
							cin>>pos;
						}
						L.CREATENODE(pos);
						break;
				case 2: cout<<"\n*********** DISPLAYING LINKED LIST ***********\n\n";
						L.DISPLAY();
						break;
				case 3: cout<<"\n*********** DELETE A NODE ***********\n";
						L.DISPLAY();
						cout<<"\nENTER THE POSITION OF THE NODE YOU WANT TO DELETE[1,2,...]: ";
						cin>>pos;
						while(pos>count+1)
						{
							cout<<"\nTHE LINKED LIST ONLY CONTAINS ONLY "<<count<<" NODES!!";
							cout<<"\nENTER APPROPRIATE POSITION !!";
							cout<<"\nENTER THE POSITION OF THE NODE YOU WANT TO DELETE[1,2,...]: ";
							cin>>pos;
						}
						L.DELETE(pos);
						break;
				case 4: cout<<"\nYOU HAVE CHOSEN TO EXIT !!\n";
						break;

				default: cout<<"\nYOU CHOOSE A WRONG OPTION !!";
						 break;

			}

			if(CH>=1 && CH<4)
			{
				cout<<"\n\nDO YOU WANT TO CHOOSE ANY OTHER OPTION FROM PROGRAM MENU ";
				cout<<"[PRESS \'Y\' FOR YES AND \'N\' FOR NO]: ";
				cin>>c;
			}
			else if(CH==4)
				break;
	}while(c=='Y'||c=='y');


	return 0;
}
