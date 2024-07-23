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
    int length(ListNode* head) 
    {
        int len = 0;
        while(head != NULL) 
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == NULL || head->next == NULL) 
		return head;
    
        int l = length(head);
        
        ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
        temp->next = head;
        
        ListNode *pred = temp,*curr,*succ;
        
        while(l >= k) 
        {
            curr = pred->next;
            succ = curr->next;
            for(int i=1;i<k;i++) 
            {
                curr->next = succ->next;
                succ->next = pred->next;
                pred->next = succ;
                succ = curr->next;
            }
            pred = curr;
            l -= k;
        }
        return temp->next;
    }
};