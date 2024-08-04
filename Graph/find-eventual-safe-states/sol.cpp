#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& visited,set<int>& safe_node)
    {
        if(visited[node] == 1)//visited before,so not safe
            return false;
        if(visited[node] == 2)
            return true;
        
        visited[node] = 1;

        for(int neighbour : graph[node])
        {
            if(!dfs(neighbour,graph,visited,safe_node))
                return false;
        }
        visited[node] = 2;

        safe_node.insert(node);

        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int> visited(graph.size(),0);
        set<int> safe_node;

        for (int i = 0; i < graph.size(); ++i) 
            dfs(i,graph,visited,safe_node);

        vector<int> result(safe_node.begin(),safe_node.end());
        sort(result.begin(),result.end());

        return result;
    }
};