#include <cstdio>

void subsample(int m, int n, float** img)
{
	int newWidth = (m + 1) / 2;
	int newHeight = (n + 1) / 2;

	float** newArray = new float*[newWidth];
	for (int i = 0; i < newWidth; ++i)
		newArray[i] = new float[newHeight] { 0 };

	for (int i = 0; i < newWidth; ++i)
	{
		for (int j = 0; j < newHeight; ++j)
		{
			int total = 0;

			for (int y = i * 2; y <= i * 2 + 1; ++y)
			{
				for (int x = j * 2; x <= j * 2 + 1; ++x)
				{
					if (y >= m || x >= n)
						break;

					newArray[i][j] += img[y][x];
					++total;
				}
			}

			newArray[i][j] /= total;

			printf("[%d][%d] - %f\n", i, j, newArray[i][j]);
		}
	}

	for (int i = 0; i < newWidth; ++i)
		delete[] newArray[i];

	delete[] newArray;

}
