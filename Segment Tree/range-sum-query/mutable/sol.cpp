#include<bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> nums;
    vector<int> tree;
    int n;

    void buildTree(int node, int start, int end) 
    {
        if (start == end) 
        {
            // Leaf node will have a single element
            tree[node] = nums[start];
        } 
        else 
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // Recursively build the segment tree
            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);

            // Internal node will have the sum of both of its children
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }
    
    // Helper function to update the segment tree
    void updateTree(int node, int start, int end, int idx, int val) 
    {
        if (start == end) 
        {
            // Leaf node
            tree[node] = val;
            nums[idx] = val;
        } 
        else 
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (start <= idx && idx <= mid) 
            {
                // If idx is in the left child, recurse on the left child
                updateTree(leftChild, start, mid, idx, val);
            } 
            else 
            {
                // If idx is in the right child, recurse on the right child
                updateTree(rightChild, mid + 1, end, idx, val);
            }
            // Internal node will have the sum of both of its children
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }
    
    // Helper function to get the sum in a range
    int queryTree(int node, int start, int end, int L, int R) 
    {
        if (R < start || end < L) 
        {
            // range represented by a node is completely outside the given range
            return 0;
        }
        if (L <= start && end <= R) 
        {
            // range represented by a node is completely inside the given range
            return tree[node];
        }
        // range represented by a node is partially inside and partially outside the given range
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = queryTree(leftChild, start, mid, L, R);
        int rightSum = queryTree(rightChild, mid + 1, end, L, R);
        
        return leftSum + rightSum;
    }
public:
    NumArray(vector<int>& nums) 
    {
        this->nums = nums;
        n = nums.size();
        tree.resize(4 * n);
        buildTree(0, 0, n - 1);
    }
    
    void update(int index, int val) 
    {
        updateTree(0,0,n - 1,index,val);
    }
    
    int sumRange(int left, int right) 
    {
        return queryTree(0,0,n - 1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
