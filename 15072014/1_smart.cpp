#include <cstdio>
#include <cstring>

const int MATRIX_SIZE = 10;
const int PATH = 1;
const int WALL = 0;

bool areBoundsOK(int matrix[][MATRIX_SIZE], int i, int j)
{
    return (i > -1 && j > -1 && j < MATRIX_SIZE && i < MATRIX_SIZE) && matrix[i][j] == PATH;
}

bool walk(int matrix[][MATRIX_SIZE], const char* pattern)
{
    int i = MATRIX_SIZE - 1;
    int j = MATRIX_SIZE - 1;

    size_t patternLength = strlen(pattern);
    for (int k = patternLength - 1; k > -1; --k)
    {
        switch (pattern[k])
        {
            case 'S':
                if (!areBoundsOK(matrix, i - 1, j))
                    return false;
                --i;
                break;
            case 'W':
                if (!areBoundsOK(matrix, i, j + 1))
                    return false;
                ++j;
                break;
            case 'N':
                if (!areBoundsOK(matrix, i + 1, j))
                    return false;
                ++i;
                break;
            case 'E':
                if (!areBoundsOK(matrix, i, j - 1))
                    return false;
                --j;
                break;
        }
    }

    printf("Start - [%d][%d]\n", i, j);
    return true;
}
