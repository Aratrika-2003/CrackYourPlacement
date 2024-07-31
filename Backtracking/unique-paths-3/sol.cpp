#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //-1 - unreachable, 0 - empty, 1 - start, 2 - end
    int dfs(int r,int c, vector<vector<int>>& grid,int sum)
    {
        if(r<0 || grid.size()-1<r || c<0 || grid[0].size()-1<c || grid[r][c]==-1 || grid[r][c]==1)
            return 0;
        if(grid[r][c] == 2)//end square;whether all obstacles reached or not
        {
            if(sum == 1)
                return 1;
            else
                return 0;
        }
        grid[r][c] = 1;//visited
        int r1 = dfs(r - 1,c,grid,sum - 1),r2 = dfs(r + 1,c,grid,sum - 1);
        int c1 = dfs(r,c - 1,grid,sum-1),c2 = dfs(r,c + 1,grid,sum - 1);
        grid[r][c] = 0;//set back to 0 again

        return (r1+r2+c1+c2);
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        if(grid.size() < 1 || grid[0].size() < 1)
            return 0;
        int row,col,sum = grid.size() * grid[0].size();
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    row = i; col = j;
                    grid[i][j] = 0;
                }
                else if(grid[i][j] == -1)
                    sum--;
            }
        }
        return dfs(row,col,grid,sum);
    }
};