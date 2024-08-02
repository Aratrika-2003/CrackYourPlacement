#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) 
    {
        //int count = 0;
        vector<int> arr = {0};
        
        for(int i = 1; i < n + 1; i++)
        {
            int r = i & 1;
            arr.push_back(arr[i >> 1] + r);
        }
        return arr;
    }
};