#include<bits/stdc++.h>
using namespace std;

//Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    unordered_map<Node*,Node*> randmap;
public:
    Node* copyRandomList(Node* head) 
    {
        if(head == NULL)
            return NULL;
        if(randmap.count(head))
            return randmap[head];

        Node* temp = new Node(head->val);
        randmap[head] = temp;
        temp->next = copyRandomList(head->next);
        temp->random = copyRandomList(head->random);

        return temp;
    }
};