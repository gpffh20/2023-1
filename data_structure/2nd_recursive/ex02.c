#include <stdio.h>
#include <stdlib.h>

void    printNum(int n)
{
    if (n / 10 > 0)
        printNum(n / 10);
    printf("%d\n", n % 10);
}

int main()
{
    int n;
    scanf("%d", &n);
    printNum(n);

    return 0;
}