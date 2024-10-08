#include<bits/stdc++.h>
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger 
{
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer     // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator 
{
    vector<int> arr;
    int index = 0;
public:
    void flatten(vector<NestedInteger>& nestedList)
    {
        for(auto list : nestedList)
        {
            if(list.isInteger())
                arr.push_back(list.getInteger());
            else
                flatten(list.getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        flatten(nestedList);
    }
    
    int next() 
    {
        return arr[index++];
    }
    
    bool hasNext() 
    {
        return index < arr.size();
    }
};