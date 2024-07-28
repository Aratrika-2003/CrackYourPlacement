#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int> window(128,0);

        for (auto ch : t) 
            window[ch]++;

        int counter = t.length(),start = 0,end = 0,minLen = INT_MAX,head = 0;

        while (end < s.length()) 
        {
            if (window[s[end]] > 0) 
                counter--;

            window[s[end]]--;
            end++;

            while (counter == 0) 
            { //valid
                if (end - start < minLen) 
                {
                    minLen = end - start;
                    head = start;
                }

                window[s[start]]++;
                if (window[s[start]] > 0) 
                    counter++;

                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};