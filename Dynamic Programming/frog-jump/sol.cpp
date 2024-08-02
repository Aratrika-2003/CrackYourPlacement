#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
        set<int> steps;
        map<int,set<int>> jump;

        for(auto stone:stones)
            steps.insert(stone);
        
        jump[0] = {1};

        for(int i = 0; i < stones.size(); i++)
        {
            for(auto jump_size:jump[stones[i]])
            {
                int next_step = stones[i] + jump_size;

                if(next_step == stones.back())
                    return true;
                
                if(steps.count(next_step) > 0)
                {
                    jump[next_step].insert(jump_size - 1);
                    jump[next_step].insert(jump_size);
                    jump[next_step].insert(jump_size + 1);
                }
            }
        }
        return false;
    }
};