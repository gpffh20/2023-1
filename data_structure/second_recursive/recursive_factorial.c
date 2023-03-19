#include <stdio.h>
#include <stdlib.h>

int rFact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * rFact(n - 1);    // 시간복잡도 : n + 함수호출(메모리에 갔다옴. 즉 오래걸림)
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", rFact(n));

    return 0;
}