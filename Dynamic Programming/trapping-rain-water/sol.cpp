#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int rain_water = 0;
        vector<int> left(height.size()),right(height.size());

        if(height.size() <= 2)
            return 0;
        
        left[0] = height[0];

        for(int i = 1; i < height.size(); i++)
            left[i] = max(left[i - 1],height[i]);

        right[height.size() - 1] = height[height.size() - 1];

        for (int i = height.size() - 2; i >= 0; i--) 
            right[i] = max(right[i + 1],height[i]);

        for (int i = 1; i < height.size() - 1; i++) 
        {
            int minHeight = min(left[i - 1],right[i + 1]);

            if (minHeight > height[i]) 
                rain_water += minHeight - height[i];
        }
        return rain_water;
    }
};