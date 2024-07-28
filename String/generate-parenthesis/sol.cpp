#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool valid_parenthesis(string s)
    // {
    //     int balance = 0;
    //     for(char ch : s)
    //     {
    //         if(ch == '(')
    //             balance++;
    //         else
    //             balance--;
            
    //         if(balance < 0)
    //             return false;
    //     }
    //     return balance == 0;
    // }
    void generate(string& s,int n,int open,int close,vector<string>& ans)
    {
        if (s.length() == 2*n) 
        { 
            ans.push_back(s); 
            return;
        }
        if (open < n) 
        {
            s.push_back('('); 
            generate(s, n, open + 1, close, ans); 
            s.pop_back(); 
        }
        if (close < open) 
        { 
            s.push_back(')'); 
            generate(s, n, open, close + 1, ans); 
            s.pop_back();
        }

        // if (s.length() == 2*n) 
        // {
        //     if (valid_parenthesis(s)) 
        //         ans.push_back(s);
        //     return; 
        // }
        // generate(s + "(", n, ans);
        // generate(s + ")", n, ans); 
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans; 
        string s;
        generate(s, n, 0, 0, ans);
        return ans; 
        // vector<string> ans; 
        // generate("", n, ans); 
        // return ans;
    }
};
