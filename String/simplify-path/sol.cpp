#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string> s;
        string res;

        for(int i = 0; i < path.size(); i++)
        {
            string temp;

            if(path[i] == '/')
                continue;
            
            while(i < path.size() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }
            if(temp == ".")
                continue;
            
            else if(temp == "..")
            {
                if(!s.empty())
                    s.pop();
            }
            else
                s.push(temp);
        }
        while(!s.empty())
        {
            res = "/" + s.top() + res;
            s.pop();
        }
        
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};