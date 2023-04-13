#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct Poly	// 구조체 태그라고 함
{
	int	degree;
	int coef;
	int	expon;
}Poly;

Poly terms[N] = {{8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0}};
int	avail = 6;

void	printPoly(int s, int e)
{
	for(int i = s; i <= e; i++)
		printf("%2dx^%d + ", terms[i].coef, terms[i].expon);
	printf("\b\b \n");
}

int main()
{
	int	As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	
	printPoly(As, Ae);
	printPoly(Bs, Be);


	return 0;
}
