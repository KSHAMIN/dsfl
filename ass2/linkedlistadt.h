

#ifndef LINKEDLISTADT_H_
#define LINKEDLISTADT_H_

template<typename T>     //node structure for patient
struct patient
{
	char name[30];
	int age;
	char bgroup[5];
	char phoneno [12];
};

template<typename T>
struct node     //node structure
{
    patient<T> p;
     int priority;
	 node<T>* next;

};
template<class T>    //class declaration for linked list as ADT
class linkedlistadt
{
 node<T>* head;
public:
    linkedlistadt();      //member function declarations
    node<T>* getnode(char [],int ,char[],char[],int);
	void display();
	void insert(char [],int ,char[],char[],int);
	void delete_beg();
	node<T>* head1();
};

#endif /* LINKEDLISTADT_H_ */
