#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& img,int r,int c,int clr,int nclr)
    {
        if(r < 0 || c < 0 || r == img.size() || c == img[0].size())
            return;
        if(img[r][c] != clr)
            return;
        
        img[r][c] = nclr;
        
        dfs(img,r,c - 1,clr,nclr);
        dfs(img,r,c + 1,clr,nclr);
        dfs(img,r - 1,c,clr,nclr);
        dfs(img,r + 1,c,clr,nclr);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if(image[sr][sc] == color)
            return image;
        
        dfs(image,sr,sc,image[sr][sc],color);
        
        return image;
    }
};