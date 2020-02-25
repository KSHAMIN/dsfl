
#ifndef SLLADT_H_
#define SLLADT_H_
template<typename T>
struct node     //node structure
{
    T data;
	struct node<T>* next;

};
template<class T>    //class declaration for linked list as ADT
class slladt
{
 node<T>* head;
public:
	slladt();
	virtual ~slladt();      //member function declarations
    node<T>* getnode();
	bool head_1();
	void create();
	void display();
	void insert_beg(T);
	void insert_end(T);
	void insert_at(T);
	T delete_beg();
	T delete_end();
	T delete_pos();
	T data_head();
};

#endif /* SLLADT_H_ */