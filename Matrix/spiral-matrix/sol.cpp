#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;

        int r = matrix.size(),c = matrix[0].size(),count = 0,tot = r * c;
        int srow = 0,scol = 0,erow = r - 1,ecol = c - 1;

        while(count < tot)
        {
            for(int i = scol; count < tot && i <= ecol; i++)
            {
                res.push_back(matrix[srow][i]);
                count++;
            }
            srow++;
            
            for(int i = srow; i < tot && i <= erow; i++)
            {
                res.push_back(matrix[i][ecol]);
                count++;
            }
            ecol--;

            for(int i = ecol; count < tot && i >= scol; i--)
            {
                res.push_back(matrix[erow][i]);
                count++;
            }
            erow--;

            for(int i = erow; count < tot && i >= srow; i--)
            {
                res.push_back(matrix[i][scol]);
                count++;
            }
            scol++;
        }
        return res;
    }
};