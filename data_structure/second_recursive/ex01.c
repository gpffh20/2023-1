#include <stdio.h>
#include <stdlib.h>

int rSum(int n)
{
    if (n == 1)
        return 1;
    else
        return n + rSum(n-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", rSum(n));
    
    return 0;
}