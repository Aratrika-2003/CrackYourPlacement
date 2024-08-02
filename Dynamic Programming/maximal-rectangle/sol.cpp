#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> s;
        int maxArea = 0;

        for (int i = 0; i <= heights.size(); ++i)
        {
            while (!s.empty() && (i == heights.size() || heights[i] < heights[s.top()])) 
            {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea,height * width);
            }
            s.push(i);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) 
            return 0;

        int rows = matrix.size(),cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                if (matrix[i][j] == '0') 
                    heights[j] = 0;
                else 
                    heights[j]++;
            }
            maxArea = max(maxArea,largestRectangleArea(heights));
        }

        return maxArea;
    }
};