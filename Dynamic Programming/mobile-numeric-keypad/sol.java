class Solution {
    
    int[] dr = {-1, 0, +1, 0};
    int[] dc = {0, +1, 0, -1};
    long[][][] dp;
    
    long solve(int n, int i, int j){
        if(n == 0) 
            return 1;
        
        if(dp[n][i][j] != 0) 
            return dp[n][i][j];
        
        long res = solve(n-1, i, j);
        for(int k=0; k<4; k++)
        {
            int adjR = i + dr[k];
            int adjC = j + dc[k];
            
            if(adjR >= 0 && adjR <4 && adjC >= 0 && adjC < 3)
            {
                if(adjR == 3)
                {
                    if(adjC == 1)
                        res += solve(n-1, adjR, adjC);
                } 
                else 
                    res += solve(n-1, adjR, adjC);
            }
        }
        
        return dp[n][i][j] = res;
    }
    public long getCount(int n) 
    {
        // Your code goes here
        long res = 0;
        dp = new long[n][4][3];

        for(int i =0; i<4; i++)
        {
            for(int j=0; j< 3; j++)
            {
                if(i == 3 && j==0 || i==3 && j==2) 
                    continue;
                res += solve(n-1, i, j);
            }
        }
        
        return res;
    }
}