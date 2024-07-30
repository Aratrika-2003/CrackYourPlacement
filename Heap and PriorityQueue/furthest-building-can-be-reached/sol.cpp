#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int,vector<int>,greater<int>> minq;
        int i = 0;
        
        for(i = 0; i < heights.size() - 1; i++)
        {
            // if(heights[i] < heights[i + 1])
            int diff = heights[i + 1] - heights[i];

            if(diff > 0)
            {
                minq.push(diff);

                if(minq.size() > ladders)
                {
                    bricks -= minq.top();
                    minq.pop();
                }
                if(bricks < 0)
                    break;
            }
        }
        return i;
    }
};