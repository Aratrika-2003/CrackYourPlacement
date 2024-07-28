#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void transpose(vector<vector<int>>& mat)
    {
        int n = mat.size(),temp;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                temp = mat[j][i];
                mat[j][i] = mat[i][j];
                mat[i][j] = temp;
            }
        }
    }
    void mirror(vector<vector<int>>& mat)
    {
        int n = mat.size(),temp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n / 2; j++)
            {
                temp = mat[i][j];
                mat[i][j] = mat[i][n - j - 1];
                mat[i][n - j - 1] = temp;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) 
    {
        transpose(matrix);
        mirror(matrix);
    }
};