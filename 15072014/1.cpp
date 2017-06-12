#include <cstring>

const int HEIGHT = 10;
const int WIDTH = 10;
const char PATH = '1';

bool walk(const char** matrix, const char* pattern) 
{
    size_t patternSize = strlen(pattern);

    size_t i, j = 0;
    bool isOK = false;

    for (size_t k = 0; k < patternSize; ++k) 
    {
        switch (pattern[i]) 
        {
            case 'E':
                isOK = isAvailable(matrix, i + 1, j);
                break;
            case 'W':
                isOK = isAvailable(matrix, i - 1, j);
                break;
            case 'N':
                isOK = isAvailable(matrix, i, j - 1);
                break;
            case 'S':
                isOK = isAvailable(matrix, i, j + 1);
                break;
        }

        if (!isOK)
            break;
    }

    return isOK;
}

bool isAvailable(const char** matrix, size_t i, size_t j)
{
    return (i < WIDTH && j < HEIGHT && i >= 0 && j >= 0) && matrix[i][j] == PATH;
}