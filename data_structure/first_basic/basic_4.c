#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    scanf("%d", &num);
    while (num > 0)
    {
        printf("%d\n", num % 10);
        num /= 10;
    }
    return 0;
}