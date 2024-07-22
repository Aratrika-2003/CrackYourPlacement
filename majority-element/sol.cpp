#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //int count = nums.size() / 2;
        
        sort(nums.begin(),nums.end());
       
        return nums[nums.size()/2];
    }
};