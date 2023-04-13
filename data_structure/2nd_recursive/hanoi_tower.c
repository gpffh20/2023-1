#include <stdio.h>
#include <stdlib.h>

void hanoiTower(int n, char from, char tmp, char to)  //n = 원반의 개수 char는 위치정보
{
    if (n == 1)
        printf("Disk %d : Move from %c to %c.\n", n, from, to);
    else
    {
        hanoiTower(n-1, from, to, tmp);  // a에서 b로 움직임. -> a에서 c를 이용해서 b로 움직임.
        printf("Disk %d : Move from %c to %c.\n", n, from, to);
        hanoiTower(n-1, tmp, from, to);   //  b에 있는걸 c로 옮김
    }
}
int main()
{
    hanoiTower(4, 'A', 'B', 'C');

    return 0;
}