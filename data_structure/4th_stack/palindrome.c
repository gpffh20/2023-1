#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct
{
	char	data[N];
	int		top;
}StackType;

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

void setAns(char arr[], char ans[])
{
	char c;
	int idx = -1;

	for (int i = 0; i < strlen(arr); i++)
	{
		c = arr[i];
		if (('a' <= c) && (c <= 'z'))
			ans[++idx] = c;
		else if (('A' <= c) && (c <= 'Z'))
			ans[++idx] = c + 32;
	}
	ans[++idx] = 0;
}

int isPalin(char ans[])
{
	StackType S;
	int n = strlen(ans);
	int i = 0;
	int isOdd = n % 2; // 이거 지우고

	init(&S);
	for(; i < n/2; i++)
		push(&S, ans[i]);
	if(isOdd) // isOdd 대신 n%2바로 넣어도 될 듯
		i++;
	while (i < n && peek(&S) == ans[i])
	{
		pop(&S);
		i++;
	}
	if (isEmpty(&S))
		return 1;
	return 0;
}

int main()
{
	char arr[N], ans[N];
	
	scanf("%[^\n]", arr);
	setAns(arr, ans);

	if (isPalin(ans))
		printf("회문입니다.\n");
	else
		printf("회문이 아닙니다.\n");

	return 0;
}
