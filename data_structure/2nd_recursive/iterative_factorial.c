#include <stdio.h>
#include <stdlib.h>

int iFact(int n)
{
    int result = 1;
    for(int i = 1; i <= n; i++) // 시간복잡도 : n
        result *= i;
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", iFact(n));

    return 0;
}