

#ifndef BTREE_H_
#define BTREE_H_
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////
template <class T>
class TREENODE
{	 T DATA;
	 TREENODE *LEFT;
	 TREENODE *RIGHT;

public:
	TREENODE(T);
//	TREENODE<T>* GET_MEMORY(TREENODE<T>*,T);
	T RETURN_DATA();
	virtual ~TREENODE();
	template <class U>friend class BTREE;

};
/////////////////////////////////////////////////////////////

template <class T>
class BTREE {
	TREENODE<T> *ROOT;
public:
	void ASSIGN_ROOT_NODE(TREENODE<T>*);
	BTREE();
	bool ISEMPTY();
	TREENODE<T>* INSERT();
	void DISPLAY_BTREE();
	int DISPLAY_DEPTH(TREENODE<T>*);
	void DISPLAY_LEAF_NODE(TREENODE<T>*);
	TREENODE<T>* COPY_TREE(TREENODE<T>*);
	virtual ~BTREE();
};

#endif /* BTREE_H_ */
