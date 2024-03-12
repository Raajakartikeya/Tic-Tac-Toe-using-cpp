#include <iostream>
using namespace std;
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player1 = 'X', player2 = 'O';
void printBoard()
{
    int i, j;
    cout << "\n";
    for (i = 0; i < 3; i++)
    {
        cout << "\t";
        for (j = 0; j < 3; j++)
        {
            cout << board[i][j];
            cout << "\t|\t";
        }
        if (i != 2)
        {
            cout << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";
            cout << endl;
        }
    }
}
int checkWinner()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == player1 && board[1][i] == player1 && board[2][i] == player1)
        {
            return 1;
        }
        if (board[0][i] == player2 && board[1][i] == player2 && board[2][i] == player2)
        {
            return 2;
        }
        if (board[i][0] == player1 && board[i][1] == player1 && board[i][2] == player1)
        {
            return 1;
        }
        if (board[i][0] == player2 && board[i][1] == player2 && board[i][2] == player2)
        {
            return 2;
        }
    }
    if (board[0][0] == player1 && board[1][1] == player1 && board[2][2] == player1)
    {
        return 1;
    }
    if (board[0][2] == player1 && board[1][1] == player1 && board[2][0] == player1)
    {
        return 1;
    }
    if (board[0][0] == player2 && board[1][1] == player2 && board[2][2] == player2)
    {
        return 2;
    }
    if (board[0][2] == player2 && board[1][1] == player2 && board[2][0] == player2)
    {
        return 2;
    }
    return 0;
}
int play(int turn)
{
    int row, col, win;
    char player;
    if (turn % 2 == 0)
    {
        cout << "\n\nPlayer " << player1 << " turn\n";
        player = player1;
    }
    else
    {
        cout << "\n\nPlayer " << player2 << " turn\n";
        player = player2;
    }

    cout << "\nEnter Position Row (0 - 2) and Column (0 - 2):";
    cin >> row >> col;

    if (board[row][col] == ' ')
    {
        board[row][col] = player;
    }
    else
    {
        cout << "Already That Position is Filled!!! Again Enter Position!!!";
        return play(turn);
        }
    printBoard();
    win = checkWinner();
    return win;
}
int main()
{
    int k;
    printBoard();
    int i;
    for (i = 0; i < 9; i++)
    {
        k = play(i);
        if (k != 0)
        {
            break;
        }
    }
    if (k == 1)
    {
        cout << "\n\nPlayer X Wins the game";
    }
    else if (k == 2)
    {
        cout << "\n\nPlayer O Wins the game";
    }
    else
    {
        cout << "\n\nMatch Draw";
    }
}