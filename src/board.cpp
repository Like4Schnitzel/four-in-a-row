#include "board.hpp"

Board::Board()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = '0';
        }
    }
}

char Board::getSlot(const int row, const int column)
{
    if (row > 5 || row < 0 || column > 6 || column < 0)
        return '0';

    //else
    return board[row][column];
}

int Board::getLowest(const int column)
{
    int lowest;
    for (lowest = 5; lowest >= 0 && board[lowest][column] != '0'; lowest--) {}
    return lowest;
}

bool Board::setInColumn(const int column, const char player)
{
    //check if something can be set in the column
    if (board[0][column] != '0') return false;

    //find lowest possible placement
    const int lowest = getLowest(column);

    board[lowest][column] = player;
    return true;
}

bool Board::checkLine(int x, int y, const int xDiff, const int yDiff, const char player)
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (getSlot(x, y) == player)
        {
            count++;
            if (count == 4)
            {
                return true;
            }
        }
        else count = 0;

        x += xDiff;
        y += yDiff;
    }

    return false;
}

bool Board::winCheck(const int row, const int column)
{
    const char currentPlayer = board[row][column];
    if (checkLine(row - 4, column - 4, 1, 1, currentPlayer) || //diagonal
        checkLine(row + 4, column - 4, -1, 1, currentPlayer) || //other diagonal
        checkLine(row - 4, column, 1, 0, currentPlayer) || //vertical
        checkLine(row, column - 4, 0, 1, currentPlayer) ) // horizontal
        return true;
    //else
    return false;
}

void Board::printBoard()
{
    for (int i = 0; i < 6; i++)
    {
        std::cout << i + 1 << " -";
        for (int j = 0; j < 7; j++)
        {
            std::cout << " " << board[i][j];
        }
        std::cout << "\n";
    }

    std::cout << "   ";
    for (int i = 0; i < 7; i++)
    {
        std::cout << " |";
    }
    std::cout << "\n   ";
    for (int i = 1; i <= 7; i++)
    {
        std::cout << " " << i;
    }
    std::cout << "\n";
}