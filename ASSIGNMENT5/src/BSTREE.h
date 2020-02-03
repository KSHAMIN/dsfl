
#ifndef BSTREE_H_
#define BSTREE_H_

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
	TREENODE<T>* RETURN_L(TREENODE<T>*);
	TREENODE<T>* RETURN_R(TREENODE<T>*);
	virtual ~TREENODE();
	template <class U>friend class BSTREE;

};
/////////////////////////////////////////////////////////////

template <class T>
class BSTREE {
	TREENODE<T> *ROOT;
public:
	//void ASSIGN_ROOT_NODE(TREENODE<T>*);
	BSTREE();
	void INSERT(TREENODE<T>*,TREENODE<T>*,TREENODE<T>*,T);
	void DELETE_NODE_WITH_1_CHILD_OR_LEAF_NODE(TREENODE<T>*,TREENODE<T>*,TREENODE<T>*,T);
	void DELETE_NODE_WITH_2_CHILDREN(TREENODE<T>*,TREENODE<T>*,TREENODE<T>*,T);
	void DISPLAY_BSTREE(TREENODE<T>*);
	void MIRROR_BST(TREENODE<T>*);
	int DISPLAY_HEIGHT(TREENODE<T>*);
	void DISPLAY_LEVEL_ORDER(TREENODE<T>*);
	void SEARCH_BSTREE(TREENODE<T>*,TREENODE<T>*,TREENODE<T>*,T);
	virtual ~BSTREE();
};


#endif /* BSTREE_H_ */
