#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),0));
        int t = 0;

        if(matrix.empty())
            return 0;

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(!i || !j || matrix[i][j] == '0')
                    dp[i][j] = matrix[i][j] - '0';
                else
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;

                t = max(dp[i][j],t);
            }
        }
        return (t * t);
    }
};