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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a == NULL || b == NULL)
            return NULL;
        while(a != b)
        {
            a = a->next;
            b = b->next;
            
            if(a == b)
                return a;
            if(a == NULL)
                a = headB;
            if(b == NULL)
                b = headA;
        }
        return a;
    }
};