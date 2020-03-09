
#include <iostream>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

struct graphEdge
{
	graphEdge *nextEdgePointer;
	struct graphVertex *destinationVertexPointer;
	int weight;
	int flag;
};

struct graphVertex
{
	char no;
	bool visited;
	graphEdge *nextEdgePointer;
	graphVertex *nextVertexPointer;
};

struct graphHead
{
	int count;
	graphVertex *firstVertex;
};

class GraphKruskal
{
	graphHead *G;
public:
	void createGraph();
	graphVertex* getVertex();
	void insertVertex( );
	int insertEdge(char,char,int);
	void displayGraph();
	int search(char);
	graphVertex* findVertex(char);
	graphEdge* findminedge();
	void marked(graphEdge*);
	void Kruskal();
};

void GraphKruskal::createGraph()
{
	G=new graphHead;
	G->count=0;
	G->firstVertex=NULL;
}

graphVertex* GraphKruskal::getVertex()
{
	graphVertex *p;
	char no;
	cout<<"ENTER VALUE : ";cin>>no;
	if(search(no)==1)
	{
		p=new graphVertex();
		p->no=no;
		p->visited=false;
		p->nextVertexPointer=NULL;
		p->nextEdgePointer=NULL;
		return p;
	}
	else
	{
		cout<<"Same value already exists \n";
		return NULL;
	}
}

int GraphKruskal::search(char key)
{
	graphVertex *GG=G->firstVertex;
	if(G->firstVertex==NULL)
	{
		return 1;
	}
	else
		while(GG!=NULL)
		{
			if(GG->no==key)
			{
				return 0;
			}
			else GG=GG->nextVertexPointer;
		}
	return 1;
}

graphVertex* GraphKruskal::findVertex(char key)
{
	graphVertex *GG=G->firstVertex;

	while(GG!=NULL)
	{
		if(GG->no==key)
		{
				return GG;
		}
		else GG=GG->nextVertexPointer;
	}
	return NULL;
}

void GraphKruskal::displayGraph()
{
	graphVertex *vertexPtr=G->firstVertex;
	graphEdge *edgePtr;
	while(vertexPtr!=NULL)
	{
		cout<<vertexPtr->no;
		edgePtr=vertexPtr->nextEdgePointer;
		if(edgePtr!=NULL)
		{
			cout<<" || "<<"("<<edgePtr->weight<<")"<<edgePtr->destinationVertexPointer->no;
			while(edgePtr->nextEdgePointer!=NULL)
			{
				edgePtr=edgePtr->nextEdgePointer;
				cout<<" "<<"("<<edgePtr->weight<<")"<<edgePtr->destinationVertexPointer->no;
			}
		}
		vertexPtr=vertexPtr->nextVertexPointer;
		cout<<"\n";
	}
}

void GraphKruskal::Kruskal()
{
	graphVertex *vertexPtr=G->firstVertex;
	graphEdge *edgePtr;
	while(vertexPtr->nextVertexPointer!=NULL)
	{
		edgePtr=findminedge();
		cout<<edgePtr->weight<<" ";
		vertexPtr=vertexPtr->nextVertexPointer;
	}
}


void GraphKruskal::insertVertex()
{
	graphVertex *newPtr,*locPtr;
	newPtr=getVertex();
	if(newPtr!=NULL)
	{
		locPtr=G->firstVertex;
		if(locPtr==NULL)
		{
			G->firstVertex=newPtr;
			locPtr=newPtr;
		}
		else
		{
			while(locPtr->nextVertexPointer!=NULL)
			{
				locPtr=locPtr->nextVertexPointer;
			}
			locPtr->nextVertexPointer=newPtr;
		}
	}
}

int GraphKruskal::insertEdge(char startVertex, char endVertex, int weight)
{
	graphVertex *fromPtr, *toPtr;
	fromPtr=findVertex(startVertex);		//Getting first vertex
	while(fromPtr==NULL)
	{
		cout<<"USER "<<startVertex<<" NOT FOUND ! ENTER AGAIN : ";
		cin>>startVertex;
		fromPtr=findVertex(startVertex);
	}

	toPtr=findVertex(endVertex);		//Getting second vertex
	while(toPtr==NULL)
	{
		cout<<"USER "<<endVertex<<" NOT FOUND ! ENTER AGAIN : ";
		cin>>endVertex;
		toPtr=findVertex(endVertex);
	}

	if(fromPtr->nextEdgePointer==NULL)
	{
		graphEdge *newedge;
		newedge=new graphEdge;
		fromPtr->nextEdgePointer=newedge;
		newedge->destinationVertexPointer=toPtr;
		newedge->nextEdgePointer=NULL;
		newedge->weight=weight;
		newedge->flag=0;
	}
	else
	{
		graphEdge *newedge,*locedge;
		locedge=fromPtr->nextEdgePointer;
		while(locedge->nextEdgePointer!=NULL)
		{
			locedge=locedge->nextEdgePointer;
		}
		newedge=new graphEdge;
		locedge->nextEdgePointer=newedge;
		newedge->destinationVertexPointer=toPtr;
		newedge->nextEdgePointer=NULL;
		newedge->weight=weight;
		newedge->flag=0;
	}

	if(toPtr->nextEdgePointer==NULL)
	{
		graphEdge *newedge;
		newedge=new graphEdge;
		toPtr->nextEdgePointer=newedge;
		newedge->destinationVertexPointer=fromPtr;
		newedge->nextEdgePointer=NULL;
		newedge->weight=weight;
		newedge->flag=0;
	}
	else
	{
		graphEdge *newedge,*locedge;
		locedge=toPtr->nextEdgePointer;
		while(locedge->nextEdgePointer!=NULL)
		{
			locedge=locedge->nextEdgePointer;
		}
		newedge=new graphEdge;
		locedge->nextEdgePointer=newedge;
		newedge->destinationVertexPointer=fromPtr;
		newedge->nextEdgePointer=NULL;
		newedge->weight=weight;
		newedge->flag=0;
	}

	return 1;
}

graphEdge* GraphKruskal::findminedge()
{
	graphEdge* temp,*edgePtr;
	graphVertex *vertexPtr=G->firstVertex;
	int minwt=999;
	while(vertexPtr!=NULL)
	{
		//cout<<vertexPtr->no;
		edgePtr=vertexPtr->nextEdgePointer;
		if(edgePtr!=NULL)
		{
			while(edgePtr->nextEdgePointer!=NULL)
			{
				if(edgePtr->flag!=1)
				{
					if(minwt>edgePtr->weight)
					{
						minwt=edgePtr->weight;
						temp=edgePtr;
					}
				}
				edgePtr=edgePtr->nextEdgePointer;
			}
		}
		vertexPtr=vertexPtr->nextVertexPointer;
	}
	marked(temp);		//mark that edge as visited
	return temp;
}


void GraphKruskal::marked(graphEdge *E)
{
	graphEdge* temp,*edgePtr;
	graphVertex *vertexPtr=G->firstVertex;

	while(vertexPtr!=NULL)
	{
		edgePtr=vertexPtr->nextEdgePointer;
		if(edgePtr!=NULL)
		{
			while(edgePtr->nextEdgePointer!=NULL)
			{
				if(edgePtr==E)
				{
					E->flag=1;
					return;
				}
				edgePtr=edgePtr->nextEdgePointer;
			}
		}
		vertexPtr=vertexPtr->nextVertexPointer;
	}
}


int main()
{
	GraphKruskal GR;
	int choice;
	char no1,no2;
	int wt;
	do{
		cout<<"\n******* MENU *******\n1)Create Graph\n2)Insert Vertex\n3)Insert Edge\n4)Display\n";
		cout<<"5.FIND MINEDGE \n0)EXIT\nEnter Choice:- ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			GR.createGraph();
			break;
		case 2:
			GR.insertVertex();
			break;
		case 3:
			cout<<"ENTER VALUE 1 : ";
			cin>>no1;
			cout<<"ENTER VALUE 2 : ";
			cin>>no2;
			cout<<"ENTER WEIGHT : ";
			cin>>wt;
			GR.insertEdge(no1,no2,wt);
			break;
		case 4:
			GR.displayGraph();
			break;
		case 5:
			GR.Kruskal();
			break;
		case 0:
			cout<<"EXIT SUCCESS ! ";
			break;
		}
	}while(choice!=0);

		return 0;

}

