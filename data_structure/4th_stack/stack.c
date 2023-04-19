#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct
{
	char	data[N];
	int		top;
}StackType;
// 끝에 Type이 들어오면 최종 자료구조이고, 아니면 중간 과정임.

void	init(StackType *S)
{
	S->top = -1;
}

int	isEmpty(StackType *S)
{
	return S->top == -1;
}

int	isFull(StackType *S)
{
	return S->top == N - 1;
}

void	push(StackType *S, char c)
{
	if (isFull(S))
		printf("Overflow\n");
	else
	{
		S->top++;
		S->data[S->top] = c;
	}
}

char	pop(StackType *S)
{
	if (isEmpty(S))
	{
		printf("Empty\n");
		return -1;
	}

	char c = S->data[S->top];
	S->top--;
	return c;
}

char	peek(StackType *S)
{
	if (isEmpty(S))
	{
		printf("Empty\n");
		return -1;
	}

	return S->data[S->top];
}

void	print(StackType *S)
{
	for (int i = 0; i <= S->top; i++)
		printf("%c", S->data[i]);
	printf("\n");
}

int main()
{
	StackType S;
	init(&S);
	// 초기화 해주는 함수 init.
	// 구조체는 레퍼런스 변수가 아니라 그냥 보내면 값이 감.

	push(&S, 'C');
	push(&S, 'a');
	push(&S, 't');
	push(&S, 's');

	print(&S);
	getchar();

	printf("Pop : %c\n", pop(&S));
	print(&S);
	getchar();

	printf("Peak : %c\n", peak(&S));
	print(&S);
	getchar();

	return 0;
}
