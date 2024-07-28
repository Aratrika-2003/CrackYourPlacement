#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // float evaluate(float a,float b,char opr)
    // {
    //     // if(opr == '+')
    //     //     return a + b;
    //     // if(opr == '-')
    //     //     return a - b;
    //     // if(opr == '*')
    //     //     return a * b;
    //     // if(opr == '/')
    //     //     return a / b;
    // }
    int prcd(char ch)
    {
        return(ch == '*' || ch == '/');
        //     return 3;
        // else if(ch == '+' || ch == '-')
        //     return 2;
        // else
        //     return 1;
    }
    string toPostfix(string &s)
    {
        stack<char> op;
        string post = "";
        for(auto c : s) 
            if(c == ' ') 
                continue;
            else if(isdigit(c)) 
                post += c;
            else 
            {
                post += '|';

                while(op.size() && prcd(c) <= prcd(op.top()))
                    post += op.top(), op.pop();
                op.push(c);
            }
        
        post += '|';

        while(op.size()) 
            post += op.top(), op.pop();
        return post;
    }
    int calculate(string s)
    {
        s = toPostfix(s);
        stack<int> num;
        for(int i = 0; i < s.length(); i++) 
        {
            if(isdigit(s[i])) 
            {
                int cur = 0;
                while(i < s.length() && isdigit(s[i]))
                    cur = cur * 10 + (s[i++] - '0');
                num.push(cur);
            }
            else 
            {
                int num1 = num.top();
                num.pop();
                int num2 = num.top();
                num.pop();
                if(s[i] == '*')      
                    num.push(num2 * num1);
                else if(s[i] == '/')
                    num.push(num2 / num1);
                else if(s[i] == '+') 
                    num.push(num2 + num1);
                else if(s[i] == '-') 
                    num.push(num2 - num1);
            }
        }
        
        return num.top();
    }
};