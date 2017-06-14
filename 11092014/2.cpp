#include <cstdio>
#include <cctype>

extern char** field;
extern const int N;

const char LAND = '0';
const char FIRE = '1';
const char WATER = '2';

struct Point
{
	int x;
	int y;

	Point(int newX = -1, int newY = -1) : x(newX), y(newY)
	{   }
};

bool isValidPosition(int x, int y)
{
	return (x >= 0 && y >= 0 && x < N && y < N);
}

Point* getNearbyPositions(const Point& point)
{
	Point* positions = new Point[N];
	size_t size = 0;

	if (isValidPosition(point.x, point.y + 1))
		positions[size++] = Point{ point.x, point.y + 1 };

	if (isValidPosition(point.x, point.y - 1))
		positions[size++] = Point{ point.x, point.y - 1 };

	if (isValidPosition(point.x + 1, point.y))
		positions[size++] = Point{ point.x + 1, point.y };

	if (isValidPosition(point.x - 1, point.y))
		positions[size++] = Point{ point.x - 1, point.y };

	return positions;
}

class GamePlayer
{
public:
	virtual Point getPosition()
	{
		return currentPosition;
	}

	virtual Point* allowedMoves() = 0;
	virtual const char* getTag() = 0;

protected:
	Point currentPosition;
};

class Knight : public GamePlayer
{
public:
	Knight(Point point)
	{
		currentPosition = point;
	}

public:
	virtual Point* allowedMoves()
	{
		Point* moves = new Point[N];

		size_t currentMove = 0;
		Point* nearPositions = getNearbyPositions(currentPosition);
		for (int i = 0; i < N; ++i)
		{
			if (nearPositions[i].x == -1)
				break;

			if (!hasAdjacentFire(nearPositions[i].x, nearPositions[i].y))
				moves[currentMove++] = nearPositions[i];
		}

		delete[] nearPositions;
		return moves;
	}

	virtual const char* getTag() { return "Knight"; }

private:
	bool hasAdjacentFire(int x, int y)
	{
		if (isValidPosition(x, y + 1))
		{
			if (field[x][y + 1] == FIRE)
				return true;
		}

		if (isValidPosition(x, y - 1))
		{
			if (field[x][y - 1] == FIRE)
				return true;
		}

		if (isValidPosition(x + 1, y))
		{
			if (field[x + 1][y] == FIRE)
				return true;
		}

		if (isValidPosition(x - 1, y))
		{
			if (field[x - 1][y] == FIRE)
				return true;
		}

		return false;
	}
};

class SeaMonster : public GamePlayer
{
public:
	SeaMonster(Point point)
	{
		currentPosition = point;
	}

public:
	virtual Point* allowedMoves()
	{
		return allowedMovesRecursive(currentPosition);
	}

	virtual const char* getTag() { return "SeaMonster"; }

private:
	Point* allowedMovesRecursive(const Point& start)
	{
		Point* moves = new Point[N];
		size_t currentMove = 0;

		Point* nearPositions = getNearbyPositions(start);
		for (int i = currentPosition.x - 1; i >= 0; --i)
		{
			if (field[i][currentPosition.y] != WATER)
				break;

			moves[currentMove++] = Point(i, currentPosition.y);
		}

		for (int i = currentPosition.x + 1; i < N; ++i)
		{
			if (field[i][currentPosition.y] != WATER)
				break;
			moves[currentMove++] = Point(i, currentPosition.y);
		}

		for (int i = currentPosition.y - 1; i >= 0; --i)
		{
			if (field[currentPosition.x][i] != WATER)
				break;
			moves[currentMove++] = Point(currentPosition.x, i);
		}

		for (int i = currentPosition.y + 1; i < N; ++i)
		{
			if (field[currentPosition.x][i] != WATER)
				break;
			moves[currentMove++] = Point(currentPosition.x, i);
		}

		return moves;
	}

	bool isValidPosition(int x, int y)
	{
		return (x >= 0 && y >= 0 && x < N && y < N) && field[x][y] == WATER;
	}
};

void allMoves(GamePlayer** players, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		Point* allowedMoves = players[i]->allowedMoves();
		for (int k = 0; k < N; ++k)
		{
			if (allowedMoves[k].x == -1)
				break;

			Point* nearPositions = getNearbyPositions({allowedMoves[k].x, allowedMoves[k].y});
			for (int j = 0; j < N; ++j)
			{
				if (nearPositions[j].x == -1)
					break;

				if (isalpha(field[nearPositions[j].x][nearPositions[j].y]) && field[nearPositions[j].x][nearPositions[j].y] != players[i]->getTag()[0])
					printf("%s (%d, %d) -> (%d, %d)\n", players[i]->getTag(), players[i]->getPosition().x, players[i]->getPosition().y, allowedMoves[k].x, allowedMoves[k].y);
			}

			delete[] nearPositions;
		}
		delete[] allowedMoves;
	}
}
