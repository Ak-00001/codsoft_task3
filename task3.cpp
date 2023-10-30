#include <iostream>
#include <vector>

using namespace std;
void displayBoard(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
}
bool checkWin(const vector<vector<char>> &board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true; 
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true; 
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true; 
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true; 
    }
    return false;
}
bool checkTie(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false; 
            }
        }
    }
    return true; 
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    int row, col;
    bool gameOver = false;

    while (!gameOver)
    {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter row and column (e.g., 1 2): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
        else if (checkTie(board))
        {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        }

   
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
