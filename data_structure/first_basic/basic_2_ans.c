#include <stdio.h>
#include <stdlib.h>

int main()
{
	int score;
	scanf("%d", &score);
	if (score < 0 || score > 100)
	{
		printf("Wrong Input\n");
	}
	else
	{
		if (score >= 90 && score <= 100)
			printf("A\n");
		else if (score >= 80 && score < 90)
			printf("B\n");
		else if (score >= 70 && score <80)
			printf("C\n");
		else
			printf("D or F\n");
	}
	
	return 0;
}