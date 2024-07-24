#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool substring(string s,int sublen,int k)
    {
        vector<int> freq(26);
        int max_freq = 0,start = 0;

        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'A']++;

            if(i + 1 - start > sublen)
            {
                freq[s[start] - 'A']--;
                start++;
            }
            max_freq = max(max_freq,freq[s[i] - 'A']);

            if(sublen - max_freq <= k)
                return true;
        }
        return false;
    }
    int characterReplacement(string s, int k) 
    {
        int low = 1,high = s.length() + 1;

        while(low + 1 < high)
        {
            int mid = low + (high - low) / 2;

            if(substring(s,mid,k))
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};