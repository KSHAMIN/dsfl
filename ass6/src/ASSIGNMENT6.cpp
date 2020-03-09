//============================================================================
// Name        : ASSIGNMENT6.cpp
// Author      : ABHINAV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include"GRAPH.h"
#include<queue>
#include<stack>

class FACEBOOK{
	string Name;
	int Date,Month,Year,Id,Comments;
	GRAPH OBJECT;
	public:
			//FUNCTION DECLARATION
			FACEBOOK()
			{	Name="";
				Date=-1;
				Month=-1;
				Year=-1;
				Id=-1;
				Comments=-1;
			}
			void ADD_ACCOUNT()
			{
				cout<<"\nENTER THE NAME: ";
				cin>>Name;
				cout<<"\nENTER THE FACEBOOK-ID[1,2,3,4....]: ";
				cin>>Id;
				while(Id<=0)
				{	cout<<"\nYOU HAVE ENTERED AN INVALID FACEBOOK-ID!!\n";
					cout<<"\nENTER THE FACEBOOK-ID[1,2,3,4....]: ";
					cin>>Id;
				}
				cout<<"\nENTER THE DATE OF BIRTH";
				cout<<"\nENTER DATE [1,2,3....,31]: ";
				cin>>Date;
				while(Date<1 || Date>31)
				{	cout<<"\nYOU HAVE NOT ENTERED A VAILD DATE OF MONTH !!!";
					cout<<"\nRE-ENTER VALID DATE [1,2,3....,31]: ";
					cin>>Date;
				}
				cout<<"\nENTER MONTH [1,2,3....,12]: ";
				cin>>Month;
				while(Month<1 || Month>12)
				{	cout<<"\nYOU HAVE NOT ENTERED A VAILD MONTH OF YEAR !!!";
					cout<<"\nRE-ENTER VALID MONTH [1,2,3....,12]: ";
					cin>>Month;
				}
				cout<<"\nENTER YEAR: ";
				cin>>Year;
				while(Year<0)
				{	cout<<"\nYOU HAVE NOT ENTERED A VAILD YEAR !!!";
					cout<<"\nRE-ENTER VALID YEAR OF BIRTH: ";
					cin>>Year;
				}
				OBJECT.CREATE_GRAPH(Name,Id,Date,Month,Year);
			}

			void ADD_FRIEND(string S,string D)
			{
				OBJECT.INSERT_FRIEND(S,D);
				cout<<"\n";
			}
			void DISPLAY_PEOPLE()
			{

				OBJECT.DISPLAY_NAME();
			}
			void DISPLAY_PEOPLE_BFS(int VERTEX)
			{
				
				OBJECT.BFS(VERTEX);

			}
			bool VALID(string S,string D)
			{
				bool A= OBJECT.VALIDATE_NAME(S,D);
				return A;
			}

			bool VALID_FRIEND(string S,string D)
			{
				bool A= OBJECT.VALIDATE_FRIEND(S,D);
				return A;
			}

		/*	void DISPLAY_PEOPLE_DFS()
			{
				OBJECT.DFS(VERTEX);

			}
*/
			void FIND_MAX_FRIENDS()
			{

			}

			void FIND_MAX_COMM()
			{

			}
			void FIND_MIN_COMM()
			{

			}
			void SEARCH(string M)
			{

			}
};

/////////////////////////	MAIN BEGINS
int main() {
	int CH,COUNT=0,a=1,VER;
	char c;
	string DESTINATION="",SOURCE="",MONTH="";
		FACEBOOK F;


		do{
				cout<<"\n************************** FACEBOOK MENU **************************\n";
				cout<<"\n1.CREATE NEW ACCOUNT ON FACEBOOK";
				cout<<"\n2.ADD A NEW FRIEND ON FACEBOOK\n3.BREADTH FIRST SEARCH OF GRAPH";
				cout<<"\n4.DEPTH FIRST SEARCH OF GRAPH\n5.FIND A PERSON WITH MAXIMUM FRIENDS ON FACEBOOK";
				cout<<"\n6.FIND THE PERSON WHO HAS DONE MAXIMUM COMMENTS ON FACEBOOK";
				cout<<"\n7.FIND THE PERSON WHO HAS DONE MINIMUM COMMENTS ON FACEBOOK";
				cout<<"\n8.SEARCH PEOPLE BY \" MONTH OF BIRTH \" ON FACEBOOK";
				cout<<"\n9.EXIT";
				cout<<"\nENTER YOUR CHOICE [1,2,3,4,5,6,7,8]: ";
				cin>>CH;
				switch(CH)
				{
					case 1:cout<<"\n********** CREATE NEW ACCOUNT ON FACEBOOK **********\n";
							cout<<"\nENTER THR NUMBER OF PEOPLE YOU WANT TO CREATE NEW FACEBOOK ACCOUNT FOR: ";
							cin>>COUNT;
							VER=COUNT;
							while(a<=COUNT)
							{	cout<<"\n   PERSON - "<<a<<"\n";
								F.ADD_ACCOUNT();
								a++;
								cout<<"\n***** A NEW ACCOUNT IS SUCCESSFULLY REGISTERED ON FACEBOOK *****\n";
							}
							break;
					case 2: cout<<"\n***** ADD A NEW FRIEND ON FACEBOOK *****\n";
							F.DISPLAY_PEOPLE();
							cout<<"\nSELECT THE \"APPROPRIATE NAME\" OF A USER TO ADD HIM/HER AS A FRIEND TO ANOTHER USER WITH ALREADY EXISTING ACCOUNT";
							cout<<"\nENTER NAME OF FIRST USER: ";
							cin>>SOURCE;
							cout<<"\nENTER NAME OF THE FRIEND OF THE USER: ";
							cin>>DESTINATION;
		/*					while(!F.VALID(SOURCE,DESTINATION))
							{	cout<<"\nYOU HAVE NOT ENTERED A VALID NAME OF EITHER THE USER OR THE FRIEND!!";
								F.DISPLAY_PEOPLE();
								cout<<"\nSELECT THE \"APPROPRIATE NAME\" OF A USER TO ADD HIM/HER AS A FRIEND TO ANOTHER USER WITH ALREADY EXISTING ACCOUNT";
								cout<<"\nENTER NAME OF FIRST USER: ";
								cin>>SOURCE;
								cout<<"\nENTER NAME OF THE FRIEND OF THE USER: ";
								cin>>DESTINATION;
							}
							while(F.VALID_FRIEND(SOURCE,DESTINATION))
							{	cout<<"\nA USER WITH NAME "<<DESTINATION<<" IS ALREADY A FRIEND OF "<<SOURCE;
								cout<<"\nWE CANNOT SEND A NEW FRINED REQUEST OF "<<DESTINATION<<" TO "<<SOURCE<<" AGAIN!!!";
								cout<<"\nCHOOSE ANOTHER PERSON TO ADD HIM/HER AS A FRIEND TO "<<SOURCE;
								F.DISPLAY_PEOPLE();
								cout<<"\nSELECT THE \"APPROPRIATE NAME\" OF A USER TO ADD HIM/HER AS A FRIEND TO ANOTHER USER WITH ALREADY EXISTING ACCOUNT";
								cout<<"\nENTER NAME OF FIRST USER: ";
								cin>>SOURCE;
								cout<<"\nENTER NAME OF THE FRIEND OF THE USER: ";
								cin>>DESTINATION;
							}
*/
							F.ADD_FRIEND(SOURCE,DESTINATION);
							break;
					case 3: cout<<"\n***** BREADTH FIRST SEARCH OF GRAPH *****\n";
							F.DISPLAY_PEOPLE_BFS(VER);
							break;
					case 4: cout<<"\n***** DEPTH FIRST SEARCH OF GRAPH *****\n";
							//F.DISPLAY_PEOPLE_DFS(COUNT);
							break;
				    case 5: cout<<"\n***** FIND A PERSON WITH MAXIMUM FRIENDS ON FACEBOOK *****\n";
				    		F.FIND_MAX_FRIENDS();
							break;
				    case 6: cout<<"\n***** FIND THE PERSON WHO HAS DONE MAXIMUM COMMENTS ON FACEBOOK *****\n";
				    		F.FIND_MAX_COMM();
							break;
				    case 7: cout<<"\n***** FIND THE PERSON WHO HAS DONE MINIMUM COMMENTS ON FACEBOOK *****\n";
				    		F.FIND_MIN_COMM();
							break;
				    case 8: cout<<"\n***** SEARCH PEOPLE BY \" MONTH OF BIRTH \" ON FACEBOOK *****\n";
				    		cout<<"\nENTER THE MONTH OF AN YEAR: ";
				    		cin>>MONTH;
				    		F.SEARCH(MONTH);
				    	    break;
				    case 9: cout<<"\nYOU HAVE CHOSEN TO EXIT !!\n";
							break;
					default: cout<<"\nYOU CHOOSE A WRONG OPTION !!";
							 break;

				}
				if(CH>=1 && CH<9)
				{
					cout<<"\n\nDO YOU WANT TO CHOOSE ANY OTHER OPTION FROM PROGRAM MENU ";
					cout<<"[PRESS \'Y\' FOR YES AND \'N\' FOR NO]: ";
					cin>>c;
				}
				else if(CH==9)
					break;
		}while(c=='Y'||c=='y');

	return 0;
}
