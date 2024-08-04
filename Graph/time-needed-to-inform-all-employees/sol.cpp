#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        queue<pair<int,int>> que;
        vector<pair<int,int>> adjlist[n];
        vector<int> dist(n,INT_MAX);

        for(int i = 0; i < manager.size(); i++)
        {
            if(manager[i] == -1)
                continue;
                
            adjlist[manager[i]].push_back({i, informTime[i]});
        }
        que.push({headID,informTime[headID]});
        dist[headID] = informTime[headID];

        while(!que.empty())
        {
            pair<int,int> employee = que.front();
            que.pop();

            for(auto adj : adjlist[employee.first])
            {
                if(dist[adj.first] > dist[employee.first] + informTime[adj.first])
                {
                    dist[adj.first] = dist[employee.first] + informTime[adj.first];
                    que.push({adj.first,dist[adj.first]});
                }
            }
        }
        int maxtime = 0;

        for(int i = 0; i < n; i++)
            maxtime = max(maxtime,dist[i]);
        if(maxtime == INT_MAX)
            return -1;

        return maxtime;
    }
};