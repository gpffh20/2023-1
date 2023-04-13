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
		switch(score / 10)	// 괄호 안 수식의 결과는 무조건 정수 아니면 문자
		{
			case 10 :
			case 9 :	// case가 10 또는 9라면 이라는 의미로 붙여쓰기 가능
				printf("A\n");
				break;	// switch 밖으로 나감
			case 8 :
				printf("B\n");
				break;
			case 7 :
				printf("C\n");
				break;
			default :
				printf("D or F\n");
		}
	}
	
	return 0;
}