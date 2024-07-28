#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> nextBoard(m, vector<int>(n, 0));
        
        // Define directions for neighbors
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        // Apply the rules to update the next state of the board
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                int liveNeighbors = 0;
                for (int k = 0; k < 8; ++k) 
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1) 
                    {
                        liveNeighbors++;
                    }
                }
                
                if (board[i][j] == 1) 
                {
                    if (liveNeighbors < 2 || liveNeighbors > 3) 
                    {
                        nextBoard[i][j] = 0;
                    } 
                    else 
                    {
                        nextBoard[i][j] = 1;
                    }
                } 
                else 
                {
                    if (liveNeighbors == 3) {
                        nextBoard[i][j] = 1;
                    }
                }
            }
        }
        
        // Copy the next state back to the original board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = nextBoard[i][j];
            }
        }
    }
};
