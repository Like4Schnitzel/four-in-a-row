#pragma once
#include <iostream>

class Board {
    private:
        //6 rows, 7 columns
        char board[6][7];
        char getSlot(int, int);
        bool checkLine(int, int, int, int, char);
    public:
        Board();
        int getLowest(int);
        bool setInColumn(int, char);
        bool winCheck(int, int);
        void printBoard();
};