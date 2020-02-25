//============================================================================
// Name        : priority_queue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "queue.h"
#include "queue.cpp"
#include <iostream>
using namespace std;

struct patient_data     //structure of patient data
{
	char name[30];
	int age;
	char bgroup[5];
	char phoneno [12];
	int priority;
};

class priority_queue    //class declaration
{
       patient_data p;
       queue<int> q;
       public:
       	void admit();
       	void discharge();
       	void display();
       	void f_priority();
       	void r_priority();
};

void priority_queue::admit()    //to admit patient
{
	cin.ignore(1);
	cout<<"\nEnter the Name of Patient::";     //scan data and store 
	cin.getline(p.name,28);
	cout<<"Enter the Age of Patient::";     //scan data and store 
	cin>>p.age;
	while(p.age<0 || p.age>100)       //validating age 
	{
		cout<<"Enter the valid age of patient::";
		cin>>p.age;
	}
	cout<<"Enter Blood Group of patient::";     //scanning blood group
	cin>>p.bgroup;
	
	cout<<"Enter Mobile Number of Patient::";      //scanning mobile number 
		cin>>p.phoneno;
		int i,f=1;
		while(f!=0)                             //validating mobile number
		{
			f=0;
			if(strlen(p.phoneno)!=10)          //if mobile number is not 10 digit
					{
						cout<<"Enter 10 digit Mobile Number::";
						cin>>p.phoneno;
						f=1;	
					}
		    else
			    {
			    	i=0;
				while(p.phoneno[i]!='\0')       
					{
						if(p.phoneno[i]< '0' || p.phoneno[i]>'9')    //if number is not digit
						{
							cout<<"Enter valid Mobile Number::";
							cin>>p.phoneno;
							f=1;
							break;
						}
						i++;
					 }
			    }
	    }  

	cout<<"Enter the priority:\n1.Serious\n2.Medium\n3.General";          //scanning priority 
	cin>>p.priority;
	while(p.priority<0 || p.priority>3)    //validation
	{
		cout<<"Enter the valid Priority::";
		cin>>p.priority;
	}
	q.enqueue(p.name,p.age,p.bgroup,p.phoneno,p.priority);      //calling enqueue function
}

void priority_queue::discharge()     //to discharge patient
{
	q.dequeue();
}

void priority_queue::display()     //to display list of patients
{
	q.q_display();
}

void priority_queue::f_priority()     //to get first patient priority
{
     int n;
     n=q.f_data();
			if(n==1)
				cout<<"\n Serious";
			else if(n==2)
				cout<<"\nMedium";
			else
			     cout<<"\nGeneral";
}

void priority_queue::r_priority()     //to get last patient priority
{
	int n;
	n=q.r_data();
			if(n==1)
				cout<<"\n Serious";
			else if(n==2)
				cout<<"\nMedium";
			else
				cout<<"\nGeneral";
			
}


int main() 
{
	priority_queue p1;     //object of class
	int ch;
do
{
	cout<<"\n*****MENU*****";       //menudriven function
	cout<<"\n\t1.Admit Patient";
	cout<<"\n\t2.Discharge the Patient";
	cout<<"\n\t3.Display List of Patients";
	cout<<"\n\t4.First Patient Priority";
	cout<<"\n\t5.Last Patient Priority";
	cout<<"\n\t6.Exit";
	cout<<"\nEnter your choice:";
	cin>>ch;
	switch(ch)             //switch-case function
	{
		case 1:
			p1.admit();     //calling functions
			cout<<"\nPatient Admitted!!!";
			p1.display();
			
			break;
		case 2:
			p1.discharge();
			cout<<"\nPatient Discharged!!!";
			p1.display();
			break;
		case 3:
			p1.display();
			break;
		case 4:
			p1.f_priority();
			break;
		case 5:
			p1.r_priority();
			break;
		case 6:
			break;
	}
}while(ch!=6);
	
}
