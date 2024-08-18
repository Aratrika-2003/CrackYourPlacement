#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int traversal(TreeNode* root,int& sum)
    {
        if(root == NULL)
            return 0;

        int lh = max(traversal(root->left,sum),0);
        int rh = max(traversal(root->right,sum),0);
        
        sum = max(sum,lh + rh + root->val);

        return max(lh,rh) + root->val;
    }

    int maxPathSum(TreeNode* root) 
    {
        int maxsum = INT_MIN;
        traversal(root,maxsum);
        return maxsum;
    }
};