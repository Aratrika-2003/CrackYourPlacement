#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    int size;
    list<int> dll;
    map<int,pair<list<int>::iterator,int>> cache;

    void leastRecent(int key)
    {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
public:
    LRUCache(int capacity) 
    {
        this->size = capacity;
    }
    
    int get(int key) 
    {
        if(cache.find(key) == cache.end())
            return -1;
        leastRecent(key);
        
        return cache[key].second;
    }
    
    void put(int key, int value) 
    {
        if(cache.find(key) != cache.end())
        {
            cache[key].second = value;
            leastRecent(key);
        }
        else
        {
            dll.push_front(key);
            cache[key] = make_pair(dll.begin(),value);
            size--;
        }
        if(size < 0)
        {
            int delkey = dll.back();
            dll.pop_back();
            cache.erase(delkey);
            size++;
        }
    }
};