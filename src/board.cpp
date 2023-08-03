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

bool Board::setInColumn(int column, char player)
{
    //check if something can be set in the column
    if (board[0][column] != '0') return false;

    //find lowest possible placement
    int lowest;
    for (lowest = 5; lowest != '0'; lowest--) {}

    board[lowest][column] = player;
    return true;
}