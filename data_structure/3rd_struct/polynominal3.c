// 실행안됨

#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct Poly	// 구조체 태그라고 함
{
	int coef;
	int	expon;
}Poly;

Poly terms[N] = {{8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0}};
int	avail = 6;

char compare(int exponA, int exponB)
{
    if (exponA > exponB)
        return '>';
    else if (exponA == exponB)
        return '=';
    else
        return '<';
}

void	attatch(int coef, int expon)
{
	terms[avail].coef = coef;
	terms[avail].expon = expon;

}

void    add(int As, int Ae, int Bs, int Be, int Cs, int *Ce)
{
    while (As <= Ae && Bs <= Be)
    {
        switch (compare(terms[As].expon, terms[Bs].expon))
        {
            case '>':
				attatch(terms[As].coef, terms[As].expon);
				As++; 
                break;
            
            case '=':
				int tempCoef = terms[As].coef + terms[Bs].coef;
				if(tempCoef != 0)
				{
					attatch(tempCoef, terms[As].expon);
					As++;
					Bs++;
				}
                break;

            case '<':
				attatch(terms[Bs].coef, terms[Bs].expon);
				Bs++;
                break;
        }
    }
	for (; As <= Ae; As++)
		attatch(terms[As].coef, terms[Ae].expon);
	for (; Bs <= Be; Bs++)
		attatch(terms[Bs].coef, terms[Be].expon);
	*Ce = avail - 1;
}

void	printPoly(int s, int e)
{
	for(int i = s; i <= e; i++)
		printf("%2dx^%d + ", terms[i].coef, terms[i].expon);
	printf("\b\b \n");
}

int main()
{
	int	As = 0, Ae = 2, Bs = 3, Be = 5, Cs = avail, Ce;
	printPoly(As, Ae);
	printPoly(Bs, Be);

    add(As, Ae, Bs, Be, Cs, &Ce);
	printf("===================");
	printPoly(Cs, Ce);

	return 0;
}
