#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
        bool static comp(Job a, Job b){
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int max_dead=0;

        for(int i=0; i<n; i++)
            max_dead=max(max_dead, arr[i].dead);

        sort(arr, arr+n, comp);

        vector<bool> deads(max_dead+1, 0);

        int tot_profit=0, tot_job=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=arr[i].dead; j>0; j--)
            {
                if(!deads[j])
                {
                    deads[j]=1;
                    tot_profit+=arr[i].profit;
                    tot_job++;

                    break;
                }
            }
            if(tot_job==max_dead) 
                break;
        }
        
        return {tot_job, tot_profit};
    } 
};