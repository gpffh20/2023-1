#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct DListNode
{
	struct DListNode *next;
	struct DListNode *prev;
	element data;
}DListNode;

typedef struct DListType
{
	DListNode *H;
	DListNode *T;
	int N;
}DListType;

DListNode *getNode()
{
	DListNode *node = (DListNode*)malloc(sizeof(DListNode));
	node->prev = node->next = NULL;
	return node;
}

void init(DListType *DL)
{
	DL->H = getNode();
	DL->T = getNode();
	DL->H->next = DL->T;
	DL->T->prev = DL->H;
	DL->N = 0;
}

void insertFirst(DListType *DL, element e)
{
	DListNode *node = getNode();
	DListNode *p = DL->H;
	
	node->data = e;

	node->prev = p;
	node->next = p->next;
	
	p->next->prev = node;
	p->next = node;

	DL->N++;
}

void insertLast(DListType *DL, element e)
{
	DListNode *node = getNode();
	DListNode *p = DL->T;

	node->data = e;

	node->next = p;
	node->prev = p->prev;

	p->prev->next = node;
	p->prev = node;

	DL->N++;
}

void insert(DListType *DL, int pos,  element e)
{
	DListNode *node = getNode();
	DListNode *p = DL->H;
	
	if (pos == 1)
		insertFirst(DL, e);
	else if (pos == DL->N+1)
		insertLast(DL, e);
	else
	{
		for (int i = 1; i < pos; i++)
			p = p->next;
		node->data = e;

		node->prev = p;
		node->next = p->next;
	
		p->next->prev = node;
		p->next = node;

		DL->N++;
	}
}

element deleteFirst(DListType *DL)
{
	DListNode *p = DL->H->next;

	if (p == DL->T)
	{
		printf("Error\n");
		return -1;
	}
	else
	{
		element e = p->data;
		p->next->prev = DL->H;
		DL->H->next = p->next;

		free(p);
		DL->N--;
		
		return e;
	}
}

element delete(DListType *DL, int pos)
{
    element e = -1;

    if(pos < 1 || pos > DL->N)
        printf("Invalid Position.\n");
    else
    {
        DListNode * p = DL->H;
        for(int i = 0; i < pos; i++)
            p = p->next;

        e = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);

        DL->N--;
    }

    return e;
}

void print(DListType *DL)
{
	DListNode *p;
	for(p = DL->H->next; p != DL->T; p = p->next)
		printf("[%c] <=> ", p->data);

	printf("\b\b\b\b    \n");
}

int main()
{
	DListType DL;
	init(&DL);

	insertFirst(&DL, 'A'); print(&DL);
	insertFirst(&DL, 'B'); print(&DL); getchar();

	insertLast(&DL, 'C'); print(&DL);
	insertLast(&DL, 'D'); print(&DL); getchar();

	insert(&DL, 4, 'E'); print(&DL);
	insert(&DL, 6, 'F'); print(&DL);
	insert(&DL, 3, 'G'); print(&DL);

	printf("[%c] is deleted. \n", deleteFirst(&DL)); print(&DL);
	printf("[%c] is deleted. \n", delete(&DL, 3)); print(&DL);

	return 0;
}
