#pragma once

class Board {
    private:
        //6 rows, 7 columns
        char board[6][7];
    public:
        Board();
        bool setInColumn();
        bool winCheck();
        void printBoard();
};