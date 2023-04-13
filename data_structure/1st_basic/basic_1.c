#include <stdio.h>
#include <stdlib.h>

int main()
{
    int price, cnt, money;

    scanf("%d %d %d", &price, &cnt, &money);
    int total = price * cnt;
    if (money < total)
        printf("모자란 금액 : %d\n", total - money);
    else
        printf("모자란 금액이 없습니다.");

    return 0;
}