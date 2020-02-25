#ifndef QUEUE_H_
#define QUEUE_H_
#include"linkedlistadt.h"

template<class T>
class queue                //class declaration for queue ADT
{
	node<T> *front,*rear;
	linkedlistadt<T> l1;
public:                        
	queue();                    //member functions of class Queue
	void enqueue(char [],int ,char[],char[],int);
	void dequeue();
	void q_display();
	bool isempty();
	int f_data();
	int r_data();

};


#endif /* QUEUE_H_ */
