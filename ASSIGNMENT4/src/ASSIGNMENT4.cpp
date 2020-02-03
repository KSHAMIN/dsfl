//============================================================================
// Name        : ASSIGNMENT4.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include"TREE.h"
#include"TREE.cpp"
//"EXP_TO_BST" CLASS DECLARATION
class EXP_TO_BST{
		//DATA MEMBERS
		string POSTFIX;
		TREE<char> O;
	public:
		EXP_TO_BST(){			//CONSTRUCTOR

				POSTFIX="";

				}
			//FUNCTION DECLARATION
			string READ_POSTFIX();
};
//READ_INFIX() FUNCTION DEFINITION

string EXP_TO_BST::READ_POSTFIX()
{		cout<<"\n****** YOU MAY ENTER ONLY \"ALPHABETS[a,b......,z,A,B....Z,]\"  OR  \"DIGITS[0,1,2......,9]\" AS OPERANDS IN INPUT OF INFIX STRING ******\n";
		cout<<"\nENTER THE POSTFIX STRING: ";		//READING THE EXPRESSION
		cin>>POSTFIX;
		
		return POSTFIX;
	
}



/////////////////////////	MAIN BEGINS
int main() {
	int CH;
		char c;
		TREE<char> T;
		EXP_TO_BST EX;
		string POS;
		 POS=EX.READ_POSTFIX();
		 TREENODE<char>* RT=T.EXPRESSION_TREE(POS);
							
		do{
				cout<<"\n************************** PROGRAM MENU **************************\n";
				cout<<"\n1.DISPLAY THE INORDER TRAVELSAL OF BINARY TREE [RECURSIVE]\n2.DISPLAY THE POSTORDER TRAVELSAL OF BINARY TREE [RECURSIVE]";
				cout<<"\n3.DISPLAY THE PREORDER TRAVELSAL OF BINARY TREE [RECURSIVE]\n4.DISPLAY THE INORDER TRAVELSAL OF BINARY TREE [NON RECURSIVE]";
				cout<<"\n5.DISPLAY THE POSTORDER TRAVELSAL OF BINARY TREE [NON RECURSIVE]";
				cout<<"\n6.DISPLAY THE PREORDER TRAVELSAL OF BINARY TREE [NON RECURSIVE]\n7.EXIT";
				cout<<"\nENTER YOUR CHOICE [1,2,3,4,5,6,7]: ";
				cin>>CH;
				switch(CH)
				{
					case 1: cout<<"\n***** DISPLAYING THE INORDER TRAVELSAL OF BINARY TREE [RECURSIVE] *****\n";
							T.INORDER_TRAVERSAL_RECURSIVE(RT);
							break;
					case 2: cout<<"\n***** DISPLAYING THE POSTORDER TRAVELSAL OF BINARY TREE [RECURSIVE] *****\n";
							T.POSTORDER_TRAVERSAL_RECURSIVE(RT);
							break;
					case 3: cout<<"\n***** DISPLAYING THE PREORDER TRAVELSAL OF BINARY TREE [RECURSIVE] *****\n";
							T.PREORDER_TRAVERSAL_RECURSIVE(RT);
							break;
				    case 4: cout<<"\n***** DISPLAYING THE INORDER TRAVELSAL OF BINARY TREE [NON-RECURSIVE] *****\n";
							T.INORDER_TRAVERSAL_NON_RECURSIVE(RT);
							break;
				    case 5: cout<<"\n***** DISPLAYING THE POSTORDER TRAVELSAL OF BINARY TREE [NON-RECURSIVE] *****\n";
							T.POSTORDER_TRAVERSAL_NON_RECURSIVE(RT);
							break;
				    case 6: cout<<"\n***** DISPLAYING THE PREORDER TRAVELSAL OF BINARY TREE [NON-RECURSIVE] *****\n";
				    	    T.PREORDER_TRAVERSAL_NON_RECURSIVE(RT);
							break;
					case 7: cout<<"\nYOU HAVE CHOSEN TO EXIT !!\n";
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
