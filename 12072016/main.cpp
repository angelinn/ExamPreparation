#include "2.cpp"
#include "1.cpp"

void printMatrix(int A[][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			printf("[%d] ", A[i][j]);
		
		printf("\n");
	}
}

int main()
{
	Node* root = buildTree("./tree.txt");
	printTree(root);

	int matrix[][3] = 
	{
		{ 1, 2, 4 },
		{ 10, 5, 12 },
		{ 3, 8, 18 }
	};

	printf("\n");
	printMatrix(matrix);
	printf("\n");

	meanSymmetric(matrix);

	printMatrix(matrix);
}
