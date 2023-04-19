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

char	peak(StackType *S)
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

int prec(char op)
{
	switch (op)
	{
		case '(': case ')':
			return 0;
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
	}
}

void convert(char exp[])
{
	StackType S;
	init(&S);

	char c, t;
	int n = strlen(exp);

	for (int i = 0; i < n; i++)
	{
		c = exp[i];
		switch (c)
		{
			case '+': case '-': case '*': case '/':
// prec(c)는 이제 들어갈 연산자, peek는 이미 있던 연산자 우선순위 비교
				while (!isEmpty(&S) && prec(c) <= prec(peak(&S)))
					printf("%c", pop(&S));
				push(&S, c);
				break;

			case '(':
				push(&S, c);
				break;

			case ')':
				t = pop(&S);
				while (t != '(')
				{
					printf("%c", t);
					t = pop(&S);
				}

			default:
				printf("%c", c);
				break;
		}
	}
	while (!isEmpty(&S))
		printf("%c", pop(&S));
	printf("\n");
}

int main()
{
	char exp[N];
	scanf("%s", exp);

	convert(exp);
	return (0);
}

