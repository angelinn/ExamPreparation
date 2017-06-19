#include <cstring>
#include <cstdio>

struct Positions
{
    int i;
    int j;
};

Positions sameSymbols(const char* text)
{
    size_t size = strlen(text);
    Positions max = { -1, -1 };

    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            if (text[i] == text[j] && j - i > max.j - max.i)
            {
                max.j = j;
                max.i = i;

                printf("Set max to %c at [%d][%d]\n", text[i], i, j);
            }
        }
    }

    return max;
}