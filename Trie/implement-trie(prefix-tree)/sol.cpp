#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
        TrieNode* children[26];
        bool end_of_word;

        TrieNode()
        {
            memset(children,0,sizeof(children));
            end_of_word = false;
        }
};
class Trie {
public:
    TrieNode* root;
    Trie() 
    {
        root = new TrieNode();
    }
    
    void insert(string word) 
    {
        TrieNode* temp = root;

        for(auto ch : word)
        {
            int index = ch - 'a';

            if (temp->children[index] == NULL) 
                temp->children[index] = new TrieNode();
            temp = temp->children[index];
        }
        temp->end_of_word = true;
    }
    
    bool search(string word) 
    {
        TrieNode* temp = root;
        for (char ch : word) 
        {
            int index = ch - 'a';
            if (temp->children[index] == NULL)
                return false;
            temp = temp->children[index];
        }
        if (temp->end_of_word == true) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* temp = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (temp->children[index] == NULL) 
                return false;
            temp = temp->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */