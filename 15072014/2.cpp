struct ChessPosition
{
    int x;
    char y;

    ChessPosition(int x = -1, char y = -1) : x(x), y(y)
    {   }
};

class ChessPiece
{
public:
    virtual ChessPosition* allowedMoves() = 0;
    ChessPosition getPosition() { return position; }
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
    virtual ChessPosition* allowedMoves()
    {
        size_t moveCount = 0;
        ChessPosition* moves = new ChessPosition[16];
        for (char i = position.y; i <= 'H'; ++i)
            moves[moveCount++] = ChessPosition { position.x, i };
            
        for (char i = position.y; i >= 'A'; --i)
            moves[moveCount++] = ChessPosition { position.x, i };

        for (int i = position.x; i <= 8; ++i)
            moves[moveCount++] = ChessPosition { i, position.y };
            
        for (int i = position.x; i >= 1; --i)
            moves[moveCount++] = ChessPosition { i, position.y };

        return moves;
    }
};

class Knight : public ChessPiece
{
public:
    virtual ChessPosition* allowedMoves()
    {
        size_t moveCount = 0;
        ChessPosition* moves = new ChessPosition[8];

        if (position.x + 3 <= 8)
        {
            if (position.y + 1 <= 'H')
                moves[moveCount++] = ChessPosition { position.x + 3, position.y + 1 };
            if (position.y - 1 >= 'A')
                moves[moveCount++] = ChessPosition { position.x + 3, position.y - 1 };
        }

        if (position.x - 3 >= 1)
        {
            if (position.y + 1 <= 'H')
                moves[moveCount++] = ChessPosition { position.x - 3, position.y + 1 };
            if (position.y - 1 >= 'A')
                moves[moveCount++] = ChessPosition { position.x - 3, position.y - 1 };
        }

        if (position.y + 3 <= 'H')
        {
            if (position.x + 1 <= 8)
                moves[moveCount++] = ChessPosition { position.x + 1, position.y + 3 };
            if (position.x - 1 >= 1)
                moves[moveCount++] = ChessPosition { position.x - 1, position.y + 3 };
        }

        if (position.y - 3 >= 'A')
        {
            if (position.x + 1 <= 8)
                moves[moveCount++] = ChessPosition { position.x + 1, position.y - 3 };
            if (position.x - 1 >= 1)
                moves[moveCount++] = ChessPosition { position.x - 1, position.y - 3 };
        }

        return moves;
    }
};

void allMoves(ChessPiece** pieces) 
{

}
