#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int x[4] = {-1,1,0,0},y[4] = {0,0,-1,1};

    bool valid(int m,int n,int row,int col)
    {
        return (m < row && n < col && m >= 0 && n >= 0);
    }

    void make_island(int m,int n,int row,int col,vector<vector<int>>& grid)
    {
        if(m >= row||n >= col || m < 0 || n < 0 || grid[m][n] == 0 || grid[m][n] == 2)
            return;
        grid[m][n] = 2;

        for(int i = 0; i < 4; i++)
        {
            int nrow = m + x[i],ncol = n + y[i];

            make_island(nrow,ncol,row,col,grid);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) 
    {
        int count = 0;
        queue<pair<int,int>> que;
        bool flag = false;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j])
                {
                    make_island(i,j,grid.size(),grid[0].size(),grid);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                    que.push({i,j});
            }
        }
        while(!que.empty())
        {
            count++;
            int qsize = que.size();

            while(qsize--)
            {
                auto node = que.front();
                que.pop();

                for(int i = 0; i < 4; i++)
                {
                    int nrow = node.first + x[i],ncol = node.second + y[i];

                    if(valid(nrow,ncol,grid.size(),grid[0].size()))
                    {
                        if(grid[nrow][ncol] == 0)
                        {
                            grid[nrow][ncol] = 2;
                            que.push({nrow,ncol});
                        }
                        if(grid[nrow][ncol] == 1)
                        return count - 1;
                    }
                }
            }
        }
        return 0;
    }
};