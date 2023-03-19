#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int even_total = 0;
    int odd_total = 0;

    scanf("%d", &num);
    for(int i = 1; i <= num; i++)
    {
        odd_total += i;
        i++;
        even_total += i;
    }
    printf("짝수의 합 : %d\n", even_total);
    printf("홀수의 합 : %d\n", odd_total);
    return 0;
}