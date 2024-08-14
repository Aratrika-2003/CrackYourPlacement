class Solution 
{
    public static long[] productExceptSelf(int nums[]) 
    {
        // code here
        long[] res = new long[nums.length];
        long preProduct = 1;
        
        for(int i = 0; i < nums.length; i++)
        {
            res[i] = preProduct;
            preProduct *= nums[i];
        }
        
        long suffProduct = 1;
        
        for (int i = nums.length - 1; i >= 0; i--) 
        {
            res[i] *= suffProduct;
            suffProduct *= nums[i];
        }
        return res;
    }
}