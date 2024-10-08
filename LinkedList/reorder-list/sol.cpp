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
    void reorderList(ListNode* head) 
    {
        if(head == NULL)
		    return;
        ListNode *prev = head;
        
        while (prev->next != NULL && prev->next->next != NULL) 
        {
            ListNode* curr = prev;
    
            while(curr->next->next != NULL)
                curr = curr->next;

            curr->next->next = prev->next;
            prev->next = curr->next;
            curr->next = NULL;
            prev = prev->next->next;
        }
        
    }
};
