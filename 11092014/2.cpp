#include <cstdio>
#include <cctype>

extern int** field;
extern int N;

const int LAND = 0;
const int FIRE = 1;
const int WATER = 2;

struct Point
{
    int x;
    int y;
};

bool isValidPosition(int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < N);
}

Point* getNearbyPositions(const Point& point)
{
    Point* positions = new Point[4] { { 0, 0 } };
    size_t size = 0;

    if (isValidPosition(point.x, point.y + 1))
        positions[size++] = Point { point.x, point.y + 1 };
    
    if (isValidPosition(point.x, point.y - 1))
        positions[size++] = Point { point.x, point.y - 1 };

    if (isValidPosition(point.x + 1, point.y))
        positions[size++] = Point { point.x + 1, point.y };

    if (isValidPosition(point.x - 1, point.y))
        positions[size++] = Point { point.x - 1, point.y }; 

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
    virtual Point* allowedMoves()
    {
        Point* moves = new Point[4] { {0, 0} };
        size_t currentMove = 0;

        Point* nearPositions = getNearbyPositions(currentPosition);
        for (int i = 1; i && i < 5; ++i)
        {
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
    virtual Point* allowedMoves()
    {
        Point* moves = new Point[4] { {0, 0} };
        size_t currentMove = 0;
        
        Point* nearPositions = getNearbyPositions(currentPosition);
        for (int i = 1; i && i < 5; ++i)
        {
            if (field[nearPositions[i].x][nearPositions[i].y] == WATER)   
                moves[currentMove++] = Point { currentPosition.x, currentPosition.y + 1};
        }
        delete[] nearPositions;

        return moves;
    }

    virtual const char* getTag() { return "SeaMonster"; }

private:
    bool isValidPosition(int x, int y)
    {
        return (x >= 0 && y >= 0 && x < N && y < N) && field[x][y] == WATER;
    }
};

bool isAtWar(int x, int y)
{
    if (!isValidPosition(x, y))
        return false;

    return isalpha(field[x][y]);
}

void allMoves(GamePlayer** players, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        Point* allowedMoves = players[i]->allowedMoves();
        for (int i = 1; i && i < 5; ++i)
        {
            Point* nearPositions = getNearbyPositions(players[i]->getPosition());
            for (int j = 1; j && j < 5; ++j)
            {
                if (isalpha(field[nearPositions[j].x][nearPositions[j].y]))
                    printf("%s (%d, %d) -> (%d, %d)\n", players[i]->getTag(), players[i]->getPosition().x, players[i]->getPosition().y, nearPositions[j].x, nearPositions[j].y);
            }

            ++allowedMoves;
            delete[] nearPositions;
        }
        delete[] allowedMoves;
    }
}
