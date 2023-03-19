#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score;

    scanf("%d", &score);
    if (90 <= score && score <= 100)
        printf("A");
    else if(80 <= score && score < 90)
        printf("B");
    else if(70 <= score && score < 80)
        printf("C");
    else if(60 <= score && score < 70)  // D가 아닌 D or F가 되어야 함
        printf("D");
    else if(0 <= score && score < 60)   // D가 아닌 D or F가 되어야 함
        printf("F");
    else
        printf("Wrong Input");  // 오류처리는 제일 위에 넣는게 좋을 듯!
    return 0;
}