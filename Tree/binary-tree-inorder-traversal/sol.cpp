#include<bits/stdc++.h>
using namespace std;

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
    void inorder(TreeNode* root,vector<int>& tree)
    {
        if(root == NULL)
            return;
        if(root != NULL)
        {
            inorder(root->left,tree);
            tree.push_back(root->val);
            inorder(root->right,tree);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> tree;

        inorder(root,tree);

        return tree;
    }
};
