#include <stdio.h>
#include <stdlib.h>
// 알고리즘 효율 측면에서는 매우 나쁨
// 브루트포스 = 무차별 대입법

void	sumOfWeight(int g)
{
	int count = 0;

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			for (int k = 1; k <= 10; k++)
			{
				if (2*i + 3*j + 5*k == g)
				{
					printf("%d %d %d\n", i, j, k);
					count++;
				}
			}
		}
	}
	if (count == 0)	// 교수님은 이렇게 쓰셨지만 그냥 count만 출력해도 무방할 듯!
		printf("0\n");
	else
		printf("%d\n", count);
}

int main()
{
    int g;
    scanf("%d", &g);
	sumOfWeight(g);

    return 0;
}