
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

typedef char element;

typedef struct
{
	element data[N];
	int rear, front;
} DequeType;

void init(DequeType *D)
{
	D->front = D->rear = 0;
}

int isEmpty(DequeType *D)
{
	return D->rear == D->front;
}

int isFull(DequeType *D)
{
	return D->front == (D->rear + 1) % N;
}

void addFront(DequeType *D, element e)
{
	if (isFull(D))
		printf("Full\n");
	else
	{
		D->data[D->front] = e;
		D->front = (D->front - 1 + N) % N;
	}
}

void addRear(DequeType *D, element e)
{
	if(isFull(D))
		printf("Full\n");
	else
	{
		D->rear = (D->rear+1) % N;
		D->data[D->rear] = e;
	}
}

element deleteRear(DequeType *D)
{
	if(isFull(D))
	{
		printf("Empty\n");
		return 0;
	}
	int pos = D->rear;
	D->rear = (D->rear - 1 + N) % N;
	return D->data[pos];
}

element deleteFront(DequeType *D)
{
	if(isEmpty(D))
	{
		printf("Empty\n");
		return 0;
	}
	D->front = (D->front+1) % N;
	return D->data[D->front];
}

void print(DequeType *D)
{
	printf("F : %d, R : %d\n", D->front, D->rear);

	int i = D->front;
	while (i != D->rear)
	{
		i = (i + 1) % N;
		printf("%c ", D->data[i]);
	}
	printf("\n");
}

int getCount(DequeType *D)
{
	int count = D->rear - D->front;
	if (count < 0)
		count += N;
	return count;
}

int main()
{
	DequeType D;
	init(&D);

	element str[N];
	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++)
		addRear(&D, str);
	
	int equal = 1;

	while (getCount(&D) > 1 && equal)
	{
		char first = deleteFront(&D);
		char last = deleteRear(&D);
		if (first != last)
			equal = 0;
	}
	if (equal)
		printf("OK");
	else
		printf("NO");

	return 0;
}
