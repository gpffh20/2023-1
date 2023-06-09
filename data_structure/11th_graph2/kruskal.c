#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
	char v1, v2;
	int weight;
	struct Edge *next;
}Edge;

typedef struct IncidentEdge
{
    char aName;
	Edge *e;
    struct IncidentEdge *next;
}IncidentEdge;
 

typedef struct Vertex
{
    char vName;
    int isVisit;
    IncidentEdge *iHead;
    struct Vertex* next;
}Vertex;
 

typedef struct
{
    Vertex * vHead;
	Edge *eHead;
	int eCount, vCount;
}GraphType;
 

void init(GraphType *G)
{
    G->vHead = NULL;
	G->eHead = NULL;
	G->eCount = G->vCount = 0;
}


void makeVertex(GraphType *G, char vName)
{
    Vertex *v = (Vertex*)malloc(sizeof(Vertex));
    v->vName = vName;
    v->isVisit = FALSE;
    v->iHead = NULL;
    v->next = NULL;

	G->vCount++;

    Vertex *p = G->vHead;

    if(p == NULL)
        G->vHead = v;
    else
    {
        while(p->next != NULL)
            p = p->next;
        p->next = v;    
    }
}
 

void makeIncidentEdge(Vertex *v, char aName, Edge *e)
{
    IncidentEdge *p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    p->aName = aName;
    p->e = e;
	p->next = NULL;

    IncidentEdge* q = v->iHead;

	if(q == NULL)
        v->iHead = p;
    else
    {
        while(q->next != NULL)
            q = q->next;
        q->next = p;    
    }
}
 

Vertex* findVertex(GraphType *G, char vName)
{
    Vertex *v = G->vHead;
   
    while(v->vName != vName)
        v = v->next;

    return v;    
}


void insertEdge(GraphType *G, char v1, char v2, int w)
{
	Edge *e = (Edge *)malloc(sizeof(Edge));
	e->v1 = v1;
	e->v2 = v2;
	e->weight = w;
	e->next = NULL;

	G->eCount++;

	Edge *q = G->eHead;
	if (q == NULL)
		G->eHead = e;
	else
	{
		while (q->next != NULL)
			q = q->next;
		q->next = e;
	}

	Vertex *v = findVertex(G, v1);
    makeIncidentEdge(v, v2, e);

    v = findVertex(G, v2);
    makeIncidentEdge(v, v1, e);
}

void selectSort(GraphType *G, Edge *E[])
{
	int i, j, least;

	Edge *p = G->eHead;
	for (i = 0; i < G->eCount; i++)
	{
		E[i] = p;
		p = p->next;
	}

	for (i = 0; i <= G->eCount - 2; i++)
	{
		least = i;
		for (j = i + 1; j <= G->eCount-1; j++)
			if(E[j]->weight < E[least]->weight)
				least = j;
		p = E[least];
		E[least] = E[i];
		E[i] = p;
	}

	for (i = 0; i < G->eCount; i++)
		printf("[%c%c%d] ", E[i]->v1, E[i]->v2, E[i]->weight);
	printf("\n");
}

void print(GraphType *G)
{
    Vertex *p = G->vHead;
    IncidentEdge *q;

    for(; p != NULL; p = p->next)
    {
        printf("[%c] : ", p->vName);
        for(q = p->iHead; q != NULL; q = q->next)
            printf("[%c, %d] ", q->aName, q->e->weight);
        printf("\n");    
    }
}

int vFind(int v[], int vNum)
{

	while (v[vNum] != -1)
		vNum = v[vNum];

	return vNum;
}

void vUnion(int v[], int vNum1, int vNum2)
{
	int v1 = vFind(v, vNum1);
	int v2 = vFind(v, vNum2);

	v[v2] = v1;
}

void krustal(GraphType *G, Edge *e[], int v[])
{
	int eCnt = 0, i = 0;
	int vNum1, vNum2;
	Edge *p;

	while (eCnt < G->vCount - 1)
	{
		p = e[i];

		vNum1 = vFind(v, p->v1 - 97);
		vNum2 = vFind(v, p->v2 - 97);

		if (vNum1 != vNum2)
		{
			eCnt++;
			printf("%d. [%c%c%d]\n", eCnt, p->v1, p->v2, p->weight);
			vUnion(v, vNum1, vNum2);
		}
		i++;
	}
}

int main()
{
    GraphType G;
    init(&G);

    makeVertex(&G, 'a'); makeVertex(&G, 'b'); makeVertex(&G, 'c');
    makeVertex(&G, 'd'); makeVertex(&G, 'e'); makeVertex(&G, 'f');
    makeVertex(&G, 'g');
       

	insertEdge(&G, 'a', 'b', 29); insertEdge(&G, 'a', 'f', 10);
	insertEdge(&G, 'b', 'c', 16); insertEdge(&G, 'b', 'g', 15);
	insertEdge(&G, 'c', 'd', 12);
	insertEdge(&G, 'd', 'e', 22); insertEdge(&G, 'd', 'g', 18);
	insertEdge(&G, 'e', 'f', 27); insertEdge(&G, 'e', 'g', 25);
   
    print(&G); printf("\n");

	Edge *e[10];
	selectSort(&G, E);

	int v[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	krustal(&G, e, v);
    return 0;
}
