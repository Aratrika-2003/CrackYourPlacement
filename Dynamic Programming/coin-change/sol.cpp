#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int sum = 0;
        map<int,int> count;
        count[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            count[i] = INT_MAX;
            for(auto coin : coins)
            {
                if (i - coin >= 0 && count[i - coin] != INT_MAX)
                    count[i] = min(count[i],count[i - coin] + 1);
            }
        }
        return count[amount] == INT_MAX ? -1 : count[amount];
    }
};