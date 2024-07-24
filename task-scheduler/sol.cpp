#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        map<char, int> taskCounts;
    
        // Count the frequency of each task
        for (char task : tasks) 
        {
            taskCounts[task]++;
        }
        
        // Sort tasks by frequency
        vector<int> counts;
        for (auto& pair : taskCounts) 
        {

            counts.push_back(pair.second);
        }
        sort(counts.begin(), counts.end(), greater<int>());
        
        // Get the maximum frequency
        int maxFrequency = counts[0];
        
        // Count the number of tasks that have the same maximum frequency
        int numMaxFrequencyTasks = 0;
        for (int count : counts) 
        {
            if (count == maxFrequency) 
                numMaxFrequencyTasks++;
            else 
                break;
        }
        
        // Calculate the minimum intervals required
        int minIntervals = (maxFrequency - 1) * (n + 1) + numMaxFrequencyTasks;
        
        // Return the maximum of minimum intervals and the number of tasks
        return max((int)tasks.size(), minIntervals);
    }
};