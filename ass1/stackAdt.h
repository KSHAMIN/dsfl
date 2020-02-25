
#include"slladt.h"

#ifndef STACKADT_H_
#define STACKADT_H_

template<class T>
class stackAdt          //class declaration of stack
{
	slladt<T> l1;
public:
	stackAdt();            //member function declarations
	virtual ~stackAdt();
	void push(T);
	T pop();
	T peep();
	bool isempty();
	void display1();
};

#endif /* STACKADT_H_ */