#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
    vector<WordDictionary*> children;
    bool end_of_word;
public:
    WordDictionary() 
    {
        this->end_of_word = false;
        this->children = vector<WordDictionary*>(26,NULL);
    }
    
    void addWord(string word) 
    {
        WordDictionary* str = this;

        for(char ch : word)
        {
            if(str->children[ch - 'a'] == NULL)
                str->children[ch - 'a'] = new WordDictionary();

            str = str->children[ch - 'a'];
        }
        str->end_of_word = true;
    }
    
    bool search(string word)
    {
        WordDictionary* str = this;

        for(int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if(ch == '.')
            {
                for(auto chs : str->children)
                    if(chs && chs->search(word.substr(i+1))) 
                        return true;
                return false;
            }
            if(str->children[ch - 'a'] == NULL) 
                return false;
            str = str->children[ch - 'a'];
        }
        return (str && str->end_of_word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */