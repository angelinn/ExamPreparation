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

void meanSymmetric(int A[][N])
{
    int sums[4] { 0 };
    int means[4] { 0 };

    for (int i = 0; i < N; ++i)
    {
        sums[0] += A[i][i];
        sums[1] += A[N / 2][i];
        sums[2] += A[i][N / 2];
        sums[3] += A[i][N - 1 - i];
    }
    
    sums[0] -= A[N / 2][N / 2];
    sums[1] -= A[N / 2][N / 2];
    sums[2] -= A[N / 2][N / 2];
    sums[3] -= A[N / 2][N / 2];
    
    means[0] = sums[0] / (N - 1);
    means[1] = sums[1] / (N - 1);
    means[2] = sums[2] / (N - 1);
    means[3] = sums[3] / (N - 1);

    for (int i = 0; i < N; ++i)
    {
        if (i != N / 2)
        {
            A[i][i] = means[0];
            A[N / 2][i] = means[1];
            A[i][N / 2] = means[2];
            A[i][N - 1 - i] = means[3];
        }
    }
}
