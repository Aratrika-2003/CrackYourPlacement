#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) 
    {
        stack<char> st;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ']')
                st.push(s[i]);
            else
            {
                string str = "";
                while(st.top() != '[')
                {
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();//'['

                string count = "";

                while(!st.empty() && isdigit(st.top()))
                {
                    count = st.top() + count;
                    st.pop();
                }
                int res = stoi(count);

                while(res--)
                {
                    for(int j = 0; j < str.length() ; j++)
                        st.push(str[j]);
                }
            }
        }
        s = "";

        while(!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};