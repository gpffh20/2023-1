#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // 난수 발생을 위한 헤더
#define N 10


void    makeArray(int A[])
{
    for (int i = 0; i < N; i++)
        A[i] = rand() % 100 + 1;
}

void printArray(int A[])
{
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int findMax(int A[])
{
    int max = A[0];

    for (int i = 1; i < N; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

int main()
{
    int A[N];   //레퍼런스 변수로 생각하면됨. 배열의 이름은 주소를 갖고 있기 때문
    srand(time(NULL));  // 난수 발생시키기 전에 하기, 이거 실행시킬 때 시간 값임. 항상 바뀜 -> 난수 발생

//    for (int i = 0; i < N; i++)
//        A[i] = rand() % 100 + 1;    // 1~100 까지 발생
    makeArray(A);

//    for (int i = 0; i < N; i++)
//        printf("%d ", A[i]);
    printArray(A); 
    
    printf("Max Value is %d\n", findMax(A));
    
    return 0;
}