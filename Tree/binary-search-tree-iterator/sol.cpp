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

class BSTIterator {
    stack<TreeNode*> st;
public:
    void leftBST(TreeNode* root)
    {
        if(root == NULL)
            return;
        while(root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) 
    {
        leftBST(root);
    }
    
    int next() 
    {
        TreeNode* root = st.top();
        st.pop();
        leftBST(root->right);
        return root->val;
    }
    
    bool hasNext() 
    {
        return (!st.empty());
    }
};


//Your BSTIterator object will be instantiated and called as such:
// BSTIterator* obj = new BSTIterator(root);
// int param_1 = obj->next();
// bool param_2 = obj->hasNext();
