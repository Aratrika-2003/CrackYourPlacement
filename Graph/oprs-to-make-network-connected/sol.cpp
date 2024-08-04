#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& visited,int n)
    {
        visited[n] = 1;

        for(auto i : adj[n])
        {
            if(!visited[i])
                dfs(adj,visited,i);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> adj(n);
        int count = 0;
        for(auto connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        vector<int> visited(n);

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(adj,visited,i);
            }
        }
        if(connections.size() >= n - 1)
            return (count - 1);

        return -1;
    }
};