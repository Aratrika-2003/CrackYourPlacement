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
    ListNode* reverse(ListNode* head)
    {
        ListNode* tail = NULL;

        while(head != NULL)
        {
            ListNode* curr = head->next;
            head->next = tail;
            tail = head;
            head = curr;  
        }
        return tail;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* head = NULL;
        int carry = 0;

        while(l1 || l2)
        {
            int x1 = l1 ? l1->val : 0;
            int x2 = l2 ? l2->val : 0;
            int sum = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            ListNode* curr = new ListNode(sum);
            curr->next = head;
            head = curr;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if(carry)
        {
            ListNode* curr = new ListNode(carry);
            curr->next = head;
            head = curr;
        }
        return head;
    }
};