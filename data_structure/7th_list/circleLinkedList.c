#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode
{
	element data;
	struct ListNode *next;
}ListNode;

typedef struct ListType
{
	ListNode *tail;
	int size;
}ListType;

void init(ListType *L)
{
	L->tail = NULL;
	L->size = 0;
}
void insertFirst(ListType *L, element e)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = e;

	if (L->size == 0)
	{
		L->tail = node;
		node->next = L->tail;
	}
	else
	{
		node->next = L->tail->next;
		L->tail->next = node;
	}
	L->size++;
}

void insertLast(ListType *L, element e)
{
	if (L->size == 0)
		insertFirst(L, e);
	else
	{
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
		node->data = e;
		node->next = L->tail->next;
		L->tail->next = node;
		L->tail = node;
		L->size++;
	}
}

void insert(ListType *L, int pos, element e)
{
	if (pos < 1 || pos > L->size + 1)
		printf("Invalid Pos.\n");
	else
	{
		if (pos == 1)
			insertFirst(L, e);
		else if (pos == L->size+1)
			insertLast(L, e);
		else
		{
			ListNode *node = (ListNode *)malloc(sizeof(ListNode));
			ListNode *pre = L->tail;
			for (int i = 1; i < pos; i++)
				pre = pre->next;

			node->next = pre->next;
			pre->next = node;
			node->data = e;
			L->size++;
		}
	}
}

element deleteFirst(ListType *L)
{
	if (L->size == 0)
	{
		printf("No Element.\n");
		return -1;
	}
	ListNode *pre = L->tail;
	ListNode *rm = pre->next;

	element e = rm->data;
	pre->next = rm->next;

	free(rm);
	L->size--;
	
	return e;
}

element delLast(ListType *L)
{
	ListNode *rm = L->tail;
	ListNode *pre = rm->next;

	element e = rm->data;

	if (L->size == 0)
		L->tail = NULL;
	else
	{
		while(pre->next != rm)
			pre = pre->next;

		pre->next = rm->next;
		L->tail = pre;
	}

	free(rm);
	L->size--;

	return e;
}

element delete(ListType *L, int pos)
{
	if (L->size == 0)
	{
		printf("No Element.\n");
		return -1;
	}
	else if (pos < 1 || pos > L->size)
	{
		printf("Invalid Pos.\n");
		return -1;
	}
	else
	{
		element e;
		if (pos == 1)
			e = deleteFirst(L);
		else if (pos == L->size)
			e = delLast(L);
		else
		{
			ListNode *rm;
			ListNode *pre = L->tail->next;
			for (int i = 1; i < pos - 1; i++)
				pre = pre->next;
			rm = pre->next;
			e = rm->data;
			pre->next = rm->next;
			free(rm);
			L->size--;
		}
		return e;
	}
}

void print(ListType *L)
{
	ListNode *node;
	if (L->size == 0)
		return ;
	int cnt = L->size;
	node = L->tail;

	do
	{
		printf("%c -> ", node->next->data);
		node = node->next;
		cnt--;
	}while (cnt != 0);

	printf("\b\b\b   \n");
}

int main()
{
	ListType L;
	init(&L);

	insertFirst(&L, 'A'); print(&L);
	insertFirst(&L, 'B'); print(&L);
	insertLast(&L, 'C'); print(&L); getchar();
	
	insert(&L, 1, 'F'); print(&L);
	insert(&L, 4, 'G'); print(&L);
	insert(&L, 6, 'H'); print(&L); getchar();

	printf("[%c] is deleted.\n", deleteFirst(&L)); print(&L);
	printf("[%c] is deleted.\n", delete(&L, 3)); print(&L);
	printf("[%c] is deleted.\n", delete(&L, 4));
	print(&L);

	return 0;
}
