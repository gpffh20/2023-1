#include <stdio.h>
#include <stdlib.h>

int findGcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return findGcd(b, a%b);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", findGcd(a, b));
    return 0;
}