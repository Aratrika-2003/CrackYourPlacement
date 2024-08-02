#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) 
    {
        int prev = 1,curr = 1,res;
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        for(int i = 2; i <= n; i++)
        {
            res = prev + curr;
            prev = curr;
            curr = res;
        }
        
        return res;
    }
};

