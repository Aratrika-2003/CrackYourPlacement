#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        vector<vector<int>> dp(k + 1,vector<int>(prices.size(),0));

        if(prices.size() <= 1 || k == 0)
            return 0;
        
        if(k >= prices.size() / 2)
        {
            int max_profit = 0;
            for (int i = 1; i < prices.size(); i++) 
            {
                if (prices[i] > prices[i - 1])
                    max_profit += prices[i] - prices[i - 1];
            }
            return max_profit;
        }
        for (int i = 1; i <= k; i++) 
        {
            int max_diff = -prices[0];
            for (int j = 1; j < prices.size(); j++) 
            {
                dp[i][j] = max(dp[i][j - 1],prices[j] + max_diff);
                max_diff = max(max_diff, dp[i - 1][j] - prices[j]);
            }
        }

        return dp[k][prices.size() - 1];
    }
};