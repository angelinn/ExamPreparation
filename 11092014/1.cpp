#include <cstdio>
#include <climits>

void square(size_t N, float* X, float* Y)
{
    int xMax = -INT_MAX;
    int yMax = -INT_MAX;
    int xMin = INT_MAX;
    int yMin = INT_MAX;

    for (size_t i = 0; i < N; ++i)
    {
        if (X[i] > xMax)
            xMax = X[i];
        if (Y[i] > yMax)
            yMax = Y[i];
        if (X[i] < xMin)
            xMin = X[i];
        if (Y[i] < yMin)
            yMin = Y[i];
    }

    int yLength = yMax - yMin;
    int xLength = xMax - xMin;

    int centerY = yMin + xLength / 2;
    int centerX = xMin + yLength / 2;

    printf("Center: (%d, %d)\n", centerX, centerY);
    printf("Side: %d\n", yLength > xLength ? yLength : xLength);
}
