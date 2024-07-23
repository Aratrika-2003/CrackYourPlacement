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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left == right or head == NULL or head->next == NULL)
            return head;
        
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* prev = temp;

        for(int i = 1; i < left; i++)
            prev = prev->next;
        
        ListNode* curr = prev->next;

        for(int i = left; i < right; i++)
        {
            ListNode* next_node = curr->next;
            curr->next = next_node->next;
            next_node->next = prev->next;
            prev->next = next_node;
        }
        
        ListNode* reversedList = temp->next;
        delete temp;
        
        return reversedList;
    }
};