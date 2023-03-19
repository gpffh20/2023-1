#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    char c;

    scanf("%c %d %d", &c, &a, &b); // scan해서 a에 넣겠다. a가 메모리 어디에 있는지 모르기 때문에 주소에다 넣어준다.

    printf("%d + %d = %d\n", a, b, a + b);    // "": 문자열(널 포함), '': 문자 -> 'a' vs "a\0"의 차이
    printf("Input character is %c.", c);
    return 0;
}