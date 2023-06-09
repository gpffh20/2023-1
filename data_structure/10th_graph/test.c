#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex
{
    char vName;
    struct Vertex* next;
}Vertex;

typedef struct
{
    Vertex * vHead;
}GraphType;

void init(GraphType *G)
{
    G->vHead = NULL;
}

void makeVertex(GraphType *G)
{
    G->n++;
}
 
void insertEdge(GraphType *G, int u, int v)
{
    if(u >= G->n || v >= G->n)
        printf("Error.\n");
    else
        G->adjMat[u][v] = G->adjMat[v][u] = 1;
}

void print(GraphType *G)
{
    for(int i = 0; i < G->n; i++)
    {
        for(int j = 0; j < G->n; j++)
            printf(" %d", G->adjMat[i][j]);
        printf("\n");    
    }
}
 
void makeVertex(GraphType *G, char vName)
{
    Vertex *v = (Vertex*)malloc(sizeof(Vertex));
    v->vName = vName;
    v->next = NULL;
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

int main()
{
    GraphType G;
    init(&G);
   
    makeVertex(&G, 'a'); makeVertex(&G, 'b'); makeVertex(&G, 'c');
    makeVertex(&G, 'd'); makeVertex(&G, 'e');
       
    // insertEdge(&G, 0, 1); insertEdge(&G, 0, 2); insertEdge(&G, 0, 4);
    // insertEdge(&G, 1, 2); insertEdge(&G, 2, 3); insertEdge(&G, 2, 4);
    // insertEdge(&G, 3, 4); print(&G);

    return 0;
}
