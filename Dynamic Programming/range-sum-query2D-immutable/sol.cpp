#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        mat = vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i = 1; i <= matrix.size(); i++)
        {
            for(int j = 1; j <= matrix[0].size(); j++)
            {
                mat[i][j] = matrix[i-1][j-1] + mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return mat[row2+1][col2+1] - mat[row1][col2+1] - mat[row2+1][col1] + mat[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */