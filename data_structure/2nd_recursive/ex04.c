#include <stdio.h>
#include <stdlib.h>

void    makeArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

int findMax(int arr[], int n)
{
    if (n == 0)
        return arr[0];
    int max = findMax(arr, n - 1);
    arr[n] = max < arr[n] ? arr[n] : max;
    return arr[n];
}

int main()
{
    int n, tmp;
    scanf("%d", &n);

    int arr[n];
    makeArr(arr, n);   

    printf("%d\n", findMax(arr, n));
    return 0;
}