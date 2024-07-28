#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int m = needle.length(),n = haystack.length();
        //maximum n - m combinations
        for(int start = 0; start <= n - m; start++)
        {
            for(int i = 0; i < m; i++)
            {
                if(needle[i] != haystack[start + i])
                    break;
                if(i == m - 1)
                    return start;
            }
        }
        return -1;
    }
};