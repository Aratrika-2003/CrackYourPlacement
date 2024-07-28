#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* left,ListNode* right)
    {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        while(left != NULL && right != NULL)
        {
            if(left->val < right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        curr->next = left ? left : right;
        
        return head->next;
    }
    ListNode* mgsort(vector<ListNode*>& list,int start,int end)
    {
        if(start == end)
            return list[start];
        if(start + 1 == end)
            return merge(list[start], list[end]);
        int mid = start + (end - start) / 2;

        ListNode *left = mgsort(list,start,mid), *right = mgsort(list,mid + 1,end);

        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.empty() || lists.size() == 0)
            return NULL;
        
        return mgsort(lists,0,lists.size() - 1);
    }
};