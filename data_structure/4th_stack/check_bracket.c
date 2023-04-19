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

int check(s)
{
	StackType S;
	init(&S);

	char c, t;
	int n = strlen(str);

	for (int i = 0;; i < n; i++)
	{
		c = str[i];
		if(c == '(' || c == '{' || c == '[')
			push(&S, c);
		else if(c == ')' || c == '}' || c == ']')
		{
			if (isEmpty(&S))
				return 0;
			else
			{
				t = pop(&S);
				if ((t  == '(' && c != ')') ||
					(t  == '{' && c != '}') ||
					(t  == '[' && c != ']'))
					return 0;
			}
		}
	}
	return isEmpty(&S);
}

int main()
{
	char str[N];

	scanf()
	if (check(str))
		printf("OK");
	else
		printf("NO");

	return 0;
}
