#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;
        priority_queue<pair<int,int>> que;
        map<int,int> map;

        for(auto n : nums)
            map[n]++;
        
        for(auto m : map)
            que.push({m.second,m.first});

        while(k--)
        {
            res.push_back(que.top().second);
            que.pop();
        }
        return res;
    }
};