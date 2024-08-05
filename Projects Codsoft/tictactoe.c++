
// Tic Tac Toe Game for Two Players

#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
bool draw = false;
int row, column;

void display_board()
{
    system("cls");

    cout << "Welcome to Tic Tac Toe Game " << endl; // Show the welcome screen of the game
    cout << "\tPlayer1 [X] \n\tPlayer2 [O]" << endl
         << endl; // Describe the player symbols

    // Game pad of the game where the player can play the game
    cout << "\t\t\t     |     |     " << endl;
    cout << "\t\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t     |     |     " << endl;
    cout << "\t\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t     |     |     " << endl;
    cout << "\t\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "\t\t\t     |     |     " << endl;
}

    //For player turn input
void player_turn()
{
    int choice;
    if (turn == 'X')
        cout << "\n\t Player1 [X] turn : ";
    if (turn == 'O')
        cout << "\n\t Player2 [O] turn : ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0; column = 0;
        break;
    case 2:
        row = 0; column = 1;
        break;
    case 3:
        row = 0; column = 2;
        break;
    case 4:
        row = 1; column = 0;
        break;
    case 5:
        row = 1; column = 1;
        break;
    case 6:
        row = 1; column = 2;
        break;
    case 7:
        row = 2; column = 0;
        break;
    case 8:
        row = 2; column = 1;
        break;
    case 9:
        row = 2; column = 2;
        break;
    default:
        cout << "Invalid choice " << endl;
        player_turn();
        return;
    }
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'O' && board[row][column] != 'X')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Please Try again @ ";   //If the board is filled already by the another player
        player_turn();
    }
    display_board();
}
bool gameover()
{
    // Checking Winning Statement

    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return false;
    // If there is any box left
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    // If all box are filled and no one win so the game will be draw
    draw = true;
    return false;
}

int main()
{
    while (gameover())
    {
        display_board();
        player_turn();

        gameover();
    }
    if (turn == 'O' && draw == false)
    {
        cout << "Player1 [X] Wins !! Congratulation ^_^ \n";        //Showing the Player winning statement
    }
    else if (turn == 'X' && draw == false)
    {
        cout << "Player2 [O] Wins !! Congratulation ^_^ \n";
    }
    else
    {
        cout << "Game Draw *_* !! ";
    }
}