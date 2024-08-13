#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int low = nums[0], high = nums.size() - 1;

        for(int i = 0,j = 0; j < nums.size(); j++)
        {
            //moving zeros to the left
            if(nums[j] == 0)
            {
                swap(nums[j],nums[i]);
                i++;
            }
        }

        for(int i = high,j = high; j >= 0; j--)
        {
            //moving twos to right
            if(nums[j] == 2)
            {
                swap(nums[j],nums[i]);
                i--;
            }
        }
    }
};