class Solution {
    public int maxScore(int[] cardPoints, int k) 
    {
        int n = cardPoints.length,totalPoints = 0;
        
        for (int i = 0; i < n; i++) 
            totalPoints += cardPoints[i];
        
        if (k == n) 
            return totalPoints;
        
        int windowSize = n - k;
        int minSubarrSum;
        int currSubarrSum = 0;
        
        for (int i = 0; i < windowSize; i++) 
            currSubarrSum += cardPoints[i];
        
        minSubarrSum = currSubarrSum;
        
        for (int i = windowSize; i < n; i++) 
        {
            currSubarrSum += cardPoints[i] - cardPoints[i - windowSize];
            minSubarrSum = Math.min(minSubarrSum, currSubarrSum);
        }
        
        return totalPoints - minSubarrSum;
    }
}