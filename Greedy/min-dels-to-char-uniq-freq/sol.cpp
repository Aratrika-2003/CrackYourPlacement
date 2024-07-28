#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) 
    {
        int count = 0;
        map<char,int> freq;
        set<int> f;
        for(char ch:s)
        {
            freq[ch]++;
        }
        for(auto c:freq)
        {
            int frequency = c.second;

            while (f.count(frequency) > 0) 
            {
                frequency--;
                count++;
            }
            if (frequency > 0)
                f.insert(frequency);
        }
        return count;
    }
};