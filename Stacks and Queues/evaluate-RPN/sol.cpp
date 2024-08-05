#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        string str = tokens.back();
        tokens.pop_back();

        if(str != "+" && str != "-" && str != "*" && str != "/")
            return stoi(str);
        
        long int b = evalRPN(tokens);
        long int a = evalRPN(tokens);
        
        if(str == "+")
            return (a + b);
        else if(str == "-")
            return (a - b);
        else if(str == "*")
            return (a * b);
        else
            return (a / b);
    }
};
