#include <stdio.h>
#include <stdlib.h>

int cnt;  // 전역변수 지양
int rFib(int n)
{
    cnt++;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return rFib(n - 2) + rFib(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d %d", rFib(n), cnt);

    return 0;
}