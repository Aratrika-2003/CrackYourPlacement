#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) 
    {
        if(s.length() == 0 || s[0] == '0')
            return 0;
        
        vector<int> dp(s.length() + 1,0);
        dp[0] = 1,dp[1] = 1;

        for(int i = 2; i <= s.length(); i++)
        {
            int one_digit = stoi(s.substr(i - 1,1)),two_digit = stoi(s.substr(i - 2,2));

            if(one_digit >= 1 && one_digit <= 9)
                dp[i] += dp[i - 1];
            if(two_digit >= 10 && two_digit <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[s.length()];
    }
};