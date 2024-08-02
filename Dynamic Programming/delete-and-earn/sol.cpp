#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        int n = 10001;
        vector<int> earn_points(n);
        vector<int> dp(n);
        for(auto i : nums)
        {
            earn_points[i] += i;
        }
        dp[0] = 0;
        dp[1] = earn_points[1];

        for(int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + earn_points[i],dp[i - 1]);
        }

        return dp[n - 1];
    }
};