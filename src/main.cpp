#include "board.cpp"

int main()
{
    std::string player1;
    std::string player2;

    std::cout << "Player 1, please enter your name: ";
    std::cin >> player1;
    std::cout << "Player 2, please enter your name: ";
    std::cin >> player2;

    Board board;
    board.printBoard();
    std::string* currentPlayer = &player2;
    char playerNum;
    int placement;
    do
    {
        //switch player
        currentPlayer = currentPlayer == &player1 ? &player2 : &player1;
        playerNum = currentPlayer == &player1 ? '1' : '2';

        do 
        {
            std::cout << *currentPlayer << ", where do you want to place your mark? [1-7] ";
            std::cin >> placement;
            placement--;
        } while (placement < 1 || placement > 7 || !board.setInColumn(placement, playerNum));
        board.printBoard();
    } while (!board.winCheck(board.getLowest(placement) + 1, placement));
    std::cout << "Congrats, " << *currentPlayer << ", you won!\n";

    return 0;
}