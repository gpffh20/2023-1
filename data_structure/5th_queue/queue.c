#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef char element;	// queue에 넣는 자료형만 해당. 나중에 바꿀 때 편하니까~

typedef struct
{
	element data[N];
	int rear, front;
} QueueType;

void init(QueueType *Q)
{
	Q->front = Q->rear = -1;
}

int isEmpty(QueueType *Q)
{
	return Q->rear == Q->front;
}

int isFull(QueueType *Q)
{
	return Q->rear == N - 1;
}

void enqueue(QueueType *Q, element e)
{
	if(isFull(Q))
		printf("Full\n");
	else
	{
		Q->rear++;
		Q->data[Q->rear] = e;
	}
}

void print(QueueType *Q)
{
	printf("F : %d, R : %d\n", Q->front, Q->rear);

	for (int i = Q->front + 1; i <= Q->rear; i++)
		printf("%c ", Q->data[i]);
	printf("\n");
}

element dequeue(QueueType *Q)
{
	if(isEmpty(Q))
	{
		printf("Empty\n");
		return 0;
	}
	Q->front++;
	return Q->data[Q->front];
}

int main()
{
	QueueType Q;
	init(&Q);
	srand(time(NULL));

	for(int i = 0; i < 7; i++)
		enqueue(&Q, rand() % 26 + 65);	// 난수 발생시켜서 char로 변환해줌
	print(&Q);
	getchar();

	for(int i = 0; i < 4; i++)
		printf("(%c)", dequeue(&Q));
	printf("\n\n");

	print(&Q);
	return 0;
}
