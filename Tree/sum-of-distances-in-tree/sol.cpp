#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> v;
    vector<int> res,counter;

    void dfs1(int i,int j)
    {
        for(auto node : v[i])
        {
            if(node == j)
                continue;
            
            dfs1(node,i);
            counter[i] += counter[node];
            res[i] += res[node] + counter[node];
        }
        counter[i]++;
    }
    void dfs2(int i,int n,int p)
    {
        for(auto u : v[i])
        {
            if(u == p)
                continue;
            
            res[u] = res[i] - counter[u] + n - counter[u];
            dfs2(u,n,i);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        v.resize(n);
        for(int i=0; i<n-1; i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];

            v[a].push_back(b);
            v[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        
        dfs1(0, -1);
        dfs2(0, n, -1);
        return res;
    }
};