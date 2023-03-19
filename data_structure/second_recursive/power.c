#include <stdio.h>
#include <stdlib.h>

int rPower(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return rPower(x*x, n/2);
    else
        return x * rPower(x*x, (n-1)/2);
}

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%d", rPower(x, n));

    return 0;
}