#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s,int i,int j)
    {
        while(i < j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void backtracking(vector<vector<string>>& res,string& s,int st,vector<string>& curr)
    {
        if(st >= s.length())
            res.push_back(curr);
        
        for(int end = st; end < s.length(); end++)
        {
            if(isPalindrome(s,st,end))
            {
                curr.push_back(s.substr(st,end - st + 1));
                backtracking(res,s,end + 1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> curr;

        backtracking(res,s,0,curr);

        return res;
    }
};