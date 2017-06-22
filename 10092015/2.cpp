#include <cstdio>

bool DFS(int** g, int i, bool* visited, size_t N)
{
	bool notVisited = false;
	if (!visited[i])
		notVisited = true;

	visited[i] = true;

	for (int j = 0; j < N; ++j)
	{
		if (!visited[j] && g[i][j])
		{
			DFS(g, j, visited, N);
		}
	}

	return notVisited;
}

int** reverseGraph(int** g, size_t N)
{
	int** rg = new int*[N];
	for (size_t i = 0; i < N; ++i)
		rg[i] = new int[N] { 0 };

	bool** visited = new bool*[N];
	for (size_t i = 0; i < N; ++i)
		visited[i] = new bool[N] { false };

	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			if (g[i][j] && !visited[i][j])
			{
				visited[i][j] = true;
				visited[j][i] = true;

				rg[j][i] = g[i][j];
				g[i][j] = 0;
			}
		}
	}

	for (size_t i = 0; i < N; ++i)
		delete[] visited[i];

	delete[] visited;
	return rg;
}

bool isConnected(int** g, size_t N, bool reversed = false)
{
	bool connected = true;

	bool* visited = new bool[N] { false };
	DFS(g, 0, visited, N);
	for (size_t i = 1; i < N; ++i)
	{
		if (DFS(g, i, visited, N))
			connected = false;
	}

	delete[] visited;

	if (connected)
		return true;

	if (reversed)
		return connected;

	int** newGraph = reverseGraph(g, N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			printf("[%d][%d] = %d\n", i, j, newGraph[i][j]);
		printf("\n");
	}

	if (!isConnected(newGraph, N, true))
		return false;

	return true;
}