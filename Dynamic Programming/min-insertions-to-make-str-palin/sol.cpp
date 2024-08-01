#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int min_insert(string& s1,string& s2,int m,int n)
    {
        vector<vector<int>> dp(n + 1,vector<int>(n + 1));

        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <=n; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    int minInsertions(string s) 
    {
        string rev = s;
        reverse(rev.begin(),rev.end());

        return s.length() - min_insert(s,rev,s.length(),s.length());
    }
};