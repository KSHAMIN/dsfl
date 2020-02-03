

#ifndef TREE_H_
#define TREE_H_
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////

template <class T>
class TREENODE
{	 T DATA;
	 TREENODE *LEFT;
	 TREENODE *RIGHT;

public:
	TREENODE();
	virtual ~TREENODE();
	template <class U>friend class TREE;

};
/////////////////////////////////////////////////////////////

template<class T>
class TREE {
	TREENODE<T> *ROOT;

public:
	TREE();
	virtual ~TREE();
	bool ISOPERATOR(char);
	TREENODE<T>* EXPRESSION_TREE(string);
	void INORDER_TRAVERSAL_RECURSIVE(TREENODE<T>*);
	void POSTORDER_TRAVERSAL_RECURSIVE(TREENODE<T>*);
	void PREORDER_TRAVERSAL_RECURSIVE(TREENODE<T>*);
	void PREORDER_TRAVERSAL_NON_RECURSIVE(TREENODE<T>*);
	void POSTORDER_TRAVERSAL_NON_RECURSIVE(TREENODE<T>*);
	void INORDER_TRAVERSAL_NON_RECURSIVE(TREENODE<T>*);
	
};
#endif /* TREE_H_ */
