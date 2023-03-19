#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a, b, c, d, f;
    int score;

    scanf("%d", &score);
    switch (score / 10)
    {
        case 10 : 
            printf("A");
            break;
        case 9 : 
            printf("A");
            break;
        case 8 : 
            printf("B");
            break;
        case 7 : 
            printf("C");
            break;
        case 6 : 
            printf("D");
            break;
        case 5 : 
            printf("F");
            break;
        case 4 : 
            printf("F");
            break;
        case 3 : 
            printf("F");
            break;
        case 2 : 
            printf("F");
            break;
        case 1 : 
            printf("F");
            break;
        case 0 : 
            printf("F");
            break;
        default :
            printf("Wrong Input");
            break;
    }

    return 0;
}