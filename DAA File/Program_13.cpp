#include <iostream>
using namespace std;

void printSolution(int board[20][20], int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (board[i][j] == 1 ? "Q " : ". "); 
        }
        
        cout << endl;   
    }
    cout << endl;
}

bool isSafe(int board[20][20], int row, int col, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {    
            return false;
        }  
    }

    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) 
    {
        if (board[i][j] == 1)
            {
                return false;
            }
        i--;
        j--;
    }
    
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < n) 
    {
        if (board[i][j] == 1)
        {    
            return false;
        }
        i--;
        j++;  
    }
    return true;
}

bool solveNQueens (int board[20][20], int row, int n) 
{
    if (row == n) 
    {
        printSolution(board, n);
        return true;   
    }
    bool found = false;
    for (int col = 0; col < n; col++) 
    {
        if (isSafe(board, row, col, n)) 
        {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, n))
            {    
                found = true;
            }
            board [row][col] = 0; 
        }  
    }
    return found;
}

int main()
{   
    int n;
    int board[20][20] = {0};
    cout << "Enter the number of queens: ";
    cin >> n;
    if (n <= 0 || n > 20) 
    {
        cout << "Enter a number between 1 and 20."; 
    }

    else if (!solveNQueens(board, 0, n)) 
    { 
        cout << "No solution exists."; 
    }
    return 0;
}