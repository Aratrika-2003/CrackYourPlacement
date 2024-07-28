import java.util.*;

class Solution
{
    public long findMinDiff (ArrayList<Integer> a, int n, int m)
    {
        // your code here
        if(m == 0 || n == 0)
            return 0;
        
        if(n < m)
            return -1;
            
        long minDiff = Long.MAX_VALUE;
        
        Collections.sort(a);
        
        for(int i = 0; i + m - 1 < n; i++)
        {
            long diff = (long) a.get(i + m - 1) - a.get(i);
            if (diff < minDiff) 
                minDiff = diff;
        }
        return minDiff;
    }
}