#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, evenSum = 0, oddSum = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
		if (i % 2 == 0)
	   		evenSum += i;
        else
			oddSum += i;
    }

	printf("Even : %d, Odd : %d\n", evenSum, oddSum);

    return 0;
}