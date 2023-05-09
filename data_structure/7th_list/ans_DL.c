#include <stdio.h>

#include <stdlib.h>


typedef char element;


typedef struct DListNode

{

    element data;

    struct DListNode *prev;

    struct DListNode *next;

}DListNode;


typedef struct

{

    DListNode *H;

    DListNode *T;

    int N;

}DListType;


DListNode* getNode()

{

    DListNode *node = (DListNode*)malloc(sizeof(DListNode));

    node->next = node->prev = NULL;

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


void insert(DListType *DL, int pos, element e)

{

    if(pos < 1 || pos > DL->N + 1)

        printf("Invalid Position.\n");

    else

    {

        DListNode *node = getNode();

        DListNode *p = DL->H;

       

        for(int i = 1; i < pos; i++)

            p = p->next;

           

        node->data = e;

       

        node->prev = p;

        node->next = p->next;

       

        p->next->prev = node;

        p->next = node;

 
       

        DL->N++;

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

   

    printf("\b\b\b\b   \n");    

}



int main()

{

    DListType DL;

    init(&DL);

   

    insert(&DL, 1, 'A'); print(&DL);

    insert(&DL, 2, 'B'); print(&DL);

    insert(&DL, 2, 'C'); print(&DL);

    insert(&DL, 4, 'D'); print(&DL);

    insert(&DL, 4, 'E'); print(&DL); getchar();

   

    printf("[%c] is deleted.\n", delete(&DL, 1)); print(&DL);

    printf("[%c] is deleted.\n", delete(&DL, 4)); print(&DL);

 
    printf("[%c] is deleted.\n", delete(&DL, 2)); print(&DL);


    return 0;

}
