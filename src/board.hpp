#pragma once

class Board {
    private:
        //6 rows, 7 columns
        char board[6][7];
    public:
        Board();
        bool setInColumn(int, char);
        bool winCheck();
        void printBoard();
};