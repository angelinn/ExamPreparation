#include "1.cpp"
#include <cstdio>

int main()
{
    int a[] = { 1, 2, 3, 4 ,5 ,6 ,7 ,8 ,9 ,10 };
    printf("Is 9 a member : %d\n", member(9, a, 10));


    int b[] = { 10, 14, 7, 0, 23, 1, 11 };
    int N = 7;
    selectionSort(b, N);

    for (int i = 0; i < N; ++i)
        printf ("%d, ", b[i]);
    
    printf("\n");

    printf("%d\n", somethingElse());
}
