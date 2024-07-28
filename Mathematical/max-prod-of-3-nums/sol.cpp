#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int maxProduct = INT_MIN,product = nums[0];

        for(int i = 1; i < nums.size() - 1; i++)
        {
            // int num = nums[i];
            // product *= num;
            maxProduct = max(maxProduct,product * nums[i] * nums[nums.size() - 1]);
            product = nums[i];
        }
        return maxProduct;
    }
};