#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(int n,int k,int st,vector<int>& curr,vector<vector<int>>& combn)
    {
        if(k == 0)
        {
            combn.push_back(curr);
            return;
        }
        for(int i = st; i <= n - k + 1; i++)
        {
            curr.push_back(i);
            find(n,k - 1,i + 1,curr,combn);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> combn;
        vector<int> curr;
        find(n,k,1,curr,combn);

        return combn;
    }
};