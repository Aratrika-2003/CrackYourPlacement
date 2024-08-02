#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int maxproduct = nums[0],minproduct = nums[0],res = maxproduct;

        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] < 0) 
                swap(maxproduct,minproduct);
            

            maxproduct = max(nums[i],maxproduct * nums[i]);
            minproduct = min(nums[i], minproduct * nums[i]);

            res = max(res,maxproduct);
        }
        return res;
    }
};