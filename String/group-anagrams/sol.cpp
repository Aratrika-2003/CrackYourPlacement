#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>> anag;
        vector<vector<string>> res;
        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            anag[temp].push_back(strs[i]);
        }
        for(auto word : anag)
            res.push_back(word.second);

        return res;
    }
};