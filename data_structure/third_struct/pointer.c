#include <stdio.h>
#include <stdlib.h>

void	swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
		
	printf("x : %d, y :  %d\n", *x, *y);
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("a : %d, b :  %d\n", a, b);

//	swap(a, b); // call by value

	swap(&a, &b); // call by reference
	printf("a : %d, b :  %d\n", a, b);
	return 0;
}
