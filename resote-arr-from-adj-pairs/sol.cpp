#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        map<int,vector<int>> unique;
        int st = 0;
        vector<int> arr;

        for(auto adj:adjacentPairs)
        {
            unique[adj[0]].push_back(adj[1]);
            unique[adj[1]].push_back(adj[0]);
        } 
        for(auto [key,val]:unique)
        {
            if(val.size() == 1)
            {
                st = key;
                break;
            }
        }
        arr.push_back(st);

        set<int> visited;
        visited.insert(st);

        while(arr.size() < unique.size())
        {
            int end = arr.back();
            vector<int> next = unique[end];

            for (int n : next) 
            {
                if (visited.count(n) == 0) 
                {
                    arr.push_back(n);
                    visited.insert(n);
                    break;
                }
            }
        }
        return arr;
    }
};