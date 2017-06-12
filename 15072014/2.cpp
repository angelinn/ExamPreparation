struct ChessPosition
{
    char x;
    int y;
};

class ChessPiece
{
public:
    virtual ChessPosition getPosition() = 0;
    virtual ChessPosition* allowedMoves() = 0;
    virtual bool captures(ChessPosition pos) = 0;
};

class Rook : public ChessPiece
{

};

class Knight : public ChessPiece
{

};

void allMoves(ChessPiece** pieces) 
{

}
