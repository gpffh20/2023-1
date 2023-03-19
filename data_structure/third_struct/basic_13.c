#include <stdio.h>
#include <stdlib.h>

typedef struct Test
{
	int	a;
	int b;

}Test;	// 구조체 태그와 같은 이름으로 하기

void	add(Test *t, int amount)
{
	t->b += amount;
	printf("%d - %d\n", t->a, t->b);
}

int main()
{
	Test t;

	scanf("%d %d", &t.a, &t.b);
	printf("%d - %d\n", t.a, t.b);

	int amount;
	scanf("%d", &amount);

	add(&t, amount);
	printf("%d - %d\n", t.a, t.b);
	return 0;
}
