//============================================================================
// Name        : tree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node             //node structure for tree
{
	int data;
	node *lchild,*rchild;
};

class binary_tree          //class structure for tree
{
	node *root;          //data member

    public:
       binary_tree();        //member functions 
	   node* getnode();
	   void create();
	   void insert();
	   void display();
	   void preorder(node*);
	   void inorder(node* );
	   void postorder(node*);
	   node* get_root();
	   node* copy(node*);
	   void copy_tree(binary_tree*);
	   int depth(node *);
	   void leaf_node(node*);

};

binary_tree::binary_tree()     //to initialize root node
{
	root=NULL;
}

node* binary_tree::get_root()    //to get root of tree
{
	return root;
}

node* binary_tree::getnode()      //to create node of tree
{
	node* p;
	p=new node;
	cout<<"Enter data::";        //take data from user
	cin>>p->data;

	p->lchild=NULL;          //make left child and right child as NULL
	p->rchild=NULL;

	return p;
}

void binary_tree::create()       //To create a tree 
{
   int n,i;
   cout<<"Enter the number of elements:";
   cin>>n;
   for(i=0;i<n;i++)
   {
     insert();       //call insert to add node to tree
   }
}

void binary_tree::insert()  //to add node to tree
{
	int ch;
	node *q;
	if(root==NULL)     //initially when tree is empty
		   {
			   root=getnode();   //create root node of tree
			   return ;
		   }
		   else
		   {
			   q=root;

			   do
			   {
				   cout<<"\n Enter the location where to insert:\n1.Left subtree\n2.right subtree";   //where to insert
				   cin>>ch;
					   if(ch==1)   // insert at left
					   {
						  if(q->lchild!=NULL)  //if left child exists 
							  q=q->lchild;      //move to left node
						  else
						  {
							  q->lchild=getnode();      //add node to left
							  return ;

						  }
					   }
					   else if(ch==2)        //insert at right
					   {
						   if(q->rchild!=NULL)  //if right child exists
							  q=q->rchild;      //move to right node
						   else
						   {
							   q->rchild=getnode();    //add node to right
							   return ;
						   }
					   }
			   }while(1);
		   }
}


void binary_tree::inorder(node* p)   //to display inorder traversal
{
	if(p!=NULL)    //if there is no node
	{
		inorder(p->lchild);    //call recursively for left child
		cout<<" "<<p->data;    //print data of node
		inorder(p->rchild);     //call recursively for right child
	}
}

void binary_tree::preorder(node* p)  //to display preorder traversal
{
	if(p!=NULL)
	{
		cout<<" "<<p->data;    //print data
		preorder(p->lchild);    //call recursively for left child
		preorder(p->rchild);    //call recursively for right child
	}
}

void binary_tree::postorder(node* p)   //to display postorder traversal
{
  if(p!=NULL)
  {
	  postorder(p->lchild);    //call recursively for left child
	  postorder(p->rchild);    //call recursively for right child
	  cout<<" "<<p->data;        //print data
  }
}

void binary_tree::display()      //to display tree
{
	cout<<"\n Preorder  :";     
	preorder(root);
	cout<<"\n Inorder   :";
	inorder(root);
	cout<<"\n Postorder :";
	postorder(root);
}

void binary_tree::leaf_node(node* p)    //to get leaf node 
{
	if(p!=NULL)
	{
		if(p->lchild==NULL && p->rchild==NULL)   //if left child and right child of node are NULL
		cout<<" "<<p->data;
		leaf_node(p->lchild);   //call recursively for left child
		leaf_node(p->rchild);   //call recursively for right child
	}
}

void binary_tree::copy_tree(binary_tree *b)
{
	b->root=copy(root);
}

node* binary_tree::copy(node *t1)    //to copy tree 
{
	if(t1==NULL)         //if tree is empty
		return NULL;
	else
	{
		node* t2;
		t2=new node;   
		t2->data=t1->data;      //copy data
		t2->lchild=copy(t1->lchild);   //call recursively for left child
		t2->rchild=copy(t1->rchild);   //call recursively for right child
	}
}

int binary_tree::depth(node *root)   //to get depth of tree
{
       if(root==NULL)    //if node is NULL
    	   return -1;
       else
       {
    	   return 1+ (depth(root->lchild) > depth(root->rchild) ? depth(root->lchild):depth(root->rchild)); //to get maximum depth of child
       }
}

int main()
{
	int n,ch;
	binary_tree b1,b2;
	do
	{                                   
		cout<<"\n*****MENU*****";      //menu driven function 
		cout<<"\n\t1.Create a Tree";
		cout<<"\n\t2.Insert a Node";
		cout<<"\n\t3.Display Tree";
		cout<<"\n\t4.Depth of Tree";
		cout<<"\n\t5.Leaf Nodes";
		cout<<"\n\t6.Copy of Tree";
		cout<<"\n\t7.Exit";
		cout<<"\nEnter Your Choice:";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				b1.create();    //to create tree
				break;
				
			case 2:
				b1.insert();   //to insert node 
				break;
			
			case 3:
				b1.display();   //to display tree
				break;
			
			case 4:
			    n=b1.depth(b1.get_root());     //to get depth of tree
                cout<<"\nDepth Of Tree:"<<n;
                break;
				
			case 5:
				cout<<"Leaf Nodes of given tree:";   //to get leaf nodes
				b1.leaf_node(b1.get_root());
				break;
				
			case 6:
				b1.copy_tree(&b2);             //to copy tree 
				cout<<"\n\nOriginal Tree::";
				b1.display();
				cout<<"\n\nCopied Tree::";
				b2.display();
				break;		
		}	
    }while(ch!=7);
}

