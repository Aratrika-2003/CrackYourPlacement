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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string s = "";
        queue<TreeNode*> que;
        if(root == NULL)
            return s;
        que.push(root);

        while(!que.empty())
        {
            TreeNode* temp = que.front();
            que.pop();

            if(temp != NULL)
                s += to_string(temp->val) + ",";
            else
                s += "@,";

            if(temp != NULL)
            {
                que.push(temp->left);
                que.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(!data.size())
            return NULL;
        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s,str,',');

        TreeNode* node = new TreeNode(stoi(str));

        q.push(node);

        while(!q.empty())
        {
            TreeNode* root = q.front();
            q.pop();
            getline(s,str,',');

            if(str == "@")
                root->left = NULL;
            else
            {
                root->left = new TreeNode(stoi(str));
                q.push(root->left);
            }

            getline(s,str,',');

            if(str == "@")
                root->right = NULL;
            else
            {
                root->right = new TreeNode(stoi(str));
                q.push(root->right);
            }

        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));