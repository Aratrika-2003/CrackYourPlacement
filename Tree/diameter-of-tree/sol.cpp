#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxm = 0;
    // int height(TreeNode* root)
    // {
    //     if(root == NULL)
    //         return 0;

    //     int lh = height(root->left),rh = height(root->right);

    //     return (lh > rh) ? (lh + 1) : (rh + 1);
    // }
    int diameter(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int ldiam = diameter(root->left);
        int rdiam = diameter(root->right);

        maxm = max(maxm,ldiam + rdiam);

        return (1 + max(ldiam,rdiam));
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        diameter(root);
        
        return maxm;
    }
};