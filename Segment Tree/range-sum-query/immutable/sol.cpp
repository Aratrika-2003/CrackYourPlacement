#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) 
    {
        for(auto num : nums)
            (this->arr).push_back(num);
    }
    
    int sumRange(int left, int right) 
    {
        int sum = 0;

        for(int i = left; i <= right; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */