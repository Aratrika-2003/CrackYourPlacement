#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0,right = height.size() - 1,maxm = 0,width,high,area;

        while(left < right)
        {
            width = right - left;
            high = min(height[left],height[right]);

            area = width * high;

            maxm = max(maxm,area);

            if(height[left] < height[right])
                left++;
            else if(height[left] > height[right])
                right--;
            else
            {
                left++; right--;
            }
        }
        return maxm;
    }
};