/*
 * GRAPH.h
 *
 *  Created on: 14-Feb-2020
 *      Author: dsfle-9
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
using namespace std;

class DATE
{
	int D,MONTH,YEAR;
	public:
	DATE();
	void ADD_DATE(int,int,int);
	virtual ~DATE();
};

class FRIENDS;
class ACCOUNT{
	string NAME;
	DATE DOB;
	int ID;
	FRIENDS *NEXT;
	ACCOUNT *DLINK;
public:
		ACCOUNT();
		virtual ~ACCOUNT();
		friend class GRAPH;
};

class FRIENDS{
	ACCOUNT *SOURCE;
	int COMMENTS;
	FRIENDS *NEW;
public:
		FRIENDS();
		virtual ~FRIENDS();
		friend class GRAPH;
};

class GRAPH {

	ACCOUNT *ALIST;

public:
	    GRAPH();
	    virtual ~GRAPH();

		void CREATE_GRAPH(string,int,int,int,int);
		void INSERT_FRIEND(string,string);
		void DISPLAY_NAME();
		bool VALIDATE_NAME(string,string);
		bool VALIDATE_FRIEND(string,string);
		//void DSF(int);
		void BFS(int);
/*

		void FIND_FRIENDS();
		void MAX_COMMENTS();
		void MIN_COMMENTS();
		void FIND_DOB();*/
};

#endif /* GRAPH_H_ */
