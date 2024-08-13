#include<bits/stdc++.h>
using namespace std;

class Solution 
{
  public:
    int longestCommonSubstr(string str1, string str2) 
    {
        // your code here
        int len = 0;
        
        vector<vector<int>> dp(str1.length() + 1,vector<int>(str2.length() + 1,0));
        
        for(int i = 1; i <= str1.length(); i++)
        {
            for(int j = 1; j <= str2.length(); j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    len = max(len,dp[i][j]);
                }
            }
        }
        return len;
    }
};