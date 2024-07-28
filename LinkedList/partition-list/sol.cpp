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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *lesser = new ListNode(0),*greater = new ListNode(0);
        ListNode *lptr = lesser,*gptr = greater;

        while(head != NULL)
        {
            if(head->val < x)
            {
                lptr->next = head;
                lptr = lptr->next;
            }
            else
            {
                gptr->next = head;
                gptr = gptr->next;
            }
            head = head->next;
        }
        lptr->next = greater->next;
        gptr->next = NULL;
    
        ListNode* partition = lesser->next;
        delete lesser,greater;

        return partition;
    }
};