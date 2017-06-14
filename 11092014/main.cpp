#include "2.cpp"

const int N = 5;

char** field = new char*[N];

int main()
{
	field[0] = new char[N] { '1', '1', '0', '2', '0' };
	field[1] = new char[N] { '0', '2', '1', '0', '2' };
	field[2] = new char[N] { '2', 'S', '2', '2', 'K' };
	field[3] = new char[N] { '1', '1', '2', '2', '0' };
	field[4] = new char[N] { '2', '2', '1', '1', '1' };

	Point* point = SeaMonster(Point{ 2, 1 }).allowedMoves();
	for (int i = 0; i < N; ++i)
		if (point[i].x > -1)
			printf("(%d, %d)\n", point[i].x, point[i].y);

	GamePlayer** players = new GamePlayer*[2];
	players[0] = new Knight(Point(2, 4));
	players[1] = new SeaMonster(Point(2, 1));

	allMoves(players, 2);
}
