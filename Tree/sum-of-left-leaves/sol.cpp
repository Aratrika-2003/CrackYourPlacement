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
    void findsum(TreeNode* root,int& sum)
    {
        if(root == NULL)
            return;
        //int sum = 0;
        if(root->left && !root->left->left && !root->left->right)
            sum += root->left->val;

        if(root->left)
            findsum(root->left,sum);
        
        if(root->right)
            findsum(root->right,sum);
    }

    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum = 0;
        findsum(root,sum);

        return sum;
    }
};