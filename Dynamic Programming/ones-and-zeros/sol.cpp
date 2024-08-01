#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<int>> dp(m + 1,vector<int>(n + 1));
        for(auto str : strs)
        {
            int zero = count(str.begin(),str.end(),'0');
            int one = str.size();
            for(int i = m; i >= zero; i--)
            {
                for(int j = n; j >= (one - zero); j--)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zero][j - (one - zero)]);
                }
            }
        }
        return dp[m][n];
    }
};