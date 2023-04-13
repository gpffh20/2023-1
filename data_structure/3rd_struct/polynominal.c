#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Poly	// 구조체 태그라고 함
{
	int	degree;
	int	coef[N];
}Poly;

Poly	addPoly(Poly A, Poly B)
{
	Poly C;
	int	Apos = 0, Bpos = 0, Cpos = 0;	// index 가르킴
	int Adeg = A.degree;
	int	Bdeg = B.degree;

	C.degree = (Adeg >= Bdeg) ? Adeg : Bdeg;

	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (Adeg > Bdeg)
		{
			C.coef[Cpos] = A.coef[Apos];
			Apos++;
			Cpos++;
			Adeg--;
			Bdeg--;
		}
		else if (Adeg == Bdeg)
		{
			C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos];
			Apos++;
			Bpos++;
			Cpos++;
			Adeg--;
			Bdeg--;
		}
		else
		{
			C.coef[Cpos] = B.coef[Apos];
			Bpos++;
			Cpos++;
			Bdeg--;
		}
	}
	return C;
}

void	printPoly(Poly P)
{
	int i, j;
	for(i = 0, j = P.degree; i <= P.degree; i++, j--)
		printf("%2dx^%d + ", P.coef[i], j);
	printf("\b\b \n");
}

int main()
{
	Poly a, b, c;
	scanf("%d %d", &a.degree, &b.degree);

	for(int i = 0; i <= a.degree; i++)
		scanf("%d", &a.coef[i]);

	for(int i = 0; i <= b.degree; i++)
		scanf("%d", &b.coef[i]);

	printPoly(a);
	printPoly(b);

	c = addPoly(a, b);
	printf("==========================\n");
	printPoly(b);

	return 0;
}
