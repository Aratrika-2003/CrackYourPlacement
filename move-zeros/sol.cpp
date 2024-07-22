#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i,key = 0;
        for(i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
                nums[key++] = nums[i];
        }
        for(i = key; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};