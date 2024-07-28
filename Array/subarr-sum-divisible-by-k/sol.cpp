#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int count = 0,sum = 0;
        int res[k];
        memset(res,0,sizeof(res));
        res[0]++;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            res[(sum % k + k) % k]++;
            count += res[(sum % k + k) % k] - 1;
        }
        return count;
    }
};