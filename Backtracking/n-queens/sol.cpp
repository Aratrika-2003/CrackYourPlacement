#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row,int col,int n,const vector<string>& board) 
    {
        //Check for same column
        for (int r = 0; r < row; r++) 
        {
            if (board[r][col] == 'Q')
                return false;
        }
        //check for left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) 
        {
            if (board[i][j] == 'Q')
                return false;
        }
        //Check for right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve_nqueens(int row,int n,vector<string>& board,vector<vector<string>>& solns) 
    {
        if (row == n) 
        {
            solns.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) 
        {
            if (isSafe(row, col, n, board)) 
            {
                board[row][col] = 'Q';
                solve_nqueens(row + 1, n, board, solns);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        solve_nqueens(0, n, board, solutions);

        return solutions;
    }
};