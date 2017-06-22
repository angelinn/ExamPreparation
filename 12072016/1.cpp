// 2 1 1 1 1 1 1 1 1 1 3
// 1 2 1 1 1 1 1 1 1 3 1 
// 1 1 2 1 1 1 1 1 3 1 1 
// 1 1 1 2 1 1 1 3 1 1 1 
// 1 1 1 1 2 1 3 1 1 1 1 
// 1 1 1 1 1 2 1 1 1 1 1 
// 1 1 1 1 3 1 2 1 1 1 1 
// 1 1 1 3 1 1 1 2 1 1 1 
// 1 1 3 1 1 1 1 1 2 1 1 
// 1 3 1 1 1 1 1 1 1 2 1
// 3 1 1 1 1 1 1 1 1 1 2 

#include <cstdio>

const int N = 3;
const int GROUPS_COUNT = 4;

void meanSymmetric(int A[][N])
{
    int sums[GROUPS_COUNT] { 0 };
    int means[GROUPS_COUNT] { 0 };
    int center = A[N / 2][N / 2];

    for (int i = 0; i < N; ++i)
    {
        sums[0] += A[i][i];
        sums[1] += A[N / 2][i];
        sums[2] += A[i][N / 2];
        sums[3] += A[i][N - 1 - i];
    }

    for (int i = 0; i < GROUPS_COUNT; ++i)
        means[i] = (sums[i] - center) / (N - 1);

    for (int i = 0; i < N; ++i)
    {
        A[i][i] = means[0];
        A[N / 2][i] = means[1];
        A[i][N / 2] = means[2];
        A[i][N - 1 - i] = means[3];
    }

    A[N / 2][N / 2] = center;
}
