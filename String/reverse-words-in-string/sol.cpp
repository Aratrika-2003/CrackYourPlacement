#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) 
    {
        stack<string> str;
        string res = "",rev = "";

        for(char ch : s)
        {
            if(ch == ' ')
            {
                if(!res.empty())
                {
                    str.push(res);
                    res = "";
                }
            }
            else
                res += ch;
        }

        if(!res.empty())
            str.push(res);

        while(!str.empty())
        {
            rev += str.top() + " ";
            str.pop();
        }
        if(!rev.empty())
            rev.pop_back();
        
        return rev;
    }
};