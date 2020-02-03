//============================================================================
// Name        : ASSIGNMENT3-BINARY_TREE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "BTREE.h"
#include "BTREE.cpp"

/////////////////////////	MAIN BEGINS
	int main() {
		int CH,DEPTH=-1;
			char c,C;
			BTREE<char> T;
			BTREE<char> T1;
			TREENODE<char> *P=NULL;
			TREENODE<char> *P1=NULL;
			string POS;

			do{
					cout<<"\n************************** PROGRAM MENU **************************\n";
					cout<<"\n1.CREATE BINARY TREE \n2.DISPLAY BINARY TREE ";
					cout<<"\n3.DISPLAY THE DEPTH OF BINARY TREE \n4.DISPLAY THE LEAF NODES OF BINARY TREE";
					cout<<"\n5.CREATE A COPY OF BINARY TREE";
					cout<<"\n6.EXIT";
					cout<<"\nENTER YOUR CHOICE [1,2,3,4,5,6]: ";
					cin>>CH;
					switch(CH)
					{
						case 1: cout<<"\n***** CREATE BINARY TREE *****\n";
								do{
								P=T.INSERT();
								cout<<"\n\nDO YOU WANT TO INSER MORE NODES IN THE BINARY TREE ";
								cout<<"[PRESS \'Y\' FOR YES ]: ";
								cin>>c;
								}while(c=='Y'||c=='y');
								break;
						case 2: cout<<"\n***** DISPLAY BINARY TREE *****\n";
								T.DISPLAY_BTREE();
								break;
						case 3: cout<<"\n***** DISPLAY THE DEPTH OF BINARY TREE *****\n";
								DEPTH = T.DISPLAY_DEPTH(P);
								cout<<"\nTHE DEPTH OF THE CREATED \"BINARY TREE\" IS: "<<DEPTH;
								break;
					    case 4: cout<<"\n***** DISPLAY THE LEAF NODES OF BINARY TREE *****\n";
					    		T.DISPLAY_LEAF_NODE(P);
								break;
					    case 5: cout<<"\n***** CREATE A COPY OF BINARY TREE *****\n";
					    		cout<<"\nORIGINAL BINARY TREE: ";
					    		T.DISPLAY_BTREE();
					    		cout<<"\n\n****** PERFORMING COPY OPERATION *******\n";
					    		P1=T1.COPY_TREE(P);
					    		T1.ASSIGN_ROOT_NODE(P1);
					    		cout<<"\nNEWLY COPIED BINARY TREE: ";
					    		T1.DISPLAY_BTREE();
					    		break;
						case 6: cout<<"\nYOU HAVE CHOSEN TO EXIT !!\n";
								break;

						default: cout<<"\nYOU CHOOSE A WRONG OPTION !!";
								 break;

					}
					if(CH>=1 && CH<6)
					{
						cout<<"\n\nDO YOU WANT TO CHOOSE ANY OTHER OPTION FROM PROGRAM MENU ";
						cout<<"[PRESS \'Y\' FOR YES AND \'N\' FOR NO]: ";
						cin>>c;
					}
					else if(CH==6)
						break;
			}while(c=='Y'||c=='y');



		return 0;
	}
