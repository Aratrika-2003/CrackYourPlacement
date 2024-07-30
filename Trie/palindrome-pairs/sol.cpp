#include<bits/stdc++.h>
using namespace std;

struct Trie
{
    map<char, Trie*> child;
    int index;
    vector<int> palinSuffixes;

    Trie() : index(-1) {}
};

bool isPalindrome(const string& str, int l, int r)
{
    while (l < r)
    {
        if (str[l] != str[r])
            return false;
        l++, r--;
    }
    return true;
}

class TriePairs
{
private:
    Trie* root;

public:
    TriePairs()
    {
        root = new Trie();
    }

    void insert(const string& word, int index)
    {
        Trie* node = root;
        for (int i = word.size() - 1; i >= 0; --i)
        {
            if (isPalindrome(word, 0, i))
                node->palinSuffixes.push_back(index);

            if (node->child.find(word[i]) == node->child.end())
                node->child[word[i]] = new Trie();

            node = node->child[word[i]];
        }
        node->index = index;
        node->palinSuffixes.push_back(index);
    }

    void search(const string& word, int index, vector<vector<int>>& result)
    {
        Trie* node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->index != -1 && node->index != index && isPalindrome(word, i, word.size() - 1))
                result.push_back({ index, node->index });

            if (node->child.find(word[i]) == node->child.end())
                return;

            node = node->child[word[i]];
        }

        for (int j : node->palinSuffixes)
        {
            if (index != j)
                result.push_back({ index, j });
        }
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        TriePairs trie;
        vector<vector<int>> result;

        for (int i = 0; i < words.size(); ++i)
            trie.insert(words[i], i);

        for (int i = 0; i < words.size(); ++i)
            trie.search(words[i], i, result);

        return result;
    }
};