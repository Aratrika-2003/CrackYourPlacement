#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.empty())
            return "";
            
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); ++i) 
        {
            string curr = strs[i];
            int j = 0;
            
            while (j < prefix.length() && j < curr.length() && prefix[j] == curr[j])
                ++j;
            
            prefix = prefix.substr(0, j);
        
            if (prefix.empty())
                return "";
        }
        
        return prefix;
    }
};