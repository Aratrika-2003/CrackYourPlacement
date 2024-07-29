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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* r = root;
        while(true)
        {
            if(r->val==p->val)
            {    
                return p; 
                break;
            }
            
            if(r->val==q->val)
            {
                return q; 
                break;
            }
            
            else if(((r->val)>(p->val) && r->val<q->val) || ((r->val)<(p->val) && (r->val)>(q->val)))
            {
                return r;
                break;
            }
            
            else if(r->val>p->val && r->val>q->val)
            {
                r=r->left;
            }
            else
            {
                r=r->right;
            }
        }
    }
};