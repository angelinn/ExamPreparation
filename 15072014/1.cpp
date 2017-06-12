#include <cstring>

const int HEIGHT = 10;
const int WIDTH = 10;
const char PATH = '1';

bool isAvailable(const char **, size_t, size_t);
bool checkPattern(const char **, size_t, size_t, const char *);

bool walk(const char** matrix, const char* pattern) 
{
    for (size_t i = 0; i < 9; ++i)
    {
        if (matrix[i][0] == PATH)
        {
            if (checkPattern(matrix, i, 0, pattern))
                return true;
        }
    }

    for (size_t j = 0; j < 9; ++j)
    {
        if (matrix[0][j] == PATH)
        {
            if (checkPattern(matrix, 0, j, pattern))
                return true;
        }
    }

    for (size_t i = 9; i > 0; --i)
    {
        if (matrix[i][9] == PATH)
        {
            if (checkPattern(matrix, i, 9, pattern))
                return true;
        }
    }

    for (size_t j = 0; j > 0; --j)
    {
        if (matrix[9][j] == PATH)
        {
            if (checkPattern(matrix, 9, j, pattern))
                return true;
        }
    }

    return false;
}

bool checkPattern(const char** matrix, size_t i, size_t j, const char* pattern) 
{
    bool isOK = false;
    while (*pattern)
    {
        switch (*pattern) 
        {
            case 'E':
                isOK = isAvailable(matrix, ++i, j);
                break;
            case 'W':
                isOK = isAvailable(matrix, --i, j);
                break;
            case 'N':
                isOK = isAvailable(matrix, i, --j);
                break;
            case 'S':
                isOK = isAvailable(matrix, i, ++j);
                break;
        }

        if (!isOK)
            break;

        ++pattern;
    }   

    return isOK;
}

bool isAvailable(const char** matrix, size_t i, size_t j)
{
    return (i < WIDTH && j < HEIGHT && i >= 0 && j >= 0) && matrix[i][j] == PATH;
}
