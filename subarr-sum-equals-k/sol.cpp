#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        //sort(nums.begin(),nums.end());
        unordered_map<int,int> res;
        int sum = 0,ans = 0;
        res[sum] = 1;
        for(auto n:nums)
        {
            sum += n;
            int subarr = sum - k;
            if(res.find(subarr) != res.end())
                ans += res[subarr];
            
            res[sum]++;
        }
        return ans;
    }
};