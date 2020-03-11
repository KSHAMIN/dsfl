//============================================================================
// Name        : ass7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

struct GraphEdge
{
	GraphEdge *nep;					//Next Edge Pointer
	struct GraphVertex *dvp;		//Destination Vertex Pointer
	int weight,flag;
};

struct GraphVertex
{
	GraphEdge *nep;					//Next Edge Pointer
	GraphVertex *nvp;				//Next Vertex Pointer
	char no;
	bool visited;					//Vertices are visited or not
};

struct GraphHead
{
	int count;
	GraphVertex *fv;					//First Vertex
};

class Kruskal
{
	GraphHead *g;
public:
	void CreateGraph();
	void InsertVertex();
	int InsertEdge(char,char,int);
	GraphVertex* GetVertex();
	GraphVertex* FindVertex(char);
	void DisplayGraph();
	int search(char);
	GraphEdge* MinEdge();
	void marked(GraphEdge*);
	void KruskalAlgo();
};

void Kruskal::CreateGraph()
{
	g = new GraphHead;
	g->count = 0;
	g->fv = NULL;
}

int Kruskal::search(char c)
{
	GraphVertex *h = g->fv;
	if(g->fv == NULL)
		return 1;
	else
	{
		while(h != NULL)
		{
			if(h->no == c)
				return 0;
			else
				h = h->nvp;
		}
	}
	return 1;
}

GraphVertex* Kruskal::GetVertex()
{
	GraphVertex *p;
	char c;
	cout << "\nEnter value:";
	cin >> c;
	if(search(c) == 1)
	{
		p = new GraphVertex;
		p->no = c;
		p->visited = false;
		p->nep = NULL;
		p->nvp = NULL;
		return p;
	}
	else
	{
		cout << "\nSame value already exists!!\n";
		return NULL;
	}
}

void Kruskal::marked(GraphEdge *m)
{
	GraphEdge *temp,*edgeptr;
	GraphVertex *vptr = g->fv;
	while(vptr != NULL)
	{
		edgeptr = vptr->nep;
		if(edgeptr != NULL)
		{
			while(edgeptr->nep != NULL)
			{
				if(edgeptr == m)
				{
					edgeptr->flag = 1;
					return;
				}
				edgeptr = edgeptr->nep;
			}
		}
		vptr = vptr->nvp;
	}
}

GraphEdge *Kruskal::MinEdge()
{
	GraphEdge *temp,*edgeptr;
	GraphVertex *vptr = g->fv;
	int mwt = 999;
	while(vptr != NULL)
	{
		edgeptr = vptr->nep;
		if(edgeptr != NULL)
		{
			while(edgeptr->nep != NULL)
			{
				if(edgeptr->flag != 1)
				{
					if(mwt > edgeptr->weight)
					{
						mwt = edgeptr->weight;
						temp = edgeptr;
					}
				}
				edgeptr = edgeptr->nep;
			}
		}
		vptr = vptr->nvp;
	}
	marked(temp);
	return temp;
}

void Kruskal::InsertVertex()
{
	GraphVertex *nptr,*lptr;			//nptr = new pointer and lptr = location pointer
	nptr = GetVertex();
	if(nptr != NULL)
	{
		lptr = g->fv;
		if(lptr == NULL)
		{
			g->fv = nptr;
			lptr = nptr;
		}
		else
		{
			while(lptr->nvp != NULL)
				lptr = lptr->nvp;
			lptr->nvp = nptr;
		}
	}
}

GraphVertex* Kruskal::FindVertex(char c)
{
	GraphVertex *h = g->fv;
	while(h != NULL)
	{
		if(h->no == c)
			return h;
		else
			h = h->nvp;
	}
	return NULL;
}

void Kruskal::DisplayGraph()
{
	GraphVertex *vptr = g->fv;
	GraphEdge *EdgePtr;
	while(vptr != NULL)
	{
		cout << vptr->no;
		EdgePtr = vptr->nep;
		if(EdgePtr != NULL)
		{
			cout << "||" << "<<" << EdgePtr->weight << ">>" << EdgePtr->dvp->no;
			while(EdgePtr->nep != NULL)
			{
				EdgePtr = EdgePtr->nep;
				cout << "\t" << "<<" << EdgePtr->weight << ">>" << EdgePtr->dvp->no;
			}
		}
		vptr = vptr->nvp;
		cout << endl;
	}
}

int Kruskal::InsertEdge(char sv,char dv,int wt)			//sv = source vertex,dv = destination vertex,wt = weight
{
	GraphVertex *sptr,*dptr;							//sptr = source pointer,dptr = destination pointer

	sptr = FindVertex(sv);
	while(sptr == NULL)
	{
		cout << "\nSource vertex not found!! Enter again:";
		cin >> sv;
		sptr = FindVertex(sv);
	}

	dptr = FindVertex(dv);
	while(dptr == NULL)
	{
		cout << "\nDestination vertex not found!! Enter again:";
		cin >> dv;
		dptr = FindVertex(dv);
	}

	if(sptr->nep == NULL)
	{
		GraphEdge *NewEdge;
		NewEdge = new GraphEdge;
		sptr->nep = NewEdge;
		NewEdge->dvp = dptr;
		NewEdge->nep = NULL;
		NewEdge->weight = wt;
		NewEdge->flag = 0;
	}
	else
	{
		GraphEdge *tempedge,*NewEdge;
		NewEdge = new GraphEdge;
		tempedge = sptr->nep;
		while(tempedge->nep != NULL)
			tempedge = tempedge->nep;
		tempedge->nep = NewEdge;
		NewEdge->dvp = dptr;
		NewEdge->nep = NULL;
		NewEdge->weight = wt;
		NewEdge->flag = 0;
	}

	if(dptr->nep == NULL)
	{
		GraphEdge *NewEdge;
		NewEdge = new GraphEdge;
		dptr->nep = NewEdge;
		NewEdge->dvp = sptr;
		NewEdge->nep = NULL;
		NewEdge->weight = wt;
		NewEdge->flag = 0;
	}
	else
	{
		GraphEdge *tempedge,*NewEdge;
		NewEdge = new GraphEdge;
		tempedge = dptr->nep;
		while(tempedge->nep != NULL)
			tempedge = tempedge->nep;
		tempedge->nep = NewEdge;
		NewEdge->dvp = sptr;
		NewEdge->nep = NULL;
		NewEdge->weight = wt;
		NewEdge->flag = 0;
	}
	return 1;
}

int menu()
{
	int r;
	cout << "\n*****MENU*****\n1)Create Graph\n2)Insert Vertex\n3)Insert Edge\n4)Display\n5)Find minimum edge\n6)Exit\n\n";
	cout << "Enter your choice:";
	cin >> r;
	return r;
}

int main()
{
	Kruskal k;
	char v1,v2;
	int wt;
	int i,j,t=1;

	while(t)
	{
		switch(menu())
		{
		case 1:
			k.CreateGraph();
			break;
		case 2:
			k.InsertVertex();
			break;
		case 3:
			cout << "\nEnter source vertex:";
			cin >> v1;
			cout << "\nEnter destination vertex:";
			cin >> v2;
			cout << "\nEnter weight:";
			cin >> wt;
			k.InsertEdge(v1,v2,wt);
			break;
		case 4:
			k.DisplayGraph();
			break;
		}
	}
	return 0;
}
