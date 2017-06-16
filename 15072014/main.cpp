#include "1.cpp"
#include "2.cpp"
#include <cstdio>

int main()
{
	// int matrix[10][10] =
	// {
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	// 	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	// 	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	// 	{ 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	// };

	// char pattern[] = "NESEESEEENEEESSSSSSS";

	// printf("Walked: %d\n", walk(matrix, pattern));

	Rook rook;
	rook.setPosition({ 1, 'A' });

	Knight knight;
	knight.setPosition({ 3, 'B' });

	allMoves(new ChessPiece*[2] { &rook, &knight }, 2);
}
