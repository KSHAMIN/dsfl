//============================================================================
// Name        : ASSIGNMENT5
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "BSTREE.h"
#include "BSTREE.cpp"

/////////////////////////	MAIN BEGINS
	int main() {
		int CH,H=-1,INFO,K;
			char c;
			BSTREE<int> T;
			TREENODE<int> O;
			TREENODE<int> *ROOT_NODE=NULL;
			TREENODE<int> *NODE_LOCATION=NULL;
			TREENODE<int> *PARENT_NODE=NULL;


			do{
					cout<<"\n************************** PROGRAM MENU **************************\n";
					cout<<"\n1.INSERT IN BINARY SEARCH TREE \n2.DISPLAY THE BINARY SEARCH TREE ";
					cout<<"\n3.SEARCH A NODE IN  BINARY SEARCH TREE \n4.IMPLEMENT DELETION IN BINARY SEARCH TREE  \n5.DISPLAY BINARY SEARCH TREE IN LEVEL ORDER";
					cout<<"\n6.CREATE A MIRROR IMAGE OF BINARY SEARCH TREE";
					cout<<"\n7.EVALUATE HEIGHT OF BINARY SEARCH TREE"<<"\n8.EXIT";
					cout<<"\nENTER YOUR CHOICE [1,2,3,4,5,6,7,8]: ";
					cin>>CH;
					switch(CH)
					{
						case 1: cout<<"\n***** CREATE BINARY TREE *****\n";
								do{
								cout<<"\nENTER THE DATA OF THE NEW NODE YOU WANT TO CREATE IN BST: ";
								cin>>INFO;
								T.INSERT(ROOT_NODE,NODE_LOCATION,PARENT_NODE,INFO);
								cout<<"\n\nDO YOU WANT TO INSERT MORE NODES IN THE BINARY SEARCH TREE ";
								cout<<"[PRESS \'Y\' FOR YES ]: ";
								cin>>c;
								}while(c=='Y'||c=='y');
								break;
						case 2: cout<<"\n***** DISPLAY BINARY SEARCH TREE *****\n";
								T.DISPLAY_BSTREE(ROOT_NODE);
								break;
						case 3: cout<<"\n***** SEARCH A NODE IN  BINARY SEARCH TREE *****\n";
								cout<<"\nENTER THE \"DATA\" YOU WANT TO SEARCH IN THE PRESENT BINARY SEARCH TREE: ";
								cin>>K;
								T.SEARCH_BSTREE(ROOT_NODE,NODE_LOCATION,PARENT_NODE,K);
								break;
						case 4:	cout<<"\n***** IMPLEMENT DELETION IN BINARY SEARCH TREE *****\n";
								T.DISPLAY_BSTREE(ROOT_NODE);
								cout<<"\nCHOOSE AND ENTER THE \"DATA\" OF NODE YOU WANT TO DELETE: ";
								cin>>K;
								T.SEARCH_BSTREE(ROOT_NODE,NODE_LOCATION,PARENT_NODE,K);
								if(NODE_LOCATION != NULL)
								  {
									if((O.RETURN_L(NODE_LOCATION)!= NULL) && (O.RETURN_L(NODE_LOCATION) != NULL))
									{
										T.DELETE_NODE_WITH_2_CHILDREN(ROOT_NODE,NODE_LOCATION,PARENT_NODE,K);
									    cout<<"\nNODE IS SUCCESSFULLY DELETED !!";
									    cout<<"\n**** THE UPDATED BINARY SEARCH TREE IS ****";
									    T.DISPLAY_BSTREE(ROOT_NODE);
									}
									else
									{
									    T.DELETE_NODE_WITH_1_CHILD_OR_LEAF_NODE(ROOT_NODE,NODE_LOCATION,PARENT_NODE,K);
									    cout<<"\nNODE IS SUCCESSFULLY DELETED !!";
									    cout<<"\n**** THE UPDATED BINARY SEARCH TREE IS ****";
									    T.DISPLAY_BSTREE(ROOT_NODE);
									}
								  }

								break;
					    case 5: cout<<"\n***** DISPLAY BINARY SEARCH TREE IN LEVEL ORDER *****\n";
					    		T.DISPLAY_LEVEL_ORDER(ROOT_NODE);
								break;
					    case 6: cout<<"\n***** CREATE MIRROR TREE OF BINARY SEARCH TREE *****\n";
					    		cout<<"\nORIGINAL BINARY TREE: ";
					    		T.DISPLAY_BSTREE(ROOT_NODE);
					    		cout<<"\n\n****** CREATING MIRROR TREE *******\n";
					    		T.MIRROR_BST(ROOT_NODE);
					    		cout<<"\nNEWLY CREATED MIRROR TREE OF BST: ";
					    		T.DISPLAY_BSTREE(ROOT_NODE);
					    		break;
					    case 7: cout<<"\n***** DISPLAY THE HEIGHT OF BINARY TREE *****\n";
								H = T.DISPLAY_HEIGHT(ROOT_NODE);
								cout<<"\nTHE HEIGHT OF THE CREATED \"BINARY SEARCH TREE\" IS: "<<H;
								break;
					    case 8: cout<<"\nYOU HAVE CHOSEN TO EXIT !!\n";
								break;

						default: cout<<"\nYOU CHOOSE A WRONG OPTION !!";
								 break;

					}
					if(CH>=1 && CH<7)
					{
						cout<<"\n\nDO YOU WANT TO CHOOSE ANY OTHER OPTION FROM PROGRAM MENU ";
						cout<<"[PRESS \'Y\' FOR YES AND \'N\' FOR NO]: ";
						cin>>c;
					}
					else if(CH==7)
						break;
			}while(c=='Y'||c=='y');
		return 0;
	}
