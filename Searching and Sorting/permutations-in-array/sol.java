import java.util.*;

class Solution {
    private void reverse(int[] array) 
    {
        int left = 0, right = array.length - 1;
        
        while (left < right) 
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            
            left++;
            right--;
        }
    }
    public boolean isPossible(int k, int[] arr1, int[] arr2) 
    {
        // Your code goes here.
        Arrays.sort(arr1);
        
        Arrays.sort(arr2);
        reverse(arr2);
        
        for (int i = 0; i < arr1.length; i++)
            if (arr1[i] + arr2[i] < k)
                return false;

        return true;
    }
}