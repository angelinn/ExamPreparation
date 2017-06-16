#include <cstdio>

struct ChessPosition
{
	int x;
	char y;

    ChessPosition(int x = -1, int y = -1) : x(x), y(y)
    {   }

	bool operator==(const ChessPosition& other)
	{
		return x == other.x && y == other.y;
	}
};

class ChessPiece
{
public:
	virtual const char* getName() const = 0;
	virtual ChessPosition* allowedMoves() = 0;
	ChessPosition getPosition() { return position; }
	void setPosition(ChessPosition pos) { position = pos; }
	bool captures(ChessPosition pos)
	{
		ChessPosition* moves = allowedMoves();
		for (int i = 0; moves[i].x != -1; ++i)
		{
			if (moves[i] == pos)
			{
				delete[] moves;
				return true;
			}
		}

		delete[] moves;
		return false;
	}

protected:
	ChessPosition position;
};

class Rook : public ChessPiece
{
public:
	virtual const char* getName() const { return "Rook"; }
	virtual ChessPosition* allowedMoves()
	{
		size_t moveCount = 0;
		ChessPosition* moves = new ChessPosition[32];
		for (char i = position.y; i <= 'H'; ++i)
			moves[moveCount++] = ChessPosition{ position.x, i };

		for (char i = position.y; i >= 'A'; --i)
			moves[moveCount++] = ChessPosition{ position.x, i };

		for (int i = position.x; i <= 8; ++i)
			moves[moveCount++] = ChessPosition{ i, position.y };

		for (int i = position.x; i >= 1; --i)
			moves[moveCount++] = ChessPosition{ i, position.y };

		return moves;
	}
};

class Knight : public ChessPiece
{
public:
	virtual const char* getName() const { return "Knight"; }

	virtual ChessPosition* allowedMoves()
	{
		size_t moveCount = 0;
		ChessPosition* moves = new ChessPosition[8];

		if (position.x + 3 <= 8)
		{
			if (position.y + 1 <= 'H')
				moves[moveCount++] = ChessPosition{ position.x + 3, position.y + 1 };
			if (position.y - 1 >= 'A')
				moves[moveCount++] = ChessPosition{ position.x + 3, position.y - 1 };
		}

		if (position.x - 3 >= 1)
		{
			if (position.y + 1 <= 'H')
				moves[moveCount++] = ChessPosition{ position.x - 3, position.y + 1 };
			if (position.y - 1 >= 'A')
				moves[moveCount++] = ChessPosition{ position.x - 3, position.y - 1 };
		}

		if (position.y + 3 <= 'H')
		{
			if (position.x + 1 <= 8)
				moves[moveCount++] = ChessPosition{ position.x + 1, position.y + 3 };
			if (position.x - 1 >= 1)
				moves[moveCount++] = ChessPosition{ position.x - 1, position.y + 3 };
		}

		if (position.y - 3 >= 'A')
		{
			if (position.x + 1 <= 8)
				moves[moveCount++] = ChessPosition{ position.x + 1, position.y - 3 };
			if (position.x - 1 >= 1)
				moves[moveCount++] = ChessPosition{ position.x - 1, position.y - 3 };
		}

		return moves;
	}
};

struct Pair
{
	ChessPiece* player;
	ChessPosition value;
};

void allMoves(ChessPiece** pieces, size_t size)
{
	int current = 0;
	Pair* allMoves = new Pair[size * 16];
	for (size_t i = 0; i < size; ++i)
	{
		ChessPosition* allowedMoves = pieces[i]->allowedMoves();
		for (int j = 0; allowedMoves[j].x != -1; ++j)
		{
			allMoves[current].player = pieces[i];
			allMoves[current++].value = allowedMoves[j];
		}
		delete[] allowedMoves;
	}

	for (int i = 0; i < current - 1; ++i)
	{
		for (int j = i + 1; j < current; ++j)
		{
			if (allMoves[i].player && allMoves[j].player && allMoves[i].value == allMoves[j].value)
			{
				allMoves[i].player = nullptr;
				allMoves[j].player = nullptr;
			}
		}
		if (allMoves[i].player)
			printf("%s %c%d = %c%d\n", allMoves[i].player->getName(), allMoves[i].player->getPosition().y, allMoves[i].player->getPosition().x, allMoves[i].value.y, allMoves[i].value.x);

	}
    delete[] allMoves;
}