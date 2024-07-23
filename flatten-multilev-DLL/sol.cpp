#include<bits/stdc++.h>
using namespace std;

//Definition for a Node.
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) 
    {
        Node *ptr = head, *tmp_next, *runner;
        
        while (ptr != NULL) 
        {
            if (ptr->child) 
            {
                tmp_next = ptr->next;
                ptr->next = ptr->child;
                ptr->next->prev = ptr;
                ptr->child = NULL;
                
                runner = ptr->next;
                while (runner->next != NULL)
                    runner = runner->next;
                runner->next = tmp_next;
                if (runner->next) 
                    runner->next->prev = runner;
            }
            
            ptr = ptr->next;
        }
        
        return head;
    }
};