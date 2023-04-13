#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value;
    scanf("%d", &value);

    while (value != 0)
    {
        printf("%d\n", value % 10);
        value = value / 10;
    }
    
    return 0;
}